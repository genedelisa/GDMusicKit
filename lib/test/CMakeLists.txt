
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

# https://cmake.org/cmake/help/latest/variable/CMAKE_LANG_COMPILER_ID.html
target_compile_options(gdmusickit_test
	PRIVATE
       	$<$<CXX_COMPILER_ID:AppleClang>:-g -Wall -Wextra -pedantic>
        $<$<CXX_COMPILER_ID:Clang>:-g -Wall -Wextra -pedantic>
		$<$<CXX_COMPILER_ID:MSVC>:/W3>
    	$<$<CXX_COMPILER_ID:GNU>:-g -Wall>
)
target_link_libraries(gdmusickit_test
    PUBLIC
    gtest
	gtest_main
	GDMusicKit::gdmusickit
)

gtest_discover_tests(gdmusickit_test
    ${Source}
    "discovering tests"
)

# link against gtest or gtest_main as needed. Eg
#add_executable(example example.cpp)
#target_link_libraries(example gtest_main)
#add_test(NAME example_test COMMAND example)
