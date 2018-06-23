// cache_before_init.cpp

// Boost Logging library
//
// Author: John Torjo, www.torjo.com
//
// Copyright (C) 2007 John Torjo (see www.torjo.com for email)
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org for updates, documentation, and revision history.
// See http://www.torjo.com/log2/ for more details

#include <hpx/config.hpp>

#include <hpx/util/logging/format/optimize.hpp>
#include <hpx/util/logging/detail/cache_before_init.hpp>

namespace hpx { namespace util { namespace logging { namespace detail {

template struct cache_before_init<optimize::cache_string_one_str>;

}}}}
