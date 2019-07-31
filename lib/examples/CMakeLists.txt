# set minimum cmake version
cmake_minimum_required(VERSION 3.14.0 FATAL_ERROR)

project(multiAppProject
    VERSION 1.0.0
    LANGUAGES CXX
    DESCRIPTION "CMake with multiple mains"
    HOMEPAGE_URL "https://github.com/genedelisa/somerepo"
)

message("top level cmake ${PROJECT_SOURCE_DIR}")

#########################################################
find_package(GDMusicKit 1.0 REQUIRED)

#########################################################
# to debug this find
set(Boost_DEBUG OFF)

# https://cmake.org/cmake/help/latest/module/FindBoost.html
#find_package(Boost 1.7.0 REQUIRED COMPONENTS log)
#include_directories(${Boost_INCLUDE_DIRS})
#link_directories(${Boost_LIBRARY_DIRS})
#ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)

set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS         OFF) # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.7.0 REQUIRED COMPONENTS system log)
if(Boost_FOUND)
    message("boost libraries found")
    message("Boost_LIBRARIES ${Boost_LIBRARIES}")
 #/usr/local/lib/libboost_system-mt.dylib
 # static /usr/local/lib/libboost_system-mt.a;/usr/local/lib/libboost_log-mt.a;/usr/local/lib/libboost_date_time-mt.a;/usr/local/lib/libboost_log_setup-mt.a;/usr/local/lib/libboost_filesystem-mt.a;/usr/local/lib/libboost_thread-mt.a;/usr/local/lib/libboost_regex-mt.a;/usr/local/lib/libboost_chrono-mt.a;/usr/local/lib/libboost_atomic-mt.a
    message("Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    # /usr/local/include
    else()
    message("ERROR boost not found")
    return()
endif()
#########################################################


#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
# On some platforms, this results in linking to a different library (e.g. -std=c++11 rather than -std=gnu++11).
#set(CMAKE_CXX_EXTENSIONS OFF)


##################################################################
set(Source
  ./NoteExample.cpp
)

##################################################################
# build an executable for each src file
foreach( sourcefile ${Source} )

	# https://cmake.org/cmake/help/latest/command/get_filename_component.html
	# NAME_WE   = File name without directory or longest extension
	get_filename_component(programName ${sourcefile} NAME_WE)
	message("${programName} from ${sourcefile}")

	add_executable( ${programName} ${sourcefile} )

	set_target_properties(${programName} PROPERTIES
   		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
	)
    

target_compile_features(${programName}
	PRIVATE
		cxx_std_17
)
target_compile_options(${programName}
	PRIVATE

	"$<$<CXX_COMPILER_ID:AppleClang>:-Wall>"
    "$<$<CXX_COMPILER_ID:AppleClang>:-Wextra>"
    "$<$<CXX_COMPILER_ID:AppleClang>:-fembed-bitcode>"
    "$<$<CXX_COMPILER_ID:AppleClang>:-fvisibility=hidden>"

    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-g3>"
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-O0>"
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-fno-omit-frame-pointer>"
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-DDEBUG>"

    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:RELEASE>>:-DNDEBUG>"
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:RELEASE>>:-O3>"
)


target_link_libraries(${programName}
	PUBLIC
		GDMusicKit::GDMusicKit
		${Boost_LIBRARIES}
	PRIVATE
)

message("lib/include is: ${CMAKE_CURRENT_SOURCE_DIR}/../include")

# Set library target properties
target_include_directories(${programName}
    PUBLIC
        ${Boost_INCLUDE_DIRS}
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>

    PRIVATE
        # /Library/Developer/CommandLineTools/usr/include/c++/v1
		${CMAKE_SOURCE_DIR}../lib/include/
)

# https://cmake.org/cmake/help/latest/command/target_link_options.html
target_link_options(${programName}
    PUBLIC
    "$<$<CONFIG:DEBUG>:${-v}>"
    #    -DBOOST_LOG_DYN_LINK
)


endforeach( sourcefile ${Source} )







#####################################################################
# Options
# https://cmake.org/cmake/help/latest/command/option.html

# e.g. cmake -D USE_UNIT_TESTING=ON ..
option(USE_UNIT_TESTING "Build the tests" OFF)
option(GENERATE_DOC "Run Doxygen to generate docs" OFF)
# possible incantation:
# cd build && cmake -D USE_UNIT_TESTING=ON -D GENERATE_DOC=ON .. && make
#####################################################################

if(GENERATE_DOC)
  add_subdirectory(doc)
endif(GENERATE_DOC)

