//  Copyright (c) 2007-2010 Hartmut Kaiser
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying 
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>

#include <hpx/hpx.hpp>
#include <hpx/runtime/actions/plain_action.hpp>

#include <boost/program_options.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/export.hpp>

using namespace hpx;
namespace po = boost::program_options;

///////////////////////////////////////////////////////////////////////////////
// Helpers

typedef hpx::naming::gid_type gid_type;

inline gid_type find_here(void)
{
    return hpx::applier::get_applier().get_runtime_support_raw_gid();
}

struct px
{
public:
  px() 
  {
    applier::get_applier().get_remote_prefixes(localities_);
    num_localities_ = localities_.size();
  }

  gid_type locality(int locality_id)
  {
    return localities_[locality_id];
  }

  int num_localities(void)
  {
    return num_localities_;
  }

private:
  std::vector<gid_type> localities_;
  int num_localities_;
};

///////////////////////////////////////////////////////////////////////////////
// int fib(int n)
// {
//     if (n < 2) 
//         return n;
// 
//     int n1 = fib(n - 1);
//     int n2 = fib(n - 2);
//     return n1 + n2;
// }
// 
// int main()
// {
//     util::high_resolution_timer t;
//     int result = fib(41);
//     double elapsed = t.elapsed();
// 
//     std::cout << "elapsed: " << elapsed << ", result: " << result << std::endl;
// }

///////////////////////////////////////////////////////////////////////////////
int fib(int n, int orig_arg, int delay_coeff);
int fib_rhs(int n, int delay_coeff);

typedef 
    actions::plain_result_action3<int, int, int, int, fib> 
fibonacci2_action;

typedef 
    actions::plain_result_action2<int, int, int, fib_rhs> 
fibonacci2_rhs_action;


typedef lcos::eager_future<fibonacci2_action> fibonacci_future;
typedef lcos::eager_future<fibonacci2_rhs_action> fibonacci_rhs_future;

HPX_REGISTER_ACTION(fibonacci2_action);
HPX_REGISTER_ACTION(fibonacci2_rhs_action);

///////////////////////////////////////////////////////////////////////////////
int count_invocations = 0;    // global invocation counter
inline void count_invocation(void) { ++count_invocations; }

inline void do_busy_work(double delay_coeff)
{
    if (delay_coeff) {
        util::high_resolution_timer t;
        double start_time = t.elapsed();
        double current = 0;
        do {
            current = t.elapsed();
        } while (current - start_time < delay_coeff * 1e-6);
    }
}


int fib (int n, int orig_arg, int delay_coeff)
{
    // count number of invocations
    count_invocation();

    // do some busy waiting, if requested
    do_busy_work(delay_coeff);

    // here is the actual fibonacci calculation
    if (n < 2) 
        return n;

    px world;

    gid_type here = find_here();

    std::vector<int> distribution;

    int index;
    for (index = 0; index < world.num_localities(); index++)
        if (world.locality(index) == here)
            break;

    int num_to_spawn = orig_arg / world.num_localities();
    int extra = orig_arg % world.num_localities();
    for (int j = 0; j < world.num_localities(); j++)
    {
        for (int i = 0; i < num_to_spawn; i++)
            distribution.push_back(j);
        if (extra > 0) {
                distribution.push_back(j);
                extra--;
            }
    }

    fibonacci_future n1(world.locality(distribution[index+1]),  n - 1, orig_arg, delay_coeff);
    fibonacci_rhs_future n2(here,  n - 2, delay_coeff);

    return n1.get() + n2.get();
}

int fib_rhs (int n, int delay_coeff)
{
    // count number of invocations
    count_invocation();

    // do some busy waiting, if requested
    do_busy_work(delay_coeff);

    // here is the actual fibonacci calculation
    if (n < 2) 
        return n;

    gid_type here = find_here();

    fibonacci_rhs_future n1(here,  n - 1, delay_coeff);
    fibonacci_rhs_future n2(here,  n - 2, delay_coeff);

    return n1.get() + n2.get();
}

