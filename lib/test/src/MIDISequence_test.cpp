
/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License.
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/

#include "gtest/gtest.h"

#include <memory>

#include <gdmusickit/gdmusickit.h>
using namespace gdmusickit;
using namespace std;

/**
 * @brief a test fixture for the MIDISequence class
 *
 */
struct MIDISequenceTest: testing::Test {
  protected:
    MIDISequence sut;

    MIDISequenceTest() {  }

    void SetUp() override {}
    void TearDown() override {}
};

// the tests

// https://github.com/google/googletest/blob/master/googletest/docs/primer.md#test-fixtures-using-the-same-data-configuration-for-multiple-tests
// tl;dr use TEST_F if you're using a fixture. F for fixture. clever.

TEST_F(MIDISequenceTest, ShouldInit) {

    //EXPECT_EQ(60, pitch->midiPitchNumber());

    //cout << sut << endl;
}