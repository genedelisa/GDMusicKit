
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
    std::unique_ptr<Pitch> pitch;

    NoteTest() : pitch{std::make_unique<Pitch>(60)} {}

    void SetUp() override {}
    void TearDown() override {}
};

// the tests

// https://github.com/google/googletest/blob/master/googletest/docs/primer.md#test-fixtures-using-the-same-data-configuration-for-multiple-tests
// tl;dr use TEST_F if you're using a fixture. F for fixture. clever.

TEST_F(NoteTest, ShouldInitMIDINumber) {

    EXPECT_EQ(60, pitch->midiPitchNumber());

    auto p = std::make_unique<Pitch>(60);
    EXPECT_EQ(60, p->midiPitchNumber());

    p = std::make_unique<Pitch>(72);
    EXPECT_EQ(72, p->midiPitchNumber());
}

TEST(NoteTestFuns, ShouldInitMIDINumberFromString) {

    Note sut{"C5"};
    std::cout << sut << std::endl;
    EXPECT_EQ(60, sut.getPitch().midiPitchNumber());

    sut = Note("Cs5");
    EXPECT_EQ(61, sut.getPitch().midiPitchNumber());

    sut = Note("D5");
    EXPECT_EQ(62, sut.getPitch().midiPitchNumber());
    sut = Note("Df5");
    EXPECT_EQ(61, sut.getPitch().midiPitchNumber());
    sut = Note("Db5");
    EXPECT_EQ(61, sut.getPitch().midiPitchNumber());
    sut = Note("D#5");
    EXPECT_EQ(63, sut.getPitch().midiPitchNumber());

    sut = Note("E5");
    EXPECT_EQ(64, sut.getPitch().midiPitchNumber());
    sut = Note("Eb5");
    EXPECT_EQ(63, sut.getPitch().midiPitchNumber());
    sut = Note("Ef5");
    EXPECT_EQ(63, sut.getPitch().midiPitchNumber());

    sut = Note("F5");
    EXPECT_EQ(65, sut.getPitch().midiPitchNumber());
    sut = Note("F#5");
    EXPECT_EQ(66, sut.getPitch().midiPitchNumber());

    sut = Note("G5");
    EXPECT_EQ(67, sut.getPitch().midiPitchNumber());
    sut = Note("Gs5");
    EXPECT_EQ(68, sut.getPitch().midiPitchNumber());
    sut = Note("Gb5");
    EXPECT_EQ(66, sut.getPitch().midiPitchNumber());
}

TEST(NoteTestFuns, ShouldFailFromString) {
    // Note sut{"Junk"};
    // std::cout << sut << std::endl;

    // assert = Fatal assertion
    // expect = non-Fatal assertion
    ASSERT_ANY_THROW(Note("Junk"));

    EXPECT_THROW(Note("Junk"), std::invalid_argument);
    ASSERT_THROW(Note("Junk"), std::invalid_argument);
}