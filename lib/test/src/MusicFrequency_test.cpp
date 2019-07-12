
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
struct MusicFrequencyTest: testing::Test {
  protected:
    std::unique_ptr<Pitch> pitch;

    MusicFrequencyTest(): 
    pitch{std::make_unique<Pitch>(60)} {}

    void SetUp() override {}
    void TearDown() override {}
};

// the tests

// https://github.com/google/googletest/blob/master/googletest/docs/primer.md#test-fixtures-using-the-same-data-configuration-for-multiple-tests
// tl;dr use TEST_F if you're using a fixture. F for fixture. clever.

TEST_F(MusicFrequencyTest, ShouldInitMIDINumber) {

    EXPECT_EQ(60, pitch->midiPitchNumber());

    auto p = std::make_unique<Pitch>(60);
    EXPECT_EQ(60, p->midiPitchNumber());

    p = std::make_unique<Pitch>(72);
    EXPECT_EQ(72, p->midiPitchNumber());
}
