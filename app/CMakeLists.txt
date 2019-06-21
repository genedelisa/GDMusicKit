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

add_executable(gdmusicTestApp src/main)

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
target_link_libraries(gdmusicTestApp
	GDMusicKit::GDMusicKit
)

