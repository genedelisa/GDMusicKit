// -*- C++ -*-
/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License.
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/
#include "gtest/gtest.h"
#include <gdmusickit/gdmusickit.h>
#include <memory>

using namespace gdmusickit;
using namespace std;

/**
 * @brief a test fixture for the Scale class
 *
 */
struct ScaleTest: testing::Test {
  protected:
    Scale sut = Scale::Major;

    ScaleTest() = default;
    // NOLINTNEXTLINE(readability-identifier-naming)
    void SetUp() override {}
    // NOLINTNEXTLINE(readability-identifier-naming)
    void TearDown() override {}
};

// the tests

// https://github.com/google/googletest/blob/master/googletest/docs/primer.md#test-fixtures-using-the-same-data-configuration-for-multiple-tests
// tl;dr use TEST_F if you're using a fixture. F for fixture. clever.
// NOLINTNEXTLINE(readability-identifier-naming)
TEST_F(ScaleTest, ShouldInit) { ASSERT_GT(sut.getIntervals().size(), 0); }

TEST(ScaleFunTest, ShouldCreatePitchesFromIntervals) {
    auto s = Scale::Major;

    auto pitches = s.pitchesFromIntervals(Pitch::C5);

    for (const auto p : pitches) {
        cout << *p << "\n";
    }
    cout << endl;

    ASSERT_EQ(Pitch::C5, pitches.at(0));
    ASSERT_EQ(Pitch::D5, pitches.at(1));
    ASSERT_EQ(Pitch::E5, pitches.at(2));
    ASSERT_EQ(Pitch::F5, pitches.at(3));
    ASSERT_EQ(Pitch::G5, pitches.at(4));
    ASSERT_EQ(Pitch::A5, pitches.at(5));
    ASSERT_EQ(Pitch::B5, pitches.at(6));
    ASSERT_EQ(Pitch::C6, pitches.at(7));
}
