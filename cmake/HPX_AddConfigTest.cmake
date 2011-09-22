# Copyright (c) 2011 Bryce Lelbach
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying 
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

set(HPX_ADDCONFIGTEST_LOADED TRUE)

include(HPX_Include)

hpx_include(Message
            Compile
            GetIncludeDirectory
            ParseArguments)

macro(add_hpx_config_test name variable)
  hpx_parse_arguments(${name} "SOURCE;FLAGS;DEFINITIONS;LANGUAGE;DEFAULT;ARGS;ROOT"
                              "FILE" ${ARGN})

  # FIXME: Sadly, CMake doesn't support non-boolean options with the option
  # command yet.
  #option(${variable}
  #  "Enable (ON), auto-detect (DETECT) or disable (OFF) ${name} (Default: ${${name}_DEFAULT}"
  #  ${${name}_DEFAULT})

  if("${variable}" STREQUAL "ON")
    set(${variable} ON CACHE STRING "${name} state.")
    foreach(definition ${${name}_DEFINITIONS})
      add_definitions(-D${definition})
    endforeach()
  elseif("${variable}" STREQUAL "OFF")
    set(${variable} OFF CACHE STRING "${name} state.")
  else()
    file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/config_tests)
  
    set(test_source "")
  
    if(${name}_FILE)
      if(${name}_ROOT)
        set(test_source "${${name}_ROOT}/share/hpx/${${name}_SOURCE}")
      else()
        set(test_source "${hpx_SOURCE_DIR}/${${name}_SOURCE}")
      endif()
    else()
      set(test_source
          "${CMAKE_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/config_tests/src.cpp")
      file(WRITE "${CMAKE_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/config_tests/src.cpp"
           "${${name}_SOURCE}\n")
    endif()
 
    hpx_debug("config_test.${name}" "Using ${test_source} as source file.")
    hpx_print_list("DEBUG" "config_test.${name}" "Flags for config test" ${name}_FLAGS) 

    hpx_compile(${name} SOURCE ${test_source} LANGUAGE ${${name}_LANGUAGE}
      OUTPUT ${CMAKE_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/config_tests/${name} 
      FLAGS ${${name}_FLAGS})
  
    if("${${name}_RESULT}" STREQUAL "0")
      set(test_result 0)
    
      execute_process(
        COMMAND "${CMAKE_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/config_tests/${name}"
                ${${name}_ARGS}
        RESULT_VARIABLE test_result OUTPUT_QUIET ERROR_QUIET) 
  
      if("${test_result}" STREQUAL "0")
        set(${variable} ON CACHE STRING "${name} state.")
        hpx_info("config_test.${name}" "Test passed.")
        foreach(definition ${${name}_DEFINITIONS})
          add_definitions(-D${definition})
        endforeach()
      else()
        set(${variable} OFF CACHE STRING "${name} state.")
        hpx_warn("config_test.${name}" "Test failed, returned ${test_result}.") 
      endif()
    else()
      set(${variable} OFF CACHE STRING "${name} state.")
      hpx_warn("config_test.${name}" "Test failed to compile.") 
    endif()
  endif()
endmacro()

###############################################################################
macro(hpx_check_for_gnu_128bit_integers variable)
  hpx_get_include_directory(include_dir)

  add_hpx_config_test("gnu_int128" ${variable} LANGUAGE CXX 
    SOURCE cmake/tests/gnu_128bit_integers.cpp
    FLAGS -I${BOOST_INCLUDE_DIR} ${include_dir} FILE ${ARGN})
endmacro()

macro(hpx_check_for_gnu_aligned_16 variable)
  hpx_get_include_directory(include_dir)

  add_hpx_config_test("gnu_aligned_16" ${variable} LANGUAGE CXX 
    SOURCE cmake/tests/gnu_aligned_16.cpp
    FLAGS -I${BOOST_INCLUDE_DIR} ${include_dir} FILE ${ARGN})
endmacro()

###############################################################################
macro(hpx_check_for_pthread_affinity_np variable)
  hpx_get_include_directory(include_dir)

  add_hpx_config_test("pthread_affinity_np" ${variable} LANGUAGE CXX 
    SOURCE cmake/tests/pthread_affinity_np.cpp
    FLAGS -pthread -I${BOOST_INCLUDE_DIR} ${include_dir} FILE ${ARGN})
endmacro()

###############################################################################
macro(hpx_cpuid target variable)
  hpx_get_include_directory(include_dir)
 
  add_hpx_config_test("${target}" ${variable} LANGUAGE CXX 
    SOURCE cmake/tests/cpuid.cpp
    FLAGS -I${BOOST_INCLUDE_DIR} ${include_dir}
    FILE ARGS "${target}" ${ARGN})
endmacro()

###############################################################################
macro(hpx_check_for_cxx11_rvalue_references variable)
  hpx_get_include_directory(include_dir)
 
  add_hpx_config_test("cxx11_rvalue_references" ${variable} LANGUAGE CXX 
    SOURCE cmake/tests/cxx11_rvalue_references.cpp
    FLAGS -I${BOOST_INCLUDE_DIR} ${include_dir} "-std=c++0x" FILE ${ARGN})
endmacro()

###############################################################################
macro(hpx_check_for_cxx11_variadic_templates variable)
  hpx_get_include_directory(include_dir)
 
  add_hpx_config_test("cxx11_variadic_templates" ${variable} LANGUAGE CXX 
    SOURCE cmake/tests/cxx11_variadic_templates.cpp
    FLAGS -I${BOOST_INCLUDE_DIR} ${include_dir} "-std=c++0x" FILE ${ARGN})
endmacro()

###############################################################################
macro(hpx_check_for_cxx11_lambdas variable)
  hpx_get_include_directory(include_dir)
 
  add_hpx_config_test("cxx11_lambdas" ${variable} LANGUAGE CXX 
    SOURCE cmake/tests/cxx11_lambdas.cpp
    FLAGS -I${BOOST_INCLUDE_DIR} ${include_dir} "-std=c++0x" FILE ${ARGN})
endmacro()

###############################################################################
macro(hpx_check_for_cxx11_unique_ptr variable)
  hpx_get_include_directory(include_dir)
 
  add_hpx_config_test("cxx11_unique_ptr" ${variable} LANGUAGE CXX 
    SOURCE cmake/tests/cxx11_unique_ptr.cpp
    FLAGS -I${BOOST_INCLUDE_DIR} ${include_dir} "-std=c++0x" FILE ${ARGN})
endmacro()

