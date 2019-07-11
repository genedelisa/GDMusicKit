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
# find_package(Boost REQUIRED COMPONENTS system)
# find_package(Boost REQUIRED COMPONENTS regex)

set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED ON)  
#set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.7.0 REQUIRED COMPONENTS system log) 

if(Boost_FOUND)
    message("boost libraries found")
    message("Boost_LIBRARIES ${Boost_LIBRARIES}")
 #/usr/local/lib/libboost_system-mt.dylib
 # static /usr/local/lib/libboost_system-mt.a;/usr/local/lib/libboost_log-mt.a;/usr/local/lib/libboost_date_time-mt.a;/usr/local/lib/libboost_log_setup-mt.a;/usr/local/lib/libboost_filesystem-mt.a;/usr/local/lib/libboost_thread-mt.a;/usr/local/lib/libboost_regex-mt.a;/usr/local/lib/libboost_chrono-mt.a;/usr/local/lib/libboost_atomic-mt.a
    message("Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    # /usr/local/include

    #include_directories(${Boost_INCLUDE_DIRS}) 
    #add_executable(progname file1.cxx file2.cxx) 
    #target_link_libraries(progname ${Boost_LIBRARIES})
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

add_library(gdmusickit
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
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>

        # $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/gdmusic>

    PRIVATE
         /Library/Developer/CommandLineTools/usr/include/c++/v1

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

# https://cmake.org/cmake/help/latest/variable/CMAKE_LANG_COMPILER_ID.html
target_compile_options(gdmusickit
	PRIVATE
       	$<$<CXX_COMPILER_ID:AppleClang>:-g -Wall -Wextra -pedantic>
        $<$<CXX_COMPILER_ID:Clang>:-g -Wall -Wextra -pedantic>
		$<$<CXX_COMPILER_ID:MSVC>:/W3>
    	$<$<CXX_COMPILER_ID:GNU>:-g -Wall>
)


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
