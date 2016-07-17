//  Copyright (c) 2014 Grant Mercer
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <hpx/hpx_init.hpp>
#include <hpx/hpx.hpp>
#include <hpx/include/parallel_swap_ranges.hpp>
#include <hpx/util/lightweight_test.hpp>

#include <boost/range/functions.hpp>

#include <numeric>
#include <string>
#include <vector>

#include "test_utils.hpp"

///////////////////////////////////////////////////////////////////////////////
template <typename ExPolicy, typename IteratorTag>
void test_swap_ranges(ExPolicy policy, IteratorTag)
{
    static_assert(
        hpx::parallel::is_execution_policy<ExPolicy>::value,
        "hpx::parallel::is_execution_policy<ExPolicy>::value");

    typedef std::vector<std::size_t>::iterator base_iterator;
    typedef test::test_iterator<base_iterator, IteratorTag> iterator;

    std::vector<std::size_t> c(10007);
    std::vector<std::size_t> d(c.size());
    std::iota(boost::begin(c), boost::end(c), std::rand());
    std::fill(boost::begin(d), boost::end(d), std::rand());

    hpx::parallel::swap_ranges(policy,
        iterator(boost::begin(c)), iterator(boost::end(c)), boost::begin(d));

    //equal begins at one, therefore counter is started at 1
    std::size_t count = 1;
    HPX_TEST(std::equal(boost::begin(c) + 1, boost::end(c), boost::begin(c),
        [&count](std::size_t v1, std::size_t v2) -> bool {
            HPX_TEST_EQ(v1, v2);
            ++count;
            return v1 == v2;
        }));
    HPX_TEST_EQ(count, c.size());

    count = 1;
    HPX_TEST(std::equal(boost::begin(d) + 1, boost::end(d), boost::begin(d),
        [&count](std::size_t v1, std::size_t v2) -> bool {
            HPX_TEST_NEQ(v1, v2);
            ++count;
            return !(v1 == v2);
        }));
    HPX_TEST_EQ(count, d.size());
}

template <typename ExPolicy, typename IteratorTag>
void test_swap_ranges_async(ExPolicy p, IteratorTag)
{
    typedef std::vector<std::size_t>::iterator base_iterator;
    typedef test::test_iterator<base_iterator, IteratorTag> iterator;

    std::vector<std::size_t> c(10007);
    std::vector<std::size_t> d(c.size());
    std::iota(boost::begin(c), boost::end(c), std::rand());
    std::fill(boost::begin(d), boost::end(d), std::rand());

    hpx::future<base_iterator> f =
        hpx::parallel::swap_ranges(p,
            iterator(boost::begin(c)), iterator(boost::end(c)),
            boost::begin(d));

    f.wait();

    std::size_t count = 1;
    HPX_TEST(std::equal(boost::begin(c) + 1, boost::end(c), boost::begin(c),
        [&count](std::size_t v1, std::size_t v2) -> bool {
            HPX_TEST_EQ(v1, v2);
            ++count;
            return v1 == v2;
        }));

    count = 1;
    HPX_TEST(std::equal(boost::begin(d) + 1, boost::end(d), boost::begin(d),
        [&count](std::size_t v1, std::size_t v2) -> bool {
            HPX_TEST_NEQ(v1, v2);
            ++count;
            return !(v1 == v2);
        }));
    HPX_TEST_EQ(count, d.size());
}

template <typename IteratorTag>
void test_swap_ranges()
{
    using namespace hpx::parallel;
    test_swap_ranges(seq, IteratorTag());
    test_swap_ranges(par, IteratorTag());
    test_swap_ranges(par_vec, IteratorTag());

    test_swap_ranges_async(seq(task), IteratorTag());
    test_swap_ranges_async(par(task), IteratorTag());

#if defined(HPX_HAVE_GENERIC_EXECUTION_POLICY)
    test_swap_ranges(execution_policy(seq), IteratorTag());
    test_swap_ranges(execution_policy(par), IteratorTag());
    test_swap_ranges(execution_policy(par_vec), IteratorTag());

    test_swap_ranges(execution_policy(seq(task)), IteratorTag());
    test_swap_ranges(execution_policy(par(task)), IteratorTag());
#endif
}

void swap_ranges_test()
{
    test_swap_ranges<std::random_access_iterator_tag>();
    test_swap_ranges<std::forward_iterator_tag>();
}

