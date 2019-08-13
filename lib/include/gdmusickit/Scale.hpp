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

        static const Scale                              major;
        static const Scale                              symmetricalDecatonic;
        static const std::map<std::string, const Scale> scaleMap;

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