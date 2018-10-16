cmake_minimum_required(VERSION 3.12)

project(
  uniquePtrExample
  VERSION
    0.1 DESCRIPTION
    "A project that shows off some specific behaviour of the std::unique_ptr"
  LANGUAGES CXX)

set(UPE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(UPE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(uniquePtrExample
               # Cpp code
               ${UPE_SOURCE_DIR}/main.cpp)

# Handle include paths
target_include_directories(
  uniquePtrExample
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:include>
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_compile_features(uniquePtrExample
                        PUBLIC
                        cxx_std_17 # Require C++17 for some features
                        )

# Optimise to level 2 if using GNU compilers
target_compile_options(uniquePtrExample PRIVATE $<$<CXX_COMPILER_ID:GNU>:-O2>)

set_target_properties(uniquePtrExample
                      PROPERTIES CMAKE_CXX_STANDARD_REQUIRED
                                 ON # Use std-c++ instead of gnu++
                                 CMAKE_CXX_EXTENSIONS
                                 OFF)