///////////////////////////////////////////////////////////////////////////////
template <typename ExPolicy, typename IteratorTag>
void test_swap_ranges_exception(ExPolicy policy, IteratorTag)
{
    static_assert(
        hpx::parallel::is_execution_policy<ExPolicy>::value,
        "hpx::parallel::is_execution_policy<ExPolicy>::value");

    typedef std::vector<std::size_t>::iterator base_iterator;
    typedef test::decorated_iterator<base_iterator, IteratorTag>
        decorated_iterator;

    std::vector<std::size_t> c(10007);
    std::vector<std::size_t> d(c.size());
    std::iota(boost::begin(c), boost::end(c), std::rand());
    std::fill(boost::begin(d), boost::end(d), std::rand());

    bool caught_exception = false;
    try {
        hpx::parallel::swap_ranges(policy,
            decorated_iterator(
                boost::begin(c),
                [](){ throw std::runtime_error("test"); }),
            decorated_iterator(boost::end(c)),
            boost::begin(d));
        HPX_TEST(false);
    }
    catch (hpx::exception_list const& e) {
        caught_exception = true;
        test::test_num_exceptions<ExPolicy, IteratorTag>::call(policy, e);
    }
    catch (...) {
        HPX_TEST(false);
    }

    HPX_TEST(caught_exception);
}

template <typename ExPolicy, typename IteratorTag>
void test_swap_ranges_exception_async(ExPolicy p, IteratorTag)
{
    typedef std::vector<std::size_t>::iterator base_iterator;
    typedef test::decorated_iterator<base_iterator, IteratorTag>
        decorated_iterator;

    std::vector<std::size_t> c(10007);
    std::vector<std::size_t> d(c.size());
    std::iota(boost::begin(c), boost::end(c), std::rand());
    std::fill(boost::begin(d), boost::end(d), std::rand());

    bool caught_exception = false;
    bool returned_from_algorithm = false;
    try {
        hpx::future<base_iterator> f =
            hpx::parallel::swap_ranges(p,
                decorated_iterator(
                    boost::begin(c),
                    [](){ throw std::runtime_error("test"); }),
                decorated_iterator(boost::end(c)),
                boost::begin(d));
        returned_from_algorithm = true;
        f.get();

        HPX_TEST(false);
    }
    catch (hpx::exception_list const& e) {
        caught_exception = true;
        test::test_num_exceptions<ExPolicy, IteratorTag>::call(p, e);
    }
    catch (...) {
        HPX_TEST(false);
    }

    HPX_TEST(caught_exception);
    HPX_TEST(returned_from_algorithm);
}

template <typename IteratorTag>
void test_swap_ranges_exception()
{
    using namespace hpx::parallel;

    // If the execution policy object is of type vector_execution_policy,
    // std::terminate shall be called. therefore we do not test exceptions
    // with a vector execution policy
    test_swap_ranges_exception(seq, IteratorTag());
    test_swap_ranges_exception(par, IteratorTag());

    test_swap_ranges_exception_async(seq(task), IteratorTag());
    test_swap_ranges_exception_async(par(task), IteratorTag());

#if defined(HPX_HAVE_GENERIC_EXECUTION_POLICY)
    test_swap_ranges_exception(execution_policy(seq), IteratorTag());
    test_swap_ranges_exception(execution_policy(par), IteratorTag());

    test_swap_ranges_exception(execution_policy(seq(task)), IteratorTag());
    test_swap_ranges_exception(execution_policy(par(task)), IteratorTag());
#endif
}

void swap_ranges_exception_test()
{
    test_swap_ranges_exception<std::random_access_iterator_tag>();
    test_swap_ranges_exception<std::forward_iterator_tag>();
}

