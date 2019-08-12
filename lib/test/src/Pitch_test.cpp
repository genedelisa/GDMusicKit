
/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License.
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/
#include "gtest/gtest.h"
#include <gdmusickit/gdmusickit.h>
#include <iomanip>
#include <iostream>
#include <memory>

using namespace gdmusickit;
using std::cout;
using std::endl;

/**
 * @brief a test fixture for the Account class
 *
 */
struct PitchTest: testing::Test {
  protected:
    // NOLINTNEXTLINE(misc-non-private-member-variables-in-classes)
    std::unique_ptr<Pitch> pitch;

    PitchTest() : pitch{std::make_unique<Pitch>(60)} {}

    // NOLINTNEXTLINE(readability-identifier-naming)
    void SetUp() override {}

    // NOLINTNEXTLINE(readability-identifier-naming)
    void TearDown() override {}
};

// the tests

// https://github.com/google/googletest/blob/master/googletest/docs/primer.md#test-fixtures-using-the-same-data-configuration-for-multiple-tests
// tl;dr use TEST_F if you're using a fixture. F for fixture. clever.

// NOLINTNEXTLINE(readability-identifier-naming)
TEST_F(PitchTest, ShouldInitMIDINumber) {

    EXPECT_EQ(60, pitch->midiPitchNumber());

    auto p = std::make_unique<Pitch>(60);
    EXPECT_EQ(60, p->midiPitchNumber());

    p = std::make_unique<Pitch>(72);
    EXPECT_EQ(72, p->midiPitchNumber());

    // std::cout << gdmusickit::Pitch::C0;
    std::cout << *Pitch::C0 << "\n";
    std::cout << std::endl;

    // std::cout << C0;
}

TEST(PitchFunTest, ShouldMatchETFq) {

    int middleC = 60;
    auto fq = Pitch::midiEqualTemperamentFrequency(middleC);

    cout << std::fixed << std::setprecision(14);
    cout << "Middle C fq is: " << fq << endl;
    // EXPECT_DOUBLE_EQ(261.626, fq);
    EXPECT_NEAR(261.62556530059862, fq, 0.00000000001);

    Pitch p{middleC};
    EXPECT_NEAR(261.62556530059862, p.getEqualTemperamentFrequency(),
                0.00000000001);
}

TEST(PitchFunTest, ShouldHaveValidConstants) {
    ASSERT_NE(Pitch::C5, nullptr);
    EXPECT_EQ(60, Pitch::C5->midiPitchNumber());
    EXPECT_NEAR(261.62556530059862, Pitch::C5->getEqualTemperamentFrequency(),
                0.00000000001);
}


TEST(PitchFunTest, ShouldTranspose) {
    const Pitch* p = Pitch::C5;
    
    Interval::SemiTones i = Interval::SemiTones::majorSecond;

    Pitch* p2 = p->transposed(i);
    EXPECT_EQ(62, p2->midiPitchNumber());

}