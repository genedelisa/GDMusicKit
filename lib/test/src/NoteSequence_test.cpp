
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
using std::cout;
using std::endl;

/**
 * @brief a test fixture for the NoteSequence class
 *
 */
struct NoteSequenceTest: testing::Test {
  protected:
    NoteSequence sequence;
    NoteSequenceTest() = default;

    // NOLINTNEXTLINE(readability-identifier-naming)
    void SetUp() override {
        double startBeat{1};
        sequence.addNote("C5", startBeat++, 0.25);
        sequence.addNote("Gf10", startBeat++, 0.25);
        sequence.addNote("bf4", startBeat++, 0.25);
        sequence.addNote("G3", startBeat++, 0.25);
    }
    // NOLINTNEXTLINE(readability-identifier-naming)
    void TearDown() override {}
};

// the tests

// https://github.com/google/googletest/blob/master/googletest/docs/primer.md#test-fixtures-using-the-same-data-configuration-for-multiple-tests
// tl;dr use TEST_F if you're using a fixture. F for fixture. clever.

const Pitch* getPitch(std::string s) {
    return PitchFactory::getSharedInstance().getPitch(s);
}

// NOLINTNEXTLINE(readability-identifier-naming)
TEST(NoteSequenceFuncTest, ShouldAddNoteViaInsertionOp) {
    NoteSequence sequence;
    double startBeat{1};
    double duration{1};
    Note n{"C5", startBeat, duration};
    sequence << n;
    cout << sequence << endl;
    // sequence.addNote("C5", startBeat++, duration);
}

// NOLINTNEXTLINE(readability-identifier-naming)
TEST(NoteSequenceFuncTest, ShouldAddNoteViaInsertionOpString) {
    NoteSequence sequence;
    // double startBeat{1};
    // double duration{1};
    // Note n{"C5", startBeat, duration};

    sequence << "Bb5";
    sequence << "C5";
    sequence << "Eb5";
    sequence << "Ab5"
             << "C3";

    cout << sequence << endl;
    // sequence.addNote("C5", startBeat++, duration);
}

// NOLINTNEXTLINE(readability-identifier-naming)
TEST(NoteSequenceFuncTest, ShouldMakeSequential) {
    NoteSequence sequence;
    double startBeat{1};
    double duration{1};
    // Note n{"C5", startBeat, duration};
    sequence.addNote("C5", startBeat, duration);
    sequence.addNote("Bb5", startBeat, duration);
    sequence.addNote("Eb5", startBeat, duration);
    sequence.addNote("Ab5", startBeat, duration);
    cout << "before sequential"
         << "\n";
    cout << sequence << "\n";
    
    NoteSequence& s = sequence.makeSequential();
    cout << "after sequential"
         << "\n";
    cout << sequence << endl;

    sequence.makeSequential(5);
     cout << "after sequential with gap 5"
         << "\n";
    cout << sequence << endl;

}

// NOLINTNEXTLINE(readability-identifier-naming)
TEST_F(NoteSequenceTest, ShouldAddNote) {
    NoteSequence sequence;
    double startBeat{1};
    double duration{1};

    // sequence.addNote(Note("C5", startBeat++, duration));
    // sequence.addNote(Note("G5", startBeat++, duration));
    // sequence.addNote(Note("Bb5", startBeat++, duration));
    // sequence.addNote(Note("Af5", startBeat++, duration));

    sequence.addNote("C5", startBeat++, duration);
    sequence.addNote("G5", startBeat++, duration);
    sequence.addNote("Bb5", startBeat++, duration);
    sequence.addNote("Af5", startBeat++, duration);

    Note note = sequence[0];
    EXPECT_EQ(60, note.getPitch()->midiPitchNumber());
    EXPECT_EQ(1, note.getStartBeat());
    EXPECT_EQ(1, note.getDuration());

    note = sequence[1];
    EXPECT_EQ(67, note.getPitch()->midiPitchNumber());
    EXPECT_EQ(2, note.getStartBeat());
    EXPECT_EQ(1, note.getDuration());
}

TEST_F(NoteSequenceTest, ShouldRemoveNote) {
    NoteSequence sequence;
    double startBeat{1};
    double duration{1};

    // sequence.addNote(Note("C5", startBeat++, duration));
    // sequence.addNote(Note("G5", startBeat++, duration));
    // sequence.addNote(Note("Bb5", startBeat++, duration));
    // sequence.addNote(Note("Af5", startBeat++, duration));

    sequence.addNote("C5", startBeat++, duration);
    sequence.addNote("G5", startBeat++, duration);
    sequence.addNote("Bb5", startBeat++, duration);
    sequence.addNote("Af5", startBeat++, duration);

    Note note = sequence[0];
    EXPECT_EQ(60, note.getPitch()->midiPitchNumber());
    EXPECT_EQ(1, note.getStartBeat());
    EXPECT_EQ(1, note.getDuration());

    note = sequence[1];
    EXPECT_EQ(67, note.getPitch()->midiPitchNumber());
    EXPECT_EQ(2, note.getStartBeat());
    EXPECT_EQ(1, note.getDuration());

    sequence.removeNote(note);

    std::cout << "After removing the second note" << std::endl;
    std::cout << sequence << std::endl;

    note = sequence[1];
    EXPECT_EQ(70, note.getPitch()->midiPitchNumber());
    // NB the remove does not adjust start times
    EXPECT_EQ(3, note.getStartBeat());
    EXPECT_EQ(1, note.getDuration());
}

