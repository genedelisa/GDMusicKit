
#######################################
# Download google test 
include(GoogleTestConfig.in)

#######################################
# Configure the tests

include(googletest)

set(Source
    src/main.cpp
    src/Pitch_test.cpp
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