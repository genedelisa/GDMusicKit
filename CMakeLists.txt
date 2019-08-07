cmake_minimum_required(VERSION 3.14.0 FATAL_ERROR)

project(GDMusicKit
    VERSION 1.0.0
    LANGUAGES CXX
    DESCRIPTION "Music classes"
    HOMEPAGE_URL "https://github.com/genedelisa/gdmusickit"
)

##############################################

# for debugging cmake files
include(CMakePrintHelpers)
# https://cmake.org/cmake/help/latest/module/CMakePrintHelpers.html


#add_subdirectory(doc)
#add_subdirectory(lib)
#add_subdirectory(app)


#####################################################################
# where to put the output. Otherwise the main will be in src and the test in test.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

cmake_print_variables(
    CMAKE_MAJOR_VERSION
    CMAKE_MINOR_VERSION
    CMAKE_CURRENT_SOURCE_DIR
)
