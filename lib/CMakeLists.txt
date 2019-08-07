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
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_SOURCE_DIR}/CMake)
message("CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}")

# Output the compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# for debugging cmake files
include(CMakePrintHelpers)
# https://cmake.org/cmake/help/latest/module/CMakePrintHelpers.html

##############################################
# dependencies
# find_package(Boost REQUIRED COMPONENTS system)
# find_package(Boost REQUIRED COMPONENTS regex)


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


if(APPLE)
    message("this is apple. finding core audio")
    find_library(CORE_AUDIO_LIBRARY CoreAudio)
    find_library(AUDIO_TOOLBOX_LIBRARY AudioToolbox)
    find_library(AUDIO_UNIT_LIBRARY AudioUnit)
    find_library(CARBON_LIBRARY Carbon)
    SET(NATIVE_AUDIO_LIBS ${CORE_AUDIO_LIBRARY} ${AUDIO_TOOLBOX_LIBRARY} ${AUDIO_UNIT_LIBRARY} ${CARBON_LIBRARY})
elseif(UNIX)
    message("this is unix. finding alsa audio")
    set(THREADS_PREFER_PTHREAD_FLAG ON)
    find_package(ALSA REQUIRED)
    find_package(Threads REQUIRED)
    SET(NATIVE_AUDIO_LIBS rt ${ALSA_LIBRARIES} jack Threads::Threads)
endif()

message("NATIVE_AUDIO_LIBS: ${NATIVE_AUDIO_LIBS}")

##############################################

option(CLANG_TIDY           "Enable Clang Tidy"                     ON)
option(CPPLINT              "Enable CppLint"                        ON)
option(LINK_WHAT_YOU_USE    "Enable link-what-you-use"              OFF)
option(INCLUDE_WHAT_YOU_USE "Enable include-what-you-use"           OFF)

##############################################
# Create library target

add_library(gdmusickit STATIC
    src/MacMIDI.cpp
    src/Logging.cpp    
    src/PitchFactory.cpp
    src/MusicFrequency.cpp
    src/Pitch.cpp
    src/PitchStringFormat.cpp
    src/PitchStringParser.cpp    
    src/Note.cpp
    src/NoteSequence.cpp
    src/MIDISequence.cpp
    src/MIDITrack.cpp   
    src/TimedMetaMessage.cpp 
)

#Add an alias so that library can be used inside the build tree, e.g. when testing
add_library(GDMusicKit::gdmusickit ALIAS gdmusickit)


