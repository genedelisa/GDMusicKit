
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
struct NoteTest: testing::Test {
  protected:
    Note aNote{"C5"};

    std::unique_ptr<Note> note;

    NoteTest() : note{std::make_unique<Note>("C5")} {}

    // NOLINTNEXTLINE(readability-identifier-naming)
    void SetUp() override {}

    // NOLINTNEXTLINE(readability-identifier-naming)
    void TearDown() override {}
};

// the tests

// https://github.com/google/googletest/blob/master/googletest/docs/primer.md#test-fixtures-using-the-same-data-configuration-for-multiple-tests
// tl;dr use TEST_F if you're using a fixture. F for fixture. clever.

// NOLINTNEXTLINE(readability-identifier-naming)
TEST_F(NoteTest, ShouldInitMIDINumber) {

    EXPECT_EQ(60, note->midiPitchNumber());

    auto p = std::make_unique<Note>("C5");
    EXPECT_EQ(60, p->midiPitchNumber());

    p = std::make_unique<Note>("C6");
    EXPECT_EQ(72, p->midiPitchNumber());
}

// NOLINTNEXTLINE(readability-identifier-naming)
TEST(NoteTestFuns, ShouldInitMIDINumberFromString) {

    Note sut{"C5"};
    std::cout << sut << std::endl;
    EXPECT_EQ(60, sut.midiPitchNumber());

    EXPECT_EQ(60, sut.midiPitchNumber());

    sut = Note("Cs5");
    EXPECT_EQ(61, sut.midiPitchNumber());

    sut = Note("D5");
    EXPECT_EQ(62, sut.midiPitchNumber());
    sut = Note("Df5");
    EXPECT_EQ(61, sut.midiPitchNumber());
    sut = Note("Db5");
    EXPECT_EQ(61, sut.midiPitchNumber());
    sut = Note("D#5");
    EXPECT_EQ(63, sut.midiPitchNumber());

    sut = Note("E5");
    EXPECT_EQ(64, sut.midiPitchNumber());
    sut = Note("Eb5");
    EXPECT_EQ(63, sut.midiPitchNumber());
    sut = Note("Ef5");
    EXPECT_EQ(63, sut.midiPitchNumber());

    sut = Note("F5");
    EXPECT_EQ(65, sut.midiPitchNumber());
    sut = Note("F#5");
    EXPECT_EQ(66, sut.midiPitchNumber());

    sut = Note("G5");
    EXPECT_EQ(67, sut.midiPitchNumber());
    sut = Note("Gs5");
    EXPECT_EQ(68, sut.midiPitchNumber());
    sut = Note("Gb5");
    EXPECT_EQ(66, sut.midiPitchNumber());

    sut = Note("C5", 2.5, 1.5);
    EXPECT_EQ(60, sut.midiPitchNumber());
    EXPECT_EQ(2.5, sut.getStartBeat());
    EXPECT_EQ(1.5, sut.getDuration());

}
// NOLINTNEXTLINE(readability-identifier-naming)
TEST(NoteTestFuns, ShouldFailFromString) {
    // Note sut{"Junk"};
    // std::cout << sut << std::endl;

    // assert = Fatal assertion
    // expect = non-Fatal assertion
    ASSERT_ANY_THROW(Note("Junk"));

    EXPECT_THROW(Note("Junk"), std::invalid_argument);
    ASSERT_THROW(Note("Junk"), std::invalid_argument);
}