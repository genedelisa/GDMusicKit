
#######################################
# Download google test 
include(GoogleTestConfig.in)

#######################################
# Configure the tests

# not found when running the the container
include(googletest)

set(Source
src/Note_test.cpp
src/PitchStringParser_test.cpp
src/PitchStringFormat_test.cpp
src/Pitch_test.cpp
src/PitchFactory_test.cpp
src/MusicFrequency_test.cpp
src/NoteSequence_test.cpp
src/MIDISequence_test.cpp
src/MIDITrack_test.cpp
src/main.cpp        
)

add_executable(gdmusickit_test
    ${Source}
)

target_compile_features(gdmusickit_test
	PRIVATE
		cxx_std_17
)

# add_compile_options(
#   "-Wall" "-Wpedantic" "-Wextra" "-fexceptions"
#   "$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb>"
# )
# if(MSVC)
#     add_compile_options("/W4" "$<$<CONFIG:RELEASE>:/O2>")
# else()
#     add_compile_options("-Wall" "-Wextra" "-Werror" "$<$<CONFIG:RELEASE>:-O3>")
#     if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
#         add_compile_options("-stdlib=libc++")
#     else()
#         # nothing special for gcc at the moment
#     endif()
# endif()


# https://cmake.org/cmake/help/latest/variable/CMAKE_LANG_COMPILER_ID.html
target_compile_options(gdmusickit_test
	PRIVATE

       # $<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-O0 -g3>

       	$<$<CXX_COMPILER_ID:AppleClang>:-Wall -Wextra -pedantic -fvisibility=hidden>
        $<$<CXX_COMPILER_ID:Clang>:-g -Wall -Wextra -pedantic>
		$<$<CXX_COMPILER_ID:MSVC>:/W3>
    	$<$<CXX_COMPILER_ID:GNU>:-g -Wall>
)
target_link_libraries(gdmusickit_test
    PUBLIC
    gtest
	gtest_main
	GDMusicKit::gdmusickit
    ${Boost_LIBRARIES}
)

# https://cmake.org/cmake/help/latest/command/target_link_options.html
target_link_options(gdmusickit_test
    PUBLIC
    -v
    #    -DBOOST_LOG_DYN_LINK
)

gtest_discover_tests(gdmusickit_test
    ${Source}
    "discovering tests"
)

# link against gtest or gtest_main as needed. Eg
#add_executable(example example.cpp)
#target_link_libraries(example gtest_main)
#add_test(NAME example_test COMMAND example)
