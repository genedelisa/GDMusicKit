
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
 * @brief a test fixture for the MIDISequence class
 *
 */
struct MIDISequenceTest: testing::Test {
  protected:
    MIDISequence sut;

    MIDISequenceTest() = default;
    // NOLINTNEXTLINE(readability-identifier-naming)
    void SetUp() override {
        MIDITrack track;
        double startBeat{1.0};
        double duration{1.0};
        track.addNote(Note("C4", startBeat, duration));
        track.addNote(Note("D4", startBeat += duration, duration));
        track.addNote(Note("E4", startBeat += duration, duration));
        track.addNote(Note("F4", startBeat += duration, duration));
        sut.addTrack(track);
    }
    // NOLINTNEXTLINE(readability-identifier-naming)
    void TearDown() override {}
};

// the tests

// https://github.com/google/googletest/blob/master/googletest/docs/primer.md#test-fixtures-using-the-same-data-configuration-for-multiple-tests
// tl;dr use TEST_F if you're using a fixture. F for fixture. clever.
// NOLINTNEXTLINE(readability-identifier-naming)
TEST_F(MIDISequenceTest, ShouldInit) {

    MIDITrack track;
    double startBeat{1.0};
    double duration{1.0};
    track.addNote(Note("C4", startBeat, duration));
    track.addNote(Note("D4", startBeat += duration, duration));
    track.addNote(Note("E4", startBeat += duration, duration));
    track.addNote(Note("F4", startBeat += duration, duration));
    sut.addTrack(track);

    EXPECT_EQ(1, sut.size());

    cout << sut << endl;

    sut.clear();
    EXPECT_EQ(0, sut.size());
}

TEST_F(MIDISequenceTest, ShouldIterate) {

    for (const auto& entry : sut) {
        std::cout << entry.first << " => " << entry.second << '\n';
    }

    cout << "structured binding and decomp "
         << "\n";
    // or structured binding and decomposition c++17
    for (const auto& [key, value] : sut) {
        std::cout << key << " => " << value << '\n';
    }

    cout << "begin end "
         << "\n";
    // tell clang-tidy I really want to do this
    // NOLINTNEXTLINE
    for (auto it = sut.begin(); it != sut.end(); ++it) {
        std::cout << it->first << " => " << it->second << '\n';
    }
    cout << endl;
}