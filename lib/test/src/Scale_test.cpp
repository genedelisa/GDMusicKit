// -*- C++ -*-
/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License.
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/
#include <memory>

#include "gtest/gtest.h"

#include <gdmusickit/gdmusickit.h>

using namespace gdmusickit;
using namespace std;

/**
 * @brief a test fixture for the Scale class
 *
 */
struct ScaleTest: testing::Test {
  protected:
    Scale sut = Scale::major;

    ScaleTest() = default;
    // NOLINTNEXTLINE(readability-identifier-naming)
    void SetUp() override {
        
    }
    // NOLINTNEXTLINE(readability-identifier-naming)
    void TearDown() override {}
};

// the tests

// https://github.com/google/googletest/blob/master/googletest/docs/primer.md#test-fixtures-using-the-same-data-configuration-for-multiple-tests
// tl;dr use TEST_F if you're using a fixture. F for fixture. clever.
// NOLINTNEXTLINE(readability-identifier-naming)
TEST_F(ScaleTest, ShouldInit) {

    ASSERT_GT(sut.getIntervals().size(), 0);
}