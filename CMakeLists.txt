if (CMAKE_VERSION VERSION_LESS "3.1")
  if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
  endif ()
else ()
  set (CMAKE_CXX_STANDARD 11)
endif ()
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
cmake_minimum_required(VERSION 2.8.12)
project(automata)
# Set source directory
set(SOURCE_DIR "src/")
# Tell CMake that headers are also in SOURCE_DIR
include_directories(${SOURCE_DIR})
set(SOURCES "${SOURCE_DIR}/Automata.cpp" "${SOURCE_DIR}/Conway.cpp")
include_directories("${SOURCE_DIR}/include") 

# Generate Python module
add_subdirectory(lib/pybind11)
pybind11_add_module(automata ${SOURCES} "${SOURCE_DIR}/bindings.cpp")