TEST_F(NoteSequenceTest, ShouldSearch) {

    std::function<bool(Note)> ifFun = [](Note n) {
        return n.getStartBeat() >= 2;
    };
    auto results = sequence.search(ifFun);

    std::cout << "results of search" << std::endl;
    for (auto n : results) {
        std::cout << n << std::endl;
    }

    ASSERT_EQ(3, results.size());
    Note n = results[0];
    ASSERT_EQ(126, n.getPitch()->midiPitchNumber());
    EXPECT_EQ(2.0, n.getStartBeat());
    n = results[1];
    ASSERT_EQ(58, n.getPitch()->midiPitchNumber());
    EXPECT_EQ(3.0, n.getStartBeat());
    n = results[2];
    ASSERT_EQ(43, n.getPitch()->midiPitchNumber());
    EXPECT_EQ(4.0, n.getStartBeat());
}

/*
TEST_F(NoteSequenceTest, ThisIsNotATest) {

    // Note sut{"C5", 1, 1};
    // std::cout << sut << std::endl;
    // sut.getPitch()->midiPitchNumber();

    NoteSequence seq;

    const Pitch* pp = getPitch("C5");

    auto pitch = PitchFactory::getSharedInstance().getPitch(69);
    double startBeat{1};
    Note n(pitch, startBeat++, 0.5);
    // seq.addNote(n);
    // seq.addNote(Note(pitch, startBeat++, 0.5));
    // seq.addNote(Note(getPitch("C5"), startBeat++, 0.5));
    // seq.addNote(Note("Ab5", startBeat++, 0.25));
    // seq.addNote(Note("Gf10", startBeat++, 0.25));
    // seq.addNote(Note(pp, startBeat++, 1.5));

double duration = 0.25;
sequence.addNote("C5", startBeat++, duration);
    sequence.addNote("G5", startBeat++, duration);
    sequence.addNote("Bb5", startBeat++, duration);
    sequence.addNote("Af5", startBeat++, duration);

    // search with a lambda
    //     std::function<bool(Note)> ifFun = [](Note n) {
    //         return n.getStartBeat() >= 2;
    //     };

    const std::vector<Note>::const_iterator result = find_if(
        seq.begin(), seq.end(), [](Note n) { return n.getStartBeat() >= 2; });

    if (result != seq.end()) {

        std::cout << "find if results" << std::endl;
        // std::cout << *result << std::endl;

        for (auto p = result; p != seq.end(); p++) {
            std::cout << *p << std::endl;
        }
        // for (auto n : result) {
        // std::cout << n << std::endl;
        //}
    }

    // get the first note
    auto v = seq[0];
    std::cout << v << std::endl;

    //    for(int i{0}; i <= seq.size(); ++i) {
    //}

    std::cout << "iteration with begin end" << std::endl;

    for (auto p = seq.begin(); p != seq.end(); p++) {
        std::cout << *p << std::endl;
    }

    std::cout << "Range based iteration" << std::endl;
    for (auto note : seq) {
        std::cout << note << std::endl;
    }
    std::cout << std::endl;

    // EXPECT_EQ(60, pitch->midiPitchNumber());

    // auto p = std::make_unique<Pitch>(60);
    // EXPECT_EQ(60, p->midiPitchNumber());

    // p = std::make_unique<Pitch>(72);
    // EXPECT_EQ(72, p->midiPitchNumber());
}
*/

TEST_F(NoteSequenceTest, ShouldWriteToCout) {

    NoteSequence seq;
    double startBeat{0};
    // seq.addNote(Note("Ab5", startBeat++, 0.25));
    // seq.addNote(Note("Gf10", startBeat++, 0.25));
    // seq.addNote(Note("bf4", startBeat++, 0.25));
    // seq.addNote(Note("G3", startBeat++, 0.25));
    double duration = 0.25;

    sequence.addNote("C5", startBeat++, duration);
    sequence.addNote("G5", startBeat++, duration);
    sequence.addNote("Bb5", startBeat++, duration);
    sequence.addNote("Af5", startBeat++, duration);

    std::cout << "Here is a sequence via the << overload\n";
    std::cout << seq << std::endl;
    std::cout << "Here is the fixture's sequence via the << overload\n";
    std::cout << sequence << std::endl;
    // @todo how do you test this?
}
