cmake_minimum_required(VERSION 3.14.0 FATAL_ERROR)

project(GDMusicKit
    VERSION 1.0.0
    LANGUAGES CXX
    DESCRIPTION "Music classes"
    HOMEPAGE_URL "https://github.com/genedelisa/gdmusickit"
)

# just for testing
#set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/libinstall" CACHE PATH "Installation Directory")

# be able to find custom modules
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_SOURCE_DIR}/cmake)

##############################################
# dependencies
find_package(Boost REQUIRED COMPONENTS regex)

##############################################
# Create library target

add_library(gdmusickit
    src/PitchFactory.cpp
    src/MusicFrequency.cpp
    src/Pitch.cpp
    src/PitchStringFormat.cpp
    src/PitchStringParser.cpp    
    src/Note.cpp
)

#Add an alias so that library can be used inside the build tree, e.g. when testing
add_library(GDMusicKit::gdmusickit ALIAS gdmusickit)

# Set library target properties
target_include_directories(gdmusickit
    PUBLIC
        $<INSTALL_INTERFACE:include>
#        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/gdmusic>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/
#        ${CMAKE_CURRENT_SOURCE_DIR}/include/gdmusic
#        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
#target_include_directories(mylib INTERFACE
#  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/mylib>
#  $<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
#)

target_compile_features(gdmusickit
	PRIVATE
		cxx_std_17
)

target_compile_options(gdmusickit
	PRIVATE
		$<$<CXX_COMPILER_ID:MSVC>:/W3>
    	$<$<CXX_COMPILER_ID:Clang>:-Wall>
    	$<$<CXX_COMPILER_ID:GNU>:-Wall>
)

target_link_libraries(gdmusickit
    PUBLIC
        Boost::boost
    PRIVATE
        Boost::regex
)

#########################

add_subdirectory(test)
add_subdirectory(doc)

#########################
include(installation.cmake.in)
