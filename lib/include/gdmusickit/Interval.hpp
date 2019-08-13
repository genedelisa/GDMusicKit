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

        enum Quality { diminished, perfect, minor, major, augmented };

        friend std::ostream& operator<<(std::ostream& os, const Interval& interval);

        friend auto operator==(Interval lhs, Interval rhs) {
            return rhs.semitones == lhs.semitones;
        }

        friend auto operator!=(Interval lhs, Interval rhs) {
            return rhs.semitones != lhs.semitones;
        }

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

        Interval(std::string name, Quality q, int d, int s)
            : name(name), quality(q), degree(d), semitones(s) {}

        
        [[nodiscard]] Quality getQuality() const { return quality; }

        [[nodiscard]] int getDegree() const { return degree; }

        [[nodiscard]] int getSemitones() const { return semitones; }

      private:

        std::string name;

        Quality quality;

        /**
         * @brief Diatonic degree.
         * C is 0, G is 5.
         */
        int degree;
        /**
         * @brief The number of semitones in the Interval.
         * 
         */
        int semitones;

      public:

        static const Interval P1;

        static const Interval P4;

        static const Interval P5;

        static const Interval P8;

        static const Interval P11;

        static const Interval P12;

        static const Interval P15;

        static const Interval m2;

        static const Interval m3;

        static const Interval m6;

        static const Interval m7;

        static const Interval m9;

        static const Interval m10;

        static const Interval m13;

        static const Interval m14;

        static const Interval M2;

        static const Interval M3;

        static const Interval M6;

        static const Interval M7;

        static const Interval M9;

        static const Interval M10;

        static const Interval M13;

        static const Interval M14;

        static const Interval d1;

        static const Interval d2;

        static const Interval d3;

        static const Interval d4;

        static const Interval d5;

        static const Interval d6;

        static const Interval d7;

        static const Interval d8;

        static const Interval d9;

        static const Interval d10;

        static const Interval d11;

        static const Interval d12;

        static const Interval d13;

        static const Interval d14;

        static const Interval d15;

        static const Interval A1;

        static const Interval A2;

        static const Interval A3;

        static const Interval A4;

        static const Interval A5;

        static const Interval A6;

        static const Interval A7;

        static const Interval A8;

        static const Interval A9;

        static const Interval A10;

        static const Interval A11;

        static const Interval A12;

        static const Interval A13;

        static const Interval A14;

        static const Interval A15;
    };
} // namespace gdmusickit

#endif // GDMUSICKIT_INTERVAL_HPP