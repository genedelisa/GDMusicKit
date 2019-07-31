cmake_minimum_required(VERSION 3.14.0 FATAL_ERROR)

project(gdmusicTestApp
    VERSION 1.0.0
    LANGUAGES CXX
    DESCRIPTION "Music classes test app"
    HOMEPAGE_URL "https://github.com/genedelisa/gdmusickit"
)

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

##########################################
add_executable(loggingTestApp
	src/Log.cpp
	src/Logging.cpp
	src/loggingfrobs.cpp
)
target_compile_features(loggingTestApp
	PRIVATE
		cxx_std_17
)
# https://cmake.org/cmake/help/latest/variable/CMAKE_LANG_COMPILER_ID.html

target_compile_options(loggingTestApp
	PRIVATE
	    $<$<CXX_COMPILER_ID:AppleClang>:-g -Wall -Wextra -pedantic>
    	$<$<CXX_COMPILER_ID:Clang>:-Wall -DBOOST_LOG_DYN_LINK>
		$<$<CXX_COMPILER_ID:MSVC>:/W3>
    	$<$<CXX_COMPILER_ID:Clang>:-Wall -DBOOST_LOG_DYN_LINK>
    	$<$<CXX_COMPILER_ID:GNU>:-Wall>
)

target_link_libraries(loggingTestApp
	PUBLIC
		GDMusicKit::GDMusicKit
		${Boost_LIBRARIES}
	PRIVATE
)

##########################################
add_executable(gdmusicTestApp
	src/main
)
target_compile_features(gdmusicTestApp
	PRIVATE
		cxx_std_17
)
target_compile_options(gdmusicTestApp
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


target_link_libraries(gdmusicTestApp
	PUBLIC
		GDMusicKit::GDMusicKit
		${Boost_LIBRARIES}
	PRIVATE
	 #Boost::log
)

message("CMAKE_CURRENT_SOURCE_DIR/../lib/include ${CMAKE_CURRENT_SOURCE_DIR}/../lib/include")

# Set library target properties
target_include_directories(gdmusicTestApp
    PUBLIC
        ${Boost_INCLUDE_DIRS}
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../lib/include>

        # $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/gdmusic>

    PRIVATE
        # /Library/Developer/CommandLineTools/usr/include/c++/v1

		${CMAKE_SOURCE_DIR}../lib/include/
)

# https://cmake.org/cmake/help/latest/command/target_link_options.html
target_link_options(gdmusicTestApp
    PUBLIC
    "$<$<CONFIG:DEBUG>:${-v}>"
    #    -DBOOST_LOG_DYN_LINK
)



message("Boost_LIBRARIES: ${Boost_LIBRARIES}")
#/usr/local/lib/libboost_log-mt.a;/usr/local/lib/libboost_date_time-mt.a;/usr/local/lib/libboost_log_setup-mt.a;/usr/local/lib/libboost_filesystem-mt.a;/usr/local/lib/libboost_thread-mt.a;/usr/local/lib/libboost_regex-mt.a;/usr/local/lib/libboost_chrono-mt.a;/usr/local/lib/libboost_atomic-mt.a










