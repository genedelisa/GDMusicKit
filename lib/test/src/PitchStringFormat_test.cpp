
/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License.
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/

#include "gtest/gtest.h"

#include <gdmusickit/gdmusickit.h>

using namespace gdmusickit;

/**
 * @brief a test fixture for the Account class
 *
 */
struct PitchStringFormatTest: testing::Test {
  protected:
    PitchStringFormatTest() = default;
    // NOLINTNEXTLINE(readability-identifier-naming)
    void SetUp() override {}
    // NOLINTNEXTLINE(readability-identifier-naming)
    void TearDown() override {}
};

// the tests

// https://github.com/google/googletest/blob/master/googletest/docs/primer.md#test-fixtures-using-the-same-data-configuration-for-multiple-tests
// tl;dr use TEST_F if you're using a fixture. F for fixture. clever.
// NOLINTNEXTLINE(readability-identifier-naming)
TEST_F(PitchStringFormatTest, ShouldFormat) {}
// NOLINTNEXTLINE(readability-identifier-naming)
TEST(PitchStringFormatTestFuns, ShouldFormatFlat) {

    PitchStringFormat::getSharedInstance().setWidth(0);

    bool includeOctave{true};

    EXPECT_EQ("C0", PitchStringFormat::getSharedInstance().stringFromMIDINumber(
                        0, PitchStringFormat::Spelling::flat,
                        PitchStringFormat::Justification::left, includeOctave));

    EXPECT_EQ("Db0",
              PitchStringFormat::getSharedInstance().stringFromMIDINumber(
                  1, PitchStringFormat::Spelling::flat,
                  PitchStringFormat::Justification::left, includeOctave));

    EXPECT_EQ("C#0",
              PitchStringFormat::getSharedInstance().stringFromMIDINumber(
                  1, PitchStringFormat::Spelling::sharp,
                  PitchStringFormat::Justification::left, includeOctave));
}
// NOLINTNEXTLINE(readability-identifier-naming)
TEST(PitchStringFormatTestFuns, ShouldFormatSolfege) {

    PitchStringFormat::getSharedInstance().setWidth(0);
    bool includeOctave = false;

    EXPECT_EQ("do", PitchStringFormat::getSharedInstance().stringFromMIDINumber(
                        0, PitchStringFormat::Spelling::solfege,
                        PitchStringFormat::Justification::left, includeOctave));
    EXPECT_EQ("do", PitchStringFormat::getSharedInstance().stringFromMIDINumber(
                        12, PitchStringFormat::Spelling::solfege,
                        PitchStringFormat::Justification::left, includeOctave));
    EXPECT_EQ("do", PitchStringFormat::getSharedInstance().stringFromMIDINumber(
                        24, PitchStringFormat::Spelling::solfege,
                        PitchStringFormat::Justification::left, includeOctave));
    EXPECT_EQ("do", PitchStringFormat::getSharedInstance().stringFromMIDINumber(
                        36, PitchStringFormat::Spelling::solfege,
                        PitchStringFormat::Justification::left, includeOctave));
    EXPECT_EQ("do", PitchStringFormat::getSharedInstance().stringFromMIDINumber(
                        48, PitchStringFormat::Spelling::solfege,
                        PitchStringFormat::Justification::left, includeOctave));
    EXPECT_EQ("do", PitchStringFormat::getSharedInstance().stringFromMIDINumber(
                        60, PitchStringFormat::Spelling::solfege,
                        PitchStringFormat::Justification::left, includeOctave));
    EXPECT_EQ("do", PitchStringFormat::getSharedInstance().stringFromMIDINumber(
                        72, PitchStringFormat::Spelling::solfege,
                        PitchStringFormat::Justification::left, includeOctave));
    EXPECT_EQ("do", PitchStringFormat::getSharedInstance().stringFromMIDINumber(
                        84, PitchStringFormat::Spelling::solfege,
                        PitchStringFormat::Justification::left, includeOctave));
    EXPECT_EQ("do", PitchStringFormat::getSharedInstance().stringFromMIDINumber(
                        96, PitchStringFormat::Spelling::solfege,
                        PitchStringFormat::Justification::left, includeOctave));

    EXPECT_EQ("di", PitchStringFormat::getSharedInstance().stringFromMIDINumber(
                        1, PitchStringFormat::Spelling::solfege,
                        PitchStringFormat::Justification::left, includeOctave));
    EXPECT_EQ("di", PitchStringFormat::getSharedInstance().stringFromMIDINumber(
                        13, PitchStringFormat::Spelling::solfege,
                        PitchStringFormat::Justification::left, includeOctave));
    EXPECT_EQ("di", PitchStringFormat::getSharedInstance().stringFromMIDINumber(
                        25, PitchStringFormat::Spelling::solfege,
                        PitchStringFormat::Justification::left, includeOctave));
    EXPECT_EQ("di", PitchStringFormat::getSharedInstance().stringFromMIDINumber(
                        37, PitchStringFormat::Spelling::solfege,
                        PitchStringFormat::Justification::left, includeOctave));
    EXPECT_EQ("di", PitchStringFormat::getSharedInstance().stringFromMIDINumber(
                        49, PitchStringFormat::Spelling::solfege,
                        PitchStringFormat::Justification::left, includeOctave));
    EXPECT_EQ("di", PitchStringFormat::getSharedInstance().stringFromMIDINumber(
                        61, PitchStringFormat::Spelling::solfege,
                        PitchStringFormat::Justification::left, includeOctave));
    EXPECT_EQ("di", PitchStringFormat::getSharedInstance().stringFromMIDINumber(
                        73, PitchStringFormat::Spelling::solfege,
                        PitchStringFormat::Justification::left, includeOctave));
    EXPECT_EQ("di", PitchStringFormat::getSharedInstance().stringFromMIDINumber(
                        85, PitchStringFormat::Spelling::solfege,
                        PitchStringFormat::Justification::left, includeOctave));
    EXPECT_EQ("di", PitchStringFormat::getSharedInstance().stringFromMIDINumber(
                        97, PitchStringFormat::Spelling::solfege,
                        PitchStringFormat::Justification::left, includeOctave));
    // @todo: complete all of this
}

/*
 int midiNumber,
            PitchStringFormat::Spelling spelling = Spelling::flat,
            PitchStringFormat::Justification justification =
                Justification::left,
            bool includeOctave = true);
 */