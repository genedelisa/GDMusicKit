// -*- C++ -*-

/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License.
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/
/** @file Interval.hpp
 *  @brief brief The Interval class.
 *
 *  The Interval
 *
 *  @date date 2019-07-19
 *  @copyright Copyright (c) 2019 Rockhopper Technologies, Inc.
 *  @version 0.1.0
 *  @author Gene De Lisa (gene@rockhoppertech.com)
 *  @bug No known bugs.
 *  @see http://rockhoppertech.com/
 */

#ifndef GDMUSICKIT_INTERVAL_HPP
#define GDMUSICKIT_INTERVAL_HPP

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

    class Interval {
      public:

        // maybe a multimap would be better?
        enum SemiTones {
            unison = 0,
            minorSecond = 1,
            majorSecond = 2,
            minorThird = 3,
            majorThird = 4,
            perfectFourth = 5,
            augmentedFourth = 6,
            perfectFifth = 7,
            minorsixth = 8,
            majorSixth = 9,
            minorSeventh = 10,
            majorSeventh = 11,
            octave = 12,
            minorNinth = 13,
            majorNinth = 14,
            // MINOR_ELEVENTH = 13;
            majorEleventh = 17,
            minorThirteenth = 20,
            majorThirteenth = 21
        };

        enum Quality {
            diminished,
            perfect,
            minor,
            major,
            augmented
        };

        static inline const std::map<std::string, int> intervalNames = {
            std::pair<std::string, int>("Unison", 0),
            std::pair<std::string, int>("Minor Second", 1),
            std::pair<std::string, int>("Major Second", 2),
            std::pair<std::string, int>("Minor Third", 3),
            std::pair<std::string, int>("Major Third", 4),
            std::pair<std::string, int>("Perfect Fourth", 5),
            std::pair<std::string, int>("Tritone", 6),
            std::pair<std::string, int>("Perfect Fifth", 7),
            std::pair<std::string, int>("Minor Sixth", 8),
            std::pair<std::string, int>("Major Sixth", 9),
            std::pair<std::string, int>("Minor Seventh", 10),
            std::pair<std::string, int>("Major Seventh", 11),
            std::pair<std::string, int>("Octave", 12),
            std::pair<std::string, int>("Minor Ninth", 13),
            std::pair<std::string, int>("Major Ninth", 14),
            std::pair<std::string, int>("Minor Tenth", 15),
            std::pair<std::string, int>("Major Tenth", 16),
            std::pair<std::string, int>("Eleventh", 17),
            std::pair<std::string, int>("Augmented Eleventh", 18),
            std::pair<std::string, int>("Minor Thirteenth", 19),
            std::pair<std::string, int>("Major Thirteenth", 20),
            std::pair<std::string, int>("Augmented Thirteenth", 21),
            std::pair<std::string, int>("Minor Seventh + Octave", 22),
            std::pair<std::string, int>("Major Seventh + Octave", 23),
            std::pair<std::string, int>("Two Octaves", 24)};
    

    Interval(Quality q, int d, int s)
        : quality(q), degree(d), semitones(s) {}

    /// Unison.
    //  public static let P1 = Interval(quality: .perfect, degree: 1, semitones:
    //  0)
//    static inline const Interval P1 = Interval(Interval::Quality::perfect, 1, 0);
    static const Interval P1;

  private:
    /// Quality of the interval.
    Quality quality;
    /// Degree of the interval.
    int degree;
    /// Semitones interval affect on a pitch.
    int semitones;
};
} // namespace gdmusickit

#endif // GDMUSICKIT_INTERVAL_HPP