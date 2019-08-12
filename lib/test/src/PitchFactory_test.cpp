
/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License.
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/
#include <memory>

#include "Logging.hpp"
#include "gtest/gtest.h"

#include <gdmusickit/gdmusickit.h>
using namespace gdmusickit;

/**
 * @brief a test fixture for the Account class
 *
 */
struct PitchFactoryTest: testing::Test {
  protected:
    PitchFactoryTest() = default;

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
    EXPECT_EQ(0, p->midiPitchNumber());

    //  p =
    //  PitchFactory::getSharedInstance().getPitch(Pitch::A5.midiPitchNumber());
    // EXPECT_EQ(69, p.midiPitchNumber());

    // p = std::make_unique<Pitch>(72);
    // EXPECT_EQ(72, p->midiPitchNumber());
}

/**
 * @brief Construct a new test f object
 * @test to init from string
 *
 */
TEST_F(PitchFactoryTest, ShouldInitMIDINumberFromString) {
    // std::string s{"C5"};
    // auto p = PitchFactory::getSharedInstance().getPitch(s);
    auto p = PitchFactory::getSharedInstance().getPitch("C5");
    EXPECT_EQ(60, p->midiPitchNumber());

    p = PitchFactory::getSharedInstance().getPitch("Db5");
    EXPECT_EQ(61, p->midiPitchNumber());

    p = PitchFactory::getSharedInstance().getPitch("A5");
    EXPECT_EQ(69, p->midiPitchNumber());

    // p = PitchFactory::getSharedInstance().getPitch("badinput");
    // EXPECT_EQ(69, p.midiPitchNumber());
}

TEST_F(PitchFactoryTest, ShouldBeSamePitchObject) {
    const Pitch* p = PitchFactory::getSharedInstance().getPitch("C5");
    LOG_INFO << "addr of test object" << std::addressof(p) << "\n";

    EXPECT_EQ(60, p->midiPitchNumber());

    const Pitch* p2 = PitchFactory::getSharedInstance().getPitch("C5");
    EXPECT_EQ(60, p2->midiPitchNumber());

    const Pitch* p3 = PitchFactory::getSharedInstance().getPitch(60);
    EXPECT_EQ(60, p3->midiPitchNumber());

    const Pitch* p4 = Pitch::C5;

    EXPECT_EQ(p, p2);
    EXPECT_EQ(p, p3);
    EXPECT_EQ(p, p4);
    EXPECT_EQ(p2, p3);

    EXPECT_EQ(std::addressof(*p), std::addressof(*p2));
    EXPECT_EQ(std::addressof(*p), std::addressof(*p3));
    EXPECT_EQ(std::addressof(*p2), std::addressof(*p3));
    EXPECT_EQ(std::addressof(*p), std::addressof(*p4));
    
}

TEST_F(PitchFactoryTest, ShouldBeSameFactory) {
    const PitchFactory& p = PitchFactory::getSharedInstance();
    const PitchFactory& p2 = PitchFactory::getSharedInstance();

    // "invalid operands to binary expression". well, I didn't make it
    // comparable
    // EXPECT_EQ(p, p2);
    EXPECT_EQ(std::addressof(p), std::addressof(p2));
}