//////////////////////////////////////////////////////////////////////////////
template <typename ExPolicy, typename IteratorTag>
void test_swap_ranges_bad_alloc(ExPolicy policy, IteratorTag)
{
    static_assert(
        hpx::parallel::is_execution_policy<ExPolicy>::value,
        "hpx::parallel::is_execution_policy<ExPolicy>::value");

    typedef std::vector<std::size_t>::iterator base_iterator;
    typedef test::decorated_iterator<base_iterator, IteratorTag>
        decorated_iterator;

    std::vector<std::size_t> c(100007);
    std::vector<std::size_t> d(c.size());
    std::iota(boost::begin(c), boost::end(c), std::rand());
    std::fill(boost::begin(d), boost::end(d), std::rand());

    bool caught_bad_alloc = false;
    try {
        hpx::parallel::swap_ranges(policy,
            decorated_iterator(
                boost::begin(c),
                [](){ throw std::bad_alloc(); }),
            decorated_iterator(boost::end(c)),
            boost::begin(d));
        HPX_TEST(false);
    }
    catch (std::bad_alloc const&) {
        caught_bad_alloc = true;
    }
    catch (...) {
        HPX_TEST(false);
    }

    HPX_TEST(caught_bad_alloc);
}

template <typename ExPolicy, typename IteratorTag>
void test_swap_ranges_bad_alloc_async(ExPolicy p, IteratorTag)
{
    typedef std::vector<std::size_t>::iterator base_iterator;
    typedef test::decorated_iterator<base_iterator, IteratorTag>
        decorated_iterator;

    std::vector<std::size_t> c(10007);
    std::vector<std::size_t> d(c.size());
    std::iota(boost::begin(c), boost::end(c), std::rand());
    std::fill(boost::begin(d), boost::end(d), std::rand());

    bool caught_bad_alloc = false;
    bool returned_from_algorithm = false;
    try {
        hpx::future<base_iterator> f =
            hpx::parallel::swap_ranges(p,
                decorated_iterator(
                    boost::begin(c),
                    [](){ throw std::bad_alloc(); }),
                decorated_iterator(boost::end(c)),
                boost::begin(d));
        returned_from_algorithm = true;
        f.get();

        HPX_TEST(false);
    }
    catch(std::bad_alloc const&) {
        caught_bad_alloc = true;
    }
    catch(...) {
        HPX_TEST(false);
    }

    HPX_TEST(caught_bad_alloc);
    HPX_TEST(returned_from_algorithm);
}

template <typename IteratorTag>
void test_swap_ranges_bad_alloc()
{
    using namespace hpx::parallel;

    // If the execution policy object is of type vector_execution_policy,
    // std::terminate shall be called. therefore we do not test exceptions
    // with a vector execution policy
    test_swap_ranges_bad_alloc(seq, IteratorTag());
    test_swap_ranges_bad_alloc(par, IteratorTag());

    test_swap_ranges_bad_alloc_async(seq(task), IteratorTag());
    test_swap_ranges_bad_alloc_async(par(task), IteratorTag());

#if defined(HPX_HAVE_GENERIC_EXECUTION_POLICY)
    test_swap_ranges_bad_alloc(execution_policy(seq), IteratorTag());
    test_swap_ranges_bad_alloc(execution_policy(par), IteratorTag());

    test_swap_ranges_bad_alloc(execution_policy(seq(task)), IteratorTag());
    test_swap_ranges_bad_alloc(execution_policy(par(task)), IteratorTag());
#endif
}

void swap_ranges_bad_alloc_test()
{
    test_swap_ranges_bad_alloc<std::random_access_iterator_tag>();
    test_swap_ranges_bad_alloc<std::forward_iterator_tag>();
}
int hpx_main(boost::program_options::variables_map& vm)
{
    unsigned int seed = (unsigned int)std::time(nullptr);
    if (vm.count("seed"))
        seed = vm["seed"].as<unsigned int>();

    std::cout << "using seed: " << seed << std::endl;
    std::srand(seed);

    swap_ranges_test();
    swap_ranges_exception_test();
    swap_ranges_bad_alloc_test();
    return hpx::finalize();
}

int main(int argc, char* argv[])
{
    // add command line option which controls the random number generator seed
    using namespace boost::program_options;
    options_description desc_commandline(
        "Usage: " HPX_APPLICATION_STRING " [options]");

    desc_commandline.add_options()
        ("seed,s", value<unsigned int>(),
        "the random number generator seed to use for this run")
        ;

    // By default this test should run on all available cores
    std::vector<std::string> cfg;
    cfg.push_back("hpx.os_threads=" +
        std::to_string(hpx::threads::hardware_concurrency()));

    // Initialize and run HPX
    HPX_TEST_EQ_MSG(hpx::init(desc_commandline, argc, argv, cfg), 0,
        "HPX main exited with non-zero status");

    return hpx::util::report_errors();
}