// -*- C++ -*-

/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License.
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/
/** @file Scale.hpp
 *  @brief brief The Scale class.
 *
 *  The Scale
 *
 *  @date date 2019-07-19
 *  @copyright Copyright (c) 2019 Rockhopper Technologies, Inc.
 *  @version 0.1.0
 *  @author Gene De Lisa (gene@rockhoppertech.com)
 *  @bug No known bugs.
 *  @see http://rockhoppertech.com/
 */

#ifndef GDMUSICKIT_SCALE_HPP
#define GDMUSICKIT_SCALE_HPP

#pragma once

//#include "gdmusickit/Note.hpp"
//#include "gdmusickit/Pitch.hpp"
//#include "gdmusickit/PitchFactory.hpp"

#include <algorithm>
#include <charconv> // from_char, to_char
#include <exception>
#include <iostream>
#include <map>
#include <string>

namespace gdmusickit {

    class Scale {
      public:
        Scale(std::string name, std::vector<int> intervals)
            : name(name), intervals(intervals) {}

        [[nodiscard]] std::string getName() const { return name; }

        [[nodiscard]] std::vector<int> getIntervals() const {
            return intervals;
        }

        std::vector<Pitch*> pitchesFromIntervals(int root);

        std::vector<Pitch*> pitchesFromIntervals(const Pitch* root) {
            return pitchesFromIntervals(root->midiPitchNumber());
        }

      private:
        std::string              name;
        std::vector<int>         intervals;
        std::vector<int>         degrees;
        std::vector<Pitch>       pitches;
        std::string              spelling;
        std::string              information;
        std::vector<std::string> categories;
        /**
         * e.g. melodic minor has a different descending form
         */
        bool             descendingDifferent = false;
        std::vector<int> descendingIntervals;

        int octave;

        std::string key = "C";

        std::vector<std::string> aliases;

        // KeySignature keySignature;

      public:
        static const Scale                              major;
        static const Scale                              symmetricalDecatonic;
        static const std::map<std::string, const Scale> scaleMap;

        static const Scale Lydian;
        static const Scale HarmonicMinor;
        static const Scale Aeolian;
        static const Scale Persian;
        static const Scale DoubleHarmonic;
        static const Scale Egyptian;
        static const Scale Mohammedan;
        static const Scale MelodicMajor;
        static const Scale Pelog2;
        static const Scale TwoSemitoneTritone;
        static const Scale Japanese;
        static const Scale MelodicMinor;
        static const Scale DiminishedDominant;
        static const Scale Pelog;
        static const Scale Hawaiian;
        static const Scale Jewish;
        static const Scale Augmented;
        static const Scale HarmonicMajor;
        static const Scale Overtone;
        static const Scale HalfDiminished;
        static const Scale PelogBarang;
        static const Scale Tritone;
        static const Scale Messiaen4thModeInverse;
        static const Scale NeapolitanMinor;
        static const Scale LydianMinor;
        static const Scale OctatonicMode2;
        static const Scale Chromatic;
        static const Scale MajorLocrian;
        static const Scale Balinese;
        static const Scale NeapolitanMajor;
        static const Scale Oriental;
        static const Scale Arabian;
        static const Scale Hindu;
        static const Scale PentatonicMinor;
        static const Scale HungarianMinor;
        static const Scale PentatonicMajor;
        static const Scale WholeTone;
        static const Scale Messiaen6thMode;
        static const Scale Iwato;
        static const Scale HungarianGypsy;
        static const Scale Phrygian;
        static const Scale AlteredDominant;
        static const Scale Kumoi;
        static const Scale LydianDominant;
        static const Scale InvertedAugmented;
        static const Scale Octatonic;
        static const Scale EightToneSpanish;
        static const Scale HungarianMajor;
        static const Scale IonianAugmented;
        static const Scale Mixolydian;
        static const Scale Messiaen7thMode;
        static const Scale Locrian;
        static const Scale Diminished;
        static const Scale Messiaen5thModeInverse;
        static const Scale LydianAugmented;
        static const Scale Messiaen6thModeInverse;
        static const Scale Javanese;
        static const Scale Major;
        static const Scale SymmetricalDecatonic;
        static const Scale Mongolian;
        static const Scale Messiaen2ndModeTruncated;
        static const Scale Bebopminor;
        static const Scale Spanish;
        static const Scale Slendro;
        static const Scale RomanianMinor;
        static const Scale LydianRaised2;
        static const Scale Ethiopian;
        static const Scale Hirajoshi;
        static const Scale Messiaen5thMode;
        static const Scale GenusChromaticum;
        static const Scale Byzantine;
        static const Scale RagaNeelangi;
        static const Scale Messiaen3rdMode;
        static const Scale LeadingWholeTone;
        static const Scale Gypsy;
        static const Scale WholeToneFlat5;
        static const Scale VanDerHost;
        static const Scale PelogBem;
        static const Scale Dorian;
        static const Scale Ultralocrian;
        static const Scale Enigmatic;
        static const Scale DiminishedMinor;
        static const Scale PhrygianDominant;
        static const Scale Messiaen7thModeInverse;
        static const Scale Algerian;
        static const Scale Chinese;
        static const Scale LocrianRaised6;
        static const Scale DorianFlat2;
        static const Scale BebopDominant;
        static const Scale BebopHalfDiminished;
        static const Scale MajorPhrygian;
        static const Scale DiminishedHalfTone;
        static const Scale Messiaen4thMode;
    };
} // namespace gdmusickit

#endif // GDMUSICKIT_SCALE_HPP

/*
"categories" : [
                  "Basic"
                  ],
  "degrees" : [
               0,
               2,
               4,
               5,
               7,
               9,
               11,
               12
               ],
  "intervals" : [
                 2,
                 2,
                 1,
                 2,
                 2,
                 2,
                 1
                 ],
  "name" : "Major",
  "spelling" : "1 2 3 4 5 6 7"
  },
  {
  "information" : "",
  "descendingIntervals" : [

  ],
*/