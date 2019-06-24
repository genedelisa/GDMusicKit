
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
struct PitchFactoryTest: testing::Test {
  protected:
    PitchFactoryTest() {}

    void SetUp() override {}
    void TearDown() override {}
};

// the tests

// https://github.com/google/googletest/blob/master/googletest/docs/primer.md#test-fixtures-using-the-same-data-configuration-for-multiple-tests
// tl;dr use TEST_F if you're using a fixture. F for fixture. clever.

// TEST(PitchFactoryTest, ShouldPrint) {
// }

TEST_F(PitchFactoryTest, ShouldInitMIDINumber) {

    auto p = PitchFactory::getSharedInstance().getPitch(0);
    // auto p = std::make_unique<Pitch>(60);
    EXPECT_EQ(0, p.midiPitchNumber());

    //  p =
    //  PitchFactory::getSharedInstance().getPitch(Pitch::A5.midiPitchNumber());
    // EXPECT_EQ(69, p.midiPitchNumber());

    // p = std::make_unique<Pitch>(72);
    // EXPECT_EQ(72, p->midiPitchNumber());
}

TEST_F(PitchFactoryTest, ShouldInitMIDINumberFromString) {
    std::string s{"C5"};

    auto p = PitchFactory::getSharedInstance().getPitch(s);
//auto p = PitchFactory::getSharedInstance().getPitch("C5");    
    EXPECT_EQ(60, p.midiPitchNumber());
}
