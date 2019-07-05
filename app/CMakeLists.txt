cmake_minimum_required(VERSION 3.14.0 FATAL_ERROR)

project(gdmusicTestApp
    VERSION 1.0.0
    LANGUAGES CXX
    DESCRIPTION "Music classes test app"
    HOMEPAGE_URL "https://github.com/genedelisa/gdmusickit"
)

# Disable in-source builds to prevent source tree corruption.
#if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
#  message(FATAL_ERROR "
#FATAL: In-source builds are not allowed.
#       You should create a separate directory for build files.
#")
#endif()

# set(CMAKE_PREFIX_PATH "GDMusicKit")
#set(GDMusicKit_DIR "../../gdmusickit/cmake")

add_executable(loggingTestApp
	src/Log.cpp
	src/Logging.cpp
	src/loggingfrobs.cpp
)
target_compile_features(loggingTestApp
	PRIVATE
		cxx_std_17
)
target_compile_options(loggingTestApp
	PRIVATE
		$<$<CXX_COMPILER_ID:MSVC>:/W3>
    	$<$<CXX_COMPILER_ID:Clang>:-Wall -DBOOST_LOG_DYN_LINK>
    	$<$<CXX_COMPILER_ID:GNU>:-Wall>
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
		$<$<CXX_COMPILER_ID:MSVC>:/W3>
    	$<$<CXX_COMPILER_ID:Clang>:-Wall>
    	$<$<CXX_COMPILER_ID:GNU>:-Wall>
)




# did not find: FindGDMusicKit.cmake" in CMAKE_MODULE_PATH
#set(GDMusicKit_DIR "/usr/local/lib/cmake/GDMusicKit")

find_package(GDMusicKit 1.0 REQUIRED)
#find_package(Threads REQUIRED)

#########################################################
set(Boost_USE_STATIC_LIBS ON)
# to debug this find
set(Boost_DEBUG OFF)
# https://cmake.org/cmake/help/latest/module/FindBoost.html
find_package(Boost 1.7.0 REQUIRED COMPONENTS log)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

#ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)

target_link_libraries(gdmusicTestApp
 PUBLIC
	GDMusicKit::GDMusicKit
)
target_link_libraries(loggingTestApp
	PUBLIC
		GDMusicKit::GDMusicKit
		#${Boost_LIBRARIES}
	PRIVATE
	 Boost::log
		#Threads::Threads
)

message("Boost_LIBRARIES: ${Boost_LIBRARIES}")
#/usr/local/lib/libboost_log-mt.a;/usr/local/lib/libboost_date_time-mt.a;/usr/local/lib/libboost_log_setup-mt.a;/usr/local/lib/libboost_filesystem-mt.a;/usr/local/lib/libboost_thread-mt.a;/usr/local/lib/libboost_regex-mt.a;/usr/local/lib/libboost_chrono-mt.a;/usr/local/lib/libboost_atomic-mt.a
#Boost::boost









