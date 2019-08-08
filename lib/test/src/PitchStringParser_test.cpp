
/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License.
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/
#include <memory>

#include "gtest/gtest.h"


#include <gdmusickit/gdmusickit.h>
using namespace gdmusickit;

/**
 * @brief a test fixture for the Account class
 *
 */
struct PitchStringParserTest: testing::Test {
  protected:
    PitchStringParserTest() = default;

    void SetUp() override {}
    void TearDown() override {}
};

// the tests

// https://github.com/google/googletest/blob/master/googletest/docs/primer.md#test-fixtures-using-the-same-data-configuration-for-multiple-tests
// tl;dr use TEST_F if you're using a fixture. F for fixture. clever.

TEST_F(PitchStringParserTest, ShouldParseToMIDINumber) {

    EXPECT_EQ(0, PitchStringParser::stringToMidiNumber("C"));
    EXPECT_EQ(60, PitchStringParser::stringToMidiNumber("C5"));
    EXPECT_EQ(59, PitchStringParser::stringToMidiNumber("CF5"));
    EXPECT_EQ(59, PitchStringParser::stringToMidiNumber("Cb5"));
    EXPECT_EQ(61, PitchStringParser::stringToMidiNumber("CS5"));
    EXPECT_EQ(61, PitchStringParser::stringToMidiNumber("C#5"));

    EXPECT_EQ(2, PitchStringParser::stringToMidiNumber("D"));
    EXPECT_EQ(62, PitchStringParser::stringToMidiNumber("D5"));
    EXPECT_EQ(61, PitchStringParser::stringToMidiNumber("DF5"));
    EXPECT_EQ(61, PitchStringParser::stringToMidiNumber("Db5"));
    EXPECT_EQ(63, PitchStringParser::stringToMidiNumber("DS5"));
    EXPECT_EQ(63, PitchStringParser::stringToMidiNumber("D#5"));
}

TEST_F(PitchStringParserTest, ShouldNotParseToMIDINumber) {

    // assert = Fatal assertion
    // expect = non-Fatal assertion
    ASSERT_ANY_THROW(PitchStringParser::stringToMidiNumber("Junk"));
    ASSERT_THROW(PitchStringParser::stringToMidiNumber("Junk"),
                 std::invalid_argument);
    // EXPECT_THROW(PitchStringParser::stringToMidiNumber("Junk"),
    // std::invalid_argument);

    // EXPECT_EQ(0, PitchStringParser::stringToMidiNumber("Junk"));
}

TEST_F(PitchStringParserTest, ShouldTestToBeValid) {
    EXPECT_TRUE(PitchStringParser::isValid("D"));
    EXPECT_TRUE(PitchStringParser::isValid("D5"));
    EXPECT_TRUE(PitchStringParser::isValid("Db5"));
    EXPECT_TRUE(PitchStringParser::isValid("D#5"));            
}


TEST_F(PitchStringParserTest, ShouldTestToBeInvalid) {
    EXPECT_FALSE(PitchStringParser::isValid("D13"));
    EXPECT_FALSE(PitchStringParser::isValid("Junk"));
    EXPECT_FALSE(PitchStringParser::isValid("Dq5"));

}