///////////////////////////////////////////////////////////////////////////////
int hpx_main(po::variables_map &vm)
{
    int argument = 10;
    int delay_coeff = 0;
    int result = 0;
    double elapsed = 0.0;


    // Process application-specific command-line options
    if (vm.count("value"))
        argument = vm["value"].as<int>();
    if (vm.count("busywait"))
        delay_coeff = vm["busywait"].as<int>();

    // try to get arguments from application configuration
    runtime& rt = get_runtime();
    argument = boost::lexical_cast<int>(
        rt.get_config().get_entry("application.fibonacci2.argument", argument));

    px world;

    gid_type here = world.locality(0);

    {
        util::high_resolution_timer t;
        fibonacci_future n(here, argument, argument, delay_coeff);
        result = n.get();
        elapsed = t.elapsed();
    }

    if (vm.count("csv"))
    {
      // write results as csv
      std::cout << argument << "," 
        << elapsed << "," << result << "," << count_invocations 
        << "," << elapsed/count_invocations << std::endl;
    }
    else {
      // write results the old fashioned way
      std::cout << "elapsed: " << elapsed << ", result: " << result << std::endl;
      std::cout << "Number of invocations of fib(): " << count_invocations 
                                                         << std::endl;
    }

    // initiate shutdown of the runtime systems on all localities
    components::stubs::runtime_support::shutdown_all();

    return 0;
}

///////////////////////////////////////////////////////////////////////////////
bool parse_commandline(int argc, char *argv[], po::variables_map& vm)
{

    try {
        po::options_description desc_cmdline ("Usage: fibonacci2 [options]");
        desc_cmdline.add_options()
            ("help,h", "print out program usage (this message)")
            ("run_agas_server,r", "run AGAS server as part of this runtime instance")
            ("worker,w", "run this instance in worker (non-console) mode")
            ("config", po::value<std::string>(), 
                "load the specified file as an application configuration file")
            ("agas,a", po::value<std::string>(), 
                "the IP address the AGAS server is running on (default taken "
                "from hpx.ini), expected format: 192.168.1.1:7912")
            ("hpx,x", po::value<std::string>(), 
                "the IP address the HPX parcelport is listening on (default "
                "is localhost:7910), expected format: 192.168.1.1:7913")
            ("localities,l", po::value<int>(), 
                "the number of localities to wait for at application startup"
                "(default is 1)")
            ("threads,t", po::value<int>(), 
                "the number of operating system threads to spawn for this"
                "HPX locality")
            ("queueing,q", po::value<std::string>(),
                "the queue scheduling policy to use, options are 'global' "
                " and 'local' (default is 'global')")
            ("value,v", po::value<int>(), 
                "the number to be used as the argument to fib (default is 10)")
            ("csv,s", "generate statistics of the run in comma separated format")
            ("busywait,b", po::value<int>(),
                "add this amount of busy wait workload to each of the iterations"
                " [in steps of 1�s], i.e. -b1000 == 1ms")
        ;

        po::store(po::command_line_parser(argc, argv)
            .options(desc_cmdline).run(), vm);
        po::notify(vm);

        // print help screen
        if (vm.count("help")) {
            std::cout << desc_cmdline;
            return false;
        }
    }
    catch (std::exception const& e) {
        std::cerr << "fibonacci2: exception caught: " << e.what() << std::endl;
        return false;
    }
    return true;
}

///////////////////////////////////////////////////////////////////////////////
inline void 
split_ip_address(std::string const& v, std::string& addr, boost::uint16_t& port)
{
    std::string::size_type p = v.find_first_of(":");
    try {
        if (p != std::string::npos) {
            addr = v.substr(0, p);
            port = boost::lexical_cast<boost::uint16_t>(v.substr(p+1));
        }
        else {
            addr = v;
        }
    }
    catch (boost::bad_lexical_cast const& /*e*/) {
        std::cerr << "fibonacci2: illegal port number given: " << v.substr(p+1) << std::endl;
        std::cerr << "           using default value instead: " << port << std::endl;
    }
}

