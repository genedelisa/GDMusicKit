
/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License.
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/

#include "gtest/gtest.h"

#include <memory>

#include <gdmusickit/gdmusickit.h>
using namespace gdmusickit;

/**
 * @brief a test fixture for the Account class
 *
 */
struct PitchStringParserTest: testing::Test {
  protected:
    PitchStringParserTest() {}

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

    ASSERT_THROW(PitchStringParser::stringToMidiNumber("Junk"), std::invalid_argument);

    // EXPECT_EQ(0, PitchStringParser::stringToMidiNumber("Junk"));
}