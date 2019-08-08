# https://cmake.org/cmake/help/latest/command/cmake_parse_arguments.html
include(CMakeParseArguments)

# https://cmake.org/cmake/help/latest/module/GNUInstallDirs.html
include(GNUInstallDirs)

# Set Debug as the default build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Enable test coverage options for the debug build type
set(CMAKE_CXX_FLAGS_DEBUG "-fprofile-arcs -ftest-coverage")




# build_executable
# An helper function to create an executable
#
# PUBLIC_DEFINITIONS - public compilation flags to share
# PRIVATE_DEFINITIONS - private compilation flags
# PUBLIC_HEADERS - include directories to share
# PRIVATE_HEADERS - private include directories
# SRCS - sources
# LIBS - libraries
function(build_executable)
  set(oneValueArgs NAME)
  set(multiValueArgs PUBLIC_DEFINITIONS PRIVATE_DEFINITIONS PUBLIC_HEADERS PRIVATE_HEADERS SRCS LIBS)

# https://cmake.org/cmake/help/latest/command/cmake_parse_arguments.html
  cmake_parse_arguments(ARGS "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

  add_executable(
    ${ARGS_NAME}
    ${ARGS_SRCS})

  target_compile_definitions(
    ${ARGS_NAME}
    PUBLIC ${ARGS_PUBLIC_DEFINITIONS}
    PRIVATE ${ARGS_PRIVATE_DEFINITIONS}
    )

  target_include_directories(
    ${ARGS_NAME}
    PUBLIC ${ARGS_PUBLIC_HEADERS}
    PRIVATE ${ARGS_PRIVATE_HEADERS}
    )

  target_link_libraries(
    ${ARGS_NAME}
    ${ARGS_LIBS}
    )

  install(TARGETS ${ARGS_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )
endfunction()

# build_test_executable
# An helper function to create and register an unit test executable
#
# PUBLIC_DEFINITIONS - public compilation flags to share
# PRIVATE_DEFINITIONS - private compilation flags
# PUBLIC_HEADERS - include directories to share
# PRIVATE_HEADERS - private include directories
# SRCS - sources
# LIBS - libraries
function(build_test_executable)
  set(oneValueArgs NAME)
  set(multiValueArgs PUBLIC_DEFINITIONS PRIVATE_DEFINITIONS PUBLIC_HEADERS PRIVATE_HEADERS SRCS LIBS)
  cmake_parse_arguments(ARGS "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

  add_executable(
    ${ARGS_NAME}
    ${ARGS_SRCS})

  target_compile_definitions(
    ${ARGS_NAME}
    PUBLIC ${ARGS_PUBLIC_DEFINITIONS}
    PRIVATE ${ARGS_PRIVATE_DEFINITIONS}
    )

  target_include_directories(
    ${ARGS_NAME}
    PUBLIC ${ARGS_PUBLIC_HEADERS}
    PRIVATE ${ARGS_PRIVATE_HEADERS}
    )

  target_link_libraries(
    ${ARGS_NAME}
    ${ARGS_LIBS}
    )

  find_package(Threads REQUIRED)
  find_package(GTest REQUIRED)
  target_include_directories(
    ${ARGS_NAME}
    PRIVATE ${GTEST_INCLUDE_DIRS}
    )
  target_link_libraries(
    ${ARGS_NAME}
    ${GTEST_BOTH_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
    )
  gtest_add_tests(
    TARGET ${ARGS_NAME}
    )
endfunction()

# build_shared_library
# An helper function to create a shared library
#
# PUBLIC_DEFINITIONS - public compilation flags to share
# PRIVATE_DEFINITIONS - private compilation flags
# PUBLIC_HEADERS - include directories to share
# PRIVATE_HEADERS - private include directories
# SRCS - sources
# LIBS - libraries
function(build_shared_library)
  set(oneValueArgs NAME)
  set(multiValueArgs PUBLIC_DEFINITIONS PRIVATE_DEFINITIONS PUBLIC_HEADERS PRIVATE_HEADERS SRCS LIBS)
  cmake_parse_arguments(ARGS "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

  add_library(
    ${ARGS_NAME} SHARED
    ${ARGS_SRCS})

  target_compile_definitions(
    ${ARGS_NAME}
    PUBLIC ${ARGS_PUBLIC_DEFINITIONS}
    PRIVATE ${ARGS_PRIVATE_DEFINITIONS}
    )

  target_include_directories(
    ${ARGS_NAME}
    PUBLIC ${ARGS_PUBLIC_HEADERS}
    PRIVATE ${ARGS_PRIVATE_HEADERS}
    )

  target_link_libraries(
    ${ARGS_NAME}
    ${ARGS_LIBS}
    )

  install(TARGETS ${ARGS_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )
endfunction()

# build_library
# An helper function to create a static library
#
# PUBLIC_DEFINITIONS - public compilation flags to share
# PRIVATE_DEFINITIONS - private compilation flags
# PUBLIC_HEADERS - include directories to share
# PRIVATE_HEADERS - private include directories
# SRCS - sources
# LIBS - libraries
function(build_library)
  set(oneValueArgs NAME)
  set(multiValueArgs PUBLIC_DEFINITIONS PRIVATE_DEFINITIONS PUBLIC_HEADERS PRIVATE_HEADERS SRCS LIBS)
  cmake_parse_arguments(ARGS "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

  add_library(
    ${ARGS_NAME} STATIC
    ${ARGS_SRCS})

  target_compile_definitions(
    ${ARGS_NAME}
    PUBLIC ${ARGS_PUBLIC_DEFINITIONS}
    PRIVATE ${ARGS_PRIVATE_DEFINITIONS}
    )

  target_include_directories(
    ${ARGS_NAME}
    PUBLIC ${ARGS_PUBLIC_HEADERS}
    PRIVATE ${ARGS_PRIVATE_HEADERS}
    )

  target_link_libraries(
    ${ARGS_NAME}
    ${ARGS_LIBS}
    )

  install(TARGETS ${ARGS_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )
endfunction()