///////////////////////////////////////////////////////////////////////////////
// helper class for AGAS server initialization
class agas_server_helper
{
public:
    agas_server_helper(std::string host, boost::uint16_t port)
      : agas_pool_(), agas_(agas_pool_, host, port)
    {
        agas_.run(false);
    }
    ~agas_server_helper()
    {
        agas_.stop();
    }

private:
    hpx::util::io_service_pool agas_pool_; 
    hpx::naming::resolver_server agas_;
};

///////////////////////////////////////////////////////////////////////////////
// this is the runtime type we use in this application
typedef hpx::threads::policies::global_queue_scheduler global_queue_policy;
typedef hpx::threads::policies::local_queue_scheduler local_queue_policy;

///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{

    try {
        // analyze the command line
        po::variables_map vm;
        if (!parse_commandline(argc, argv, vm))
            return -1;

        // Check command line arguments.
        std::string hpx_host("localhost"), agas_host;
        boost::uint16_t hpx_port = HPX_PORT, agas_port = 0;
        int num_threads = 1;
        std::string queueing = "global";
        int num_localities = 1;
        hpx::runtime::mode mode = hpx::runtime::console;    // default is console mode

        // extract IP address/port arguments
        if (vm.count("agas")) 
            split_ip_address(vm["agas"].as<std::string>(), agas_host, agas_port);

        if (vm.count("hpx")) 
            split_ip_address(vm["hpx"].as<std::string>(), hpx_host, hpx_port);

        if (vm.count("localities"))
            num_localities = vm["localities"].as<int>();

        if (vm.count("threads"))
            num_threads = vm["threads"].as<int>();

        if (vm.count("queueing"))
            queueing = vm["queueing"].as<std::string>();

        if (vm.count("worker")) {
            mode = hpx::runtime::worker;
            if (vm.count("config")) {
                std::cerr << "fibonacci2: --config option ignored, used for console "
                             "instance only\n";
            }
        }

        // initialize and run the AGAS service, if appropriate
        std::auto_ptr<agas_server_helper> agas_server;
        if (vm.count("run_agas_server"))  // run the AGAS server instance here
            agas_server.reset(new agas_server_helper(agas_host, agas_port));

        // initialize and start the HPX runtime
        if (queueing == "global")
        {
            typedef hpx::runtime_impl<global_queue_policy> runtime_type;

            // Build and configure this runtime instance
            runtime_type rt(hpx_host, hpx_port, agas_host, agas_port, mode);
            if (mode != hpx::runtime::worker && vm.count("config"))
            {
                std::string config(vm["config"].as<std::string>());
                rt.get_config().load_application_configuration(config.c_str());
            }
               
            // Run this runtime instance
            if (mode != hpx::runtime::worker) {
                rt.run(boost::bind(hpx_main, vm), num_threads, num_localities);
            }
            else
            {
                rt.run(num_threads, num_localities);
            }
        }
        else if (queueing == "local")
        {
            typedef hpx::runtime_impl<local_queue_policy> runtime_type;
            local_queue_policy::init_parameter_type init(num_threads, 1000);

            // Build and configure this runtime instance
            runtime_type rt(hpx_host, hpx_port, agas_host, agas_port, mode, init);
            if (mode != hpx::runtime::worker && vm.count("config"))
            {
                std::string config(vm["config"].as<std::string>());
                rt.get_config().load_application_configuration(config.c_str());
            }
               
            // Run this runtime instance
            if (mode != hpx::runtime::worker) {
                rt.run(boost::bind(hpx_main, vm), num_threads, num_localities);
            }
            else
            {
                rt.run(num_threads, num_localities);
            }
        }
        else
            BOOST_ASSERT(false);
    }
    catch (std::exception& e) {
        std::cerr << "fibonacci2: std::exception caught: " << e.what() << "\n";
        return -1;
    }
    catch (...) {
        std::cerr << "fibonacci2: unexpected exception caught\n";
        return -2;
    }
    return 0;
}