# Set library target properties
target_include_directories(gdmusickit
    PUBLIC
        ${Boost_INCLUDE_DIRS}
        $<INSTALL_INTERFACE:include/gdmusickit>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>

        # $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/gdmusic>

    PRIVATE
        # /Library/Developer/CommandLineTools/usr/include/c++/v1

        #${CMAKE_CURRENT_SOURCE_DIR}/include/

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

# add_compile_options(
#     # Enable (almost) all warnings on compilers
#     # https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Wall-316
#     $<$<CXX_COMPILER_ID:GNU>:-Wall>
#     # http://clang.llvm.org/docs/DiagnosticsReference.html#wall
#     $<$<CXX_COMPILER_ID:Clang>:-Wall>
#     # https://msdn.microsoft.com/en-us/library/thxezb7y.aspx#Anchor_1
#     $<$<CXX_COMPILER_ID:MSVC>:/W4>

#     $<$<CXX_COMPILER_ID:Clang>:-Wextra>
#     $<$<CXX_COMPILER_ID:Clang>:-pedantic>
#     $<$<CXX_COMPILER_ID:Clang>:-fvisibility=hidden>
#     #$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-O0;-g3;>

#     # Disable "'<param>': unreferenced formal parameter" warning
#     $<$<CXX_COMPILER_ID:MSVC>:/wd4100>
#     # Disable "'<class>::<member>': class '<member-type>' needs to have dll-interface to be used by clients of class '<class>'" warning
#     $<$<CXX_COMPILER_ID:MSVC>:/wd4251>
#     # Disable "'<func>': unreferenced local function has been removed" warning
#     $<$<CXX_COMPILER_ID:MSVC>:/wd4505>
#     # Disable "declaration of '<type>' hides global declaration" warning
#     $<$<CXX_COMPILER_ID:MSVC>:/wd4459>
#     # Disable "function '<func>' marked as __forceinline not inlined" warning
#     $<$<CXX_COMPILER_ID:MSVC>:/wd4714>

#     # Enable C++ Exception unwind mechanics with DLL support
#     $<$<CXX_COMPILER_ID:MSVC>:/EHsc>
# )

#######################################################################
# N.B.
#it looks like if you set target_compile_options, then this is not used
#######################################################################
add_compile_options(
    "$<$<CXX_COMPILER_ID:AppleClang>:-pedantic>"

    "$<$<CXX_COMPILER_ID:GNU>:-Os>"
    "$<$<CXX_COMPILER_ID:GNU>:-s>"
    "$<$<CXX_COMPILER_ID:GNU>:-Wall>"
    "$<$<CXX_COMPILER_ID:GNU>:-Wextra>"
    "$<$<AND:$<CXX_COMPILER_ID:GNU>,$<CONFIG:DEBUG>>:-g3>"
    "$<$<AND:$<CXX_COMPILER_ID:GNU>,$<CONFIG:DEBUG>>:-fno-omit-frame-pointer>"

    "$<$<CXX_COMPILER_ID:Clang>:-Os>"
    "$<$<CXX_COMPILER_ID:Clang>:-Wall>"
    "$<$<CXX_COMPILER_ID:Clang>:-Wextra>"
    "$<$<CXX_COMPILER_ID:Clang>:-fvisibility=hidden>"
    "$<$<AND:$<CXX_COMPILER_ID:Clang>,$<CONFIG:DEBUG>>:-g3>"
    "$<$<AND:$<CXX_COMPILER_ID:Clang>,$<CONFIG:DEBUG>>:-O0>"
    "$<$<AND:$<CXX_COMPILER_ID:Clang>,$<CONFIG:DEBUG>>:-fno-omit-frame-pointer>"
    

    "$<$<CXX_COMPILER_ID:AppleClang>:-Wall>"
    "$<$<CXX_COMPILER_ID:AppleClang>:-Wextra>"
    "$<$<CXX_COMPILER_ID:AppleClang>:-fembed-bitcode>"
    "$<$<CXX_COMPILER_ID:AppleClang>:-fvisibility=hidden>"
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-g3>"
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-O0>"
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-fno-omit-frame-pointer>"

    "$<$<AND:$<CXX_COMPILER_ID:MSVC>,$<CONFIG:DEBUG>>:/Od>"
    "$<$<AND:$<CXX_COMPILER_ID:MSVC>,$<CONFIG:RELEASE>>:/Os>"
)

add_compile_options(
    "$<$<AND:$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>,$<CONFIG:RELEASE>>:-Oz>"
    "$<$<AND:$<NOT:$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>>,$<CONFIG:RELEASE>>:-Os>"
)


# https://cmake.org/cmake/help/latest/variable/CMAKE_LANG_COMPILER_ID.html
target_compile_options(gdmusickit
	PRIVATE

    "$<$<CXX_COMPILER_ID:AppleClang>:-Wall>"
    "$<$<CXX_COMPILER_ID:AppleClang>:-Wextra>"
    "$<$<CXX_COMPILER_ID:AppleClang>:-pedantic>"
    "$<$<CXX_COMPILER_ID:AppleClang>:-fembed-bitcode>"
    "$<$<CXX_COMPILER_ID:AppleClang>:-fvisibility=hidden>"

    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-g3>"
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-O0>"
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-fno-omit-frame-pointer>"
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-DDEBUG>"

    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-fprofile-arcs>"
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-ftest-coverage>"


    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:RELEASE>>:-DNDEBUG>"
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:RELEASE>>:-O3>"


#   https://msdn.microsoft.com/en-us/library/thxezb7y.aspx#Anchor_1
    $<$<CXX_COMPILER_ID:MSVC>:/W4>

#   https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Wall-316
    $<$<CXX_COMPILER_ID:GNU>:-Wall>
    $<$<CXX_COMPILER_ID:GNU>:-Wextra>
    $<$<CXX_COMPILER_ID:GNU>:-pedantic>

#   http://clang.llvm.org/docs/DiagnosticsReference.html#wall
    $<$<CXX_COMPILER_ID:Clang>:-Wall>
    $<$<CXX_COMPILER_ID:Clang>:-Wextra>
    $<$<CXX_COMPILER_ID:Clang>:-pedantic> 

)
# for boost link warnings
# -fvisibility=hidden


# clang++ -cc1 --help
# https://github.com/Barro/compiler-warnings

target_link_libraries(gdmusickit
    PUBLIC
        ${Boost_LIBRARIES}
    PRIVATE
        ${NATIVE_AUDIO_LIBS}
        #Boost::regex
)
# https://cmake.org/cmake/help/latest/command/target_link_options.html
target_link_options(gdmusickit 
    PUBLIC 
        "$<$<CONFIG:DEBUG>:${-v}>"
)

#########################

add_subdirectory(test)
add_subdirectory(doc)

#########################
include(installation.cmake.in)

# Including custom cmake rules
include(CMake/clang-cxx-dev-tools.cmake)


# set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=-*,readability-*)
# CMAKE_<LANG>_CPPLINT
# CMAKE_CXX_CPPLINT


# https://blog.kitware.com/static-checks-with-cmake-cdash-iwyu-clang-tidy-lwyu-cpplint-and-cppcheck/

# Enable Clang Tidy
# -----------------
# -DCMAKE_CXX_CLANG_TIDY:STRING="clang-tidy;-checks=-*,readability-*"

if (CLANG_TIDY)
	find_program(CLANG_TIDY_PATH NAMES clang-tidy)
	if (CLANG_TIDY_PATH)
		message(STATUS "Looking for clang-tidy - found")
		set (CLANG_TIDY_OPTS
			${CLANG_TIDY_PATH}
			# "-fix"
			"-checks=-*,readability-*,modernize-*"
		)
		set (CMAKE_C_CLANG_TIDY "${CLANG_TIDY_OPTS}")
		set (CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_OPTS}")
		set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ferror-limit=0")
		set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ferror-limit=0")
	else ()
		message(STATUS "Looking for clang-tidy - not found")
	endif ()
endif (CLANG_TIDY)


# Enable CppLint
# --------------
# -DCMAKE_CXX_CPPLINT:STRING="cpplint;--linelength=79"
# pip install cpplint

if (CPPLINT)
	find_program(CPPLINT_PATH NAMES cpplint)
	if (CPPLINT_PATH)
		message(STATUS "Looking for CppLint - found")
		set (CPPLINT_OPTS
			${CPPLINT_PATH}
			"--linelength=79"
		)
		set (CMAKE_C_CPPLINT "${CPPLINT_OPTS}")
		set (CMAKE_CXX_CPPLINT "${CPPLINT_OPTS}")
		set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ferror-limit=0")
		set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ferror-limit=0")
	else ()
		message(STATUS "Looking for CppLint - not found")
	endif ()
endif (CPPLINT)


# -DCMAKE_CMAKE_LINK_WHAT_YOU_USE:BOOL=ON

if (LINK_WHAT_YOU_USE)
	message(STATUS "Enabling link-what-you-use - ok")
	set (CMAKE_LINK_WHAT_YOU_USE ON)
endif (LINK_WHAT_YOU_USE)


# Enable Google's Include What You Use
# ------------------------------------
# -DCMAKE_CXX_INCLUDE_WHAT_YOU_USE:STRING="include-what-you-use;-Xiwyu;--mapping_file=../iwyu.imp"

if (INCLUDE_WHAT_YOU_USE)
	find_program(INCLUDE_WHAT_YOU_USE_PATH NAMES include-what-you-use iwyu)
	if (INCLUDE_WHAT_YOU_USE_PATH)
		message(STATUS "Looking for include-what-you-use - found")
		set (INCLUDE_WHAT_YOU_USE_OPTS
			${INCLUDE_WHAT_YOU_USE_PATH}
			"-Xiwyu"
			"--mapping_file=${PROJECT_SOURCE_DIR}/iwyu.imp"
		)
		set (CMAKE_C_INCLUDE_WHAT_YOU_USE "${INCLUDE_WHAT_YOU_USE_OPTS}")
		set (CMAKE_CXX_INCLUDE_WHAT_YOU_USE "${INCLUDE_WHAT_YOU_USE_OPTS}")
		set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ferror-limit=0")
		set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ferror-limit=0")
	else ()
		message(STATUS "Looking for include-what-you-use - not found")
	endif ()
endif (INCLUDE_WHAT_YOU_USE)

########### Add uninstall target ###############
CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/cmake_uninstall.cmake"
  IMMEDIATE @ONLY)
