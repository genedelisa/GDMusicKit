
/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License.
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/

#include "gtest/gtest.h"

#include <memory>

#include "Logging.hpp"
#include <gdmusickit/gdmusickit.h>

using namespace gdmusickit;
using namespace std;

/**
 * @brief a test fixture for the Account class
 *
 */
struct MIDITrackTest: testing::Test {
  protected:
    MIDITrack sut{0};

    MIDITrackTest() = default;

    void SetUp() override {
        double startBeat{1};
        sut.addNote(Note("C5", startBeat++, 0.25));
        sut.addNote(Note("Gf10", startBeat++, 0.25));
        sut.addNote(Note("bf4", startBeat++, 0.25));
        sut.addNote(Note("G3", startBeat++, 0.25));
    }
    void TearDown() override {}
};

// the tests

// https://github.com/google/googletest/blob/master/googletest/docs/primer.md#test-fixtures-using-the-same-data-configuration-for-multiple-tests
// tl;dr use TEST_F if you're using a fixture. F for fixture. clever.

TEST_F(MIDITrackTest, ShouldInit) {

    // EXPECT_EQ(60, pitch->midiPitchNumber());
    // LOG_INFO << sut;
    LOG_INFO << sut << endl;
}

TEST_F(MIDITrackTest, ShouldChangeStartBeat) {

    // setLogLevelDebug();

    LOG_INFO << sut << "\n";
    sut.changeStartBeat(4.0);
    LOG_INFO << "changed sb to 4"
             << "\n";
    LOG_INFO << sut << "\n";
}

TEST(MIDITrackLocalTest, ShouldFindNotesAtBeat) {
    MIDITrack localSut{0};
    double startBeat{1};
    localSut.addNote(Note("C5", startBeat, 0.25));
    localSut.addNote(Note("Gf10", startBeat, 0.25));
    localSut.addNote(Note("bf4", startBeat++, 0.25));
    localSut.addNote(Note("G3", startBeat++, 0.25));

    auto v = localSut.notesAtBeat(1);
    for (auto& n : v) {
        LOG_INFO << n << "\n";
        EXPECT_EQ(1.0, n.getStartBeat());
    }
     EXPECT_EQ(3, v.size());

}
