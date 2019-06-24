
/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License.
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/

#include "gtest/gtest.h"

#include <iostream>
#include <memory>

#include <gdmusickit/gdmusickit.h>
using namespace gdmusickit;

/**
 * @brief a test fixture for the Account class
 *
 */
struct NoteSequenceTest: testing::Test {
  protected:
    NoteSequenceTest() {}

    void SetUp() override {}
    void TearDown() override {}
};

// the tests

// https://github.com/google/googletest/blob/master/googletest/docs/primer.md#test-fixtures-using-the-same-data-configuration-for-multiple-tests
// tl;dr use TEST_F if you're using a fixture. F for fixture. clever.

TEST_F(NoteSequenceTest, ShouldInitMIDINumber) {

    NoteSequence seq;

    Pitch pitch = PitchFactory::getSharedInstance().getPitch(69);
    double startBeat{0};
    Note n(pitch, startBeat++, 0.5);
    seq.addNote(n);
    seq.addNote(Note(pitch, startBeat++, 0.5));    
    seq.addNote(Note(pitch, startBeat++, 0.5));    
    seq.addNote(Note(pitch, startBeat++, 0.5));    
    seq.addNote(Note(pitch, startBeat++, 0.5));                

    auto v = seq[0];
    std::cout << v << std::endl;

    for(int i{0}; i <= seq.size(); ++i) {
    
    }

    std::cout << "Range based iteration" << std::endl;
    for(auto n : seq) {
        std::cout << n << std::endl;
    }

    // EXPECT_EQ(60, pitch->midiPitchNumber());

    // auto p = std::make_unique<Pitch>(60);
    // EXPECT_EQ(60, p->midiPitchNumber());

    // p = std::make_unique<Pitch>(72);
    // EXPECT_EQ(72, p->midiPitchNumber());
}