ADD_CUSTOM_TARGET(uninstall
  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake/cmake_uninstall.cmake")



# https://cmake.org/cmake/help/latest/manual/cmake-properties.7.html?#properties-on-targets
cmake_print_properties(
    TARGETS 
        gdmusickit
    PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY 
        COMPILE_DEFINITIONS
        COMPILE_FEATURES
        COMPILE_FLAGS
        COMPILE_OPTIONS

        INTERFACE_AUTOUIC_OPTIONS
        INTERFACE_COMPILE_DEFINITIONS
        INTERFACE_COMPILE_FEATURES
        INTERFACE_COMPILE_OPTIONS
        INTERFACE_INCLUDE_DIRECTORIES
        INTERFACE_LINK_DEPENDS
        INTERFACE_LINK_DIRECTORIES
        INTERFACE_LINK_LIBRARIES
        INTERFACE_LINK_OPTIONS
        INTERFACE_POSITION_INDEPENDENT_CODE
        INTERFACE_SOURCES
        INTERFACE_SYSTEM_INCLUDE_DIRECTORIES

        CXX_CLANG_TIDY
        CXX_COMPILER_LAUNCHER
        CXX_CPPCHECK
        CXX_CPPLINT
        CXX_INCLUDE_WHAT_YOU_USE
        CXX_VISIBILITY_PRESET
)

# https://cmake.org/cmake/help/latest/manual/cmake-variables.7.html
cmake_print_variables(
    CMAKE_MAJOR_VERSION
    CMAKE_MINOR_VERSION
    CMAKE_PROJECT_NAME
    CMAKE_CURRENT_SOURCE_DIR
)