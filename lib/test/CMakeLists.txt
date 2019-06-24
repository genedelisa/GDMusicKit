
#######################################
# Download google test 
include(GoogleTestConfig.in)

#######################################
# Configure the tests

include(googletest)

set(Source
src/Note_test.cpp
src/PitchStringParser_test.cpp
src/PitchStringFormat_test.cpp
src/Pitch_test.cpp
src/PitchFactory_test.cpp
src/MusicFrequency_test.cpp
src/NoteSequence_test.cpp
src/main.cpp        
)

add_executable(gdmusickit_test
    ${Source}
)

target_compile_features(gdmusickit_test
	PRIVATE
		cxx_std_17
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