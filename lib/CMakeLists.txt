cmake_minimum_required(VERSION 3.14.0 FATAL_ERROR)

project(GDMusicKit
    VERSION 1.0.0
    LANGUAGES CXX
    DESCRIPTION "Music classes"
    HOMEPAGE_URL "https://github.com/genedelisa/gdmusickit"
)

# Enable C++17 standard options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

##############################################
# Options
option(USE_CLANG_TIDY           "Enable Clang Tidy"             ON)
option(USE_CPPLINT              "Enable CppLint"                OFF)
option(USE_CPPCHECK              "Enable Cppcheck"              OFF)
option(USE_LINK_WHAT_YOU_USE    "Enable link-what-you-use"      ON)
option(USE_INCLUDE_WHAT_YOU_USE "Enable include-what-you-use"   ON)
# if off, assume that you installed it
option(DOWNLOAD_GTEST            "Download Google Test"         OFF)
##############################################

# be able to find custom modules
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_SOURCE_DIR}/CMake)
#list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)
message("CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}")
# Load CMake modules
#include(BuildModules)
include(StaticAnalysis)
#include(PackageConfig)
#include(clang-cxx-dev-tools)

# Enable static/dynamic tests
# this is a macro in StaticAnalysis.cmake
enable_static_analysis()


# Output the compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# for debugging cmake files
include(CMakePrintHelpers)
# https://cmake.org/cmake/help/latest/module/CMakePrintHelpers.html

##############################################
# dependencies

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
# Create library target

set(LibSource
    #${CMAKE_CURRENT_SOURCE_DIR}/src/gdlib/Frob.cpp
    #src/MacMIDI.cpp
    src/Interval.cpp
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
    #src/TimedMetaMessage.cpp 
)

add_library(gdmusickit STATIC
    ${LibSource}
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

#https://clang.llvm.org/docs/UsersManual.html

# https://cmake.org/cmake/help/latest/variable/CMAKE_LANG_COMPILER_ID.html
target_compile_options(gdmusickit
	PRIVATE
    #https://clang.llvm.org/docs/DiagnosticsReference.html#wall
    "$<$<CXX_COMPILER_ID:AppleClang>:-Wall>"
    #https://clang.llvm.org/docs/DiagnosticsReference.html#wextra
    "$<$<CXX_COMPILER_ID:AppleClang>:-Wextra>"
    # https://clang.llvm.org/docs/UsersManual.html#cmdoption-pedantic
    "$<$<CXX_COMPILER_ID:AppleClang>:-pedantic>"

    #"$<$<CXX_COMPILER_ID:AppleClang>:-fembed-bitcode>"
    #"$<$<CXX_COMPILER_ID:AppleClang>:-fvisibility=hidden>"

    #"$<$<CXX_COMPILER_ID:AppleClang>:-fvisibility=hidden>"

    #https://clang.llvm.org/docs/UsersManual.html#cmdoption-g
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-g3>"
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-O0>"
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-DDEBUG>"
#    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-fprofile-arcs>"
#    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-ftest-coverage>"
#    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-fno-omit-frame-pointer>"

    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:RELEASE>>:-DNDEBUG>"
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:RELEASE>>:-O3>"
    #https://clang.llvm.org/docs/UsersManual.html#cmdoption-g0
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:RELEASE>>:-g0>"

 

#   https://msdn.microsoft.com/en-us/library/thxezb7y.aspx#Anchor_1
    $<$<CXX_COMPILER_ID:MSVC>:/W4>

#   https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Wall-316
    $<$<CXX_COMPILER_ID:GNU>:-Wall>
    $<$<CXX_COMPILER_ID:GNU>:-Wextra>
    $<$<CXX_COMPILER_ID:GNU>:-pedantic>
    "$<$<AND:$<CXX_COMPILER_ID:GNU>,$<CONFIG:DEBUG>>:-fno-omit-frame-pointer>"
    "$<$<CXX_COMPILER_ID:GNU>:-fembed-bitcode>"
#   http://clang.llvm.org/docs/DiagnosticsReference.html#wall
    $<$<CXX_COMPILER_ID:Clang>:-Wall>
    $<$<CXX_COMPILER_ID:Clang>:-Wextra>
    $<$<CXX_COMPILER_ID:Clang>:-pedantic> 

)
# for boost link warnings
# -fvisibility=hidden

# set_target_properties(gdmusickit PROPERTIES 
#     VERSION ${PROJECT_VERSION}
#     SOVERSION 1
#     PUBLIC_HEADER include/gdmusickit/gdmusickit.h
#     #PUBLIC_HEADER "${CMAKE_SOURCE_DIR}/include/gdmusickit/gdmusickit.h"
# )

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
        "$<$<CONFIG:DEBUG>:${-lgcov}>"
        "$<$<CONFIG:DEBUG>:${--coverage}>"
)

#########################

add_subdirectory(test)
add_subdirectory(doc)

#########################
include(installation.cmake.in)

# Including custom cmake rules
# include(CMake/clang-cxx-dev-tools.cmake)



########### Add uninstall target ###############
#CONFIGURE_FILE(
#  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
#  "${CMAKE_CURRENT_BINARY_DIR}/cmake/cmake_uninstall.cmake"
#  IMMEDIATE @ONLY)
#ADD_CUSTOM_TARGET(uninstall
#  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake/cmake_uninstall.cmake")



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