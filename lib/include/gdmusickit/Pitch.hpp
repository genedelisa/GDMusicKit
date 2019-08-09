// -*- C++ -*-
/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License. 
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/


#ifndef GDMUSICKIT_PITCH_HPP
#define GDMUSICKIT_PITCH_HPP

/**
* @file Pitch.hpp
* @author Gene De Lisa <gene@rockhoppertech.com>
* @version 1.0 6/21/19
*
* @section LICENSE
* Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
*
* Licensed under the MIT License.

* See LICENSE in the project for license information.
*
* @section DESCRIPTION
* The Pitch class represents a pitch. :)
*
* @todo clean this up
* @todo the sections above look far to big in the output.
*/
#pragma once

// class Pitch;
//#include "PitchFactory.hpp"
// nope. cant include

#include <iostream>

// gene's music kit

namespace gdmusickit {

    // http://www.doxygen.nl/manual/faq.html#faq_code_inc

    /** @class Pitch Pitch.hpp "Pitch.hpp"
     *
     *
     * @brief This is a Pitch class.
     *
     * A representation of a music Pitch.
     * Nothing exciting.
     *
     * ## Usage:
     *
     *  @code
     *  std::unique_ptr<Pitch> up = std::make_unique<Pitch>(60);
     *  std::cout << "up:" << up << std::endl;
     *  @endcode
     *
     * @note Use the PitchFactory directly.
     */
    class Pitch {

        friend std::ostream& operator<<(std::ostream& os, const Pitch& pitch);

        friend auto operator==(Pitch lhs, Pitch rhs) {
            return rhs.midiNumber == lhs.midiNumber;
        }

        friend auto operator!=(Pitch lhs, Pitch rhs) {
            return rhs.midiNumber != lhs.midiNumber;
        }

      public:
        /**
         * @brief the Constructor.
         * @details Create a Pitch with a MIDI pitch number.
         */
        explicit Pitch(int midiNumber);

        /**
         * @brief Create a Pitch with a MIDI pitch number.
         *
         *
         * ## Typical usage:
         *
         * @code
         * Pitch* p = new Pitch(60);
         * @endcode
         *
         * @param pitchString wstring. A string to be parsed into a midi number.
         * @returns nothing.
         *
         * @todo Fix this I think. Maybe not.
         */
        explicit Pitch(const std::string& pitchString);

        // copy constructor
        // Pitch(const Pitch&) = delete;
        // move constructor
        // Pitch(Pitch&&) = delete;

        [[nodiscard]] int midiPitchNumber() const;

        [[nodiscard]] int pitchClass() const; /**< midinumber mod 12 */

        [[nodiscard]] int octave() const;

        static double midiEqualTemperamentFrequency(int midiNumber);

        inline static int octaveForMiddleC = 5;

        static int octaveAdjustment(int fromDefault) {
            auto offset = 5 - octaveForMiddleC;
            return ((5 + offset + fromDefault) * 12);
        }

        // inline static const Pitch* C0 =
        //     PitchFactory::getSharedInstance().getPitch(
        //         0 + Pitch::octaveAdjustment(-5));

        // static Pitch A5;
        // inline static const int sValue = 777;

        // static Pitch A5{Pitch(69)}
        //  static const Pitch A5 =
        //     PitchFactory::getSharedInstance().getPitch(
        //         9 + Pitch::octaveAdjustment(0));

      protected:
      private:
        int midiNumber{0}; /* 0 to 127 */
        double frequency{0};

        // pitchbend? cents? spelling?

      public:
        /**
         * @brief A constant
         * @bug this doesn't fucking work
         */

        // NOLINTNEXTLINE(readability-identifier-naming)
        static const Pitch* C0;
        static const Pitch* CS0; // NOLINT(readability-identifier-naming)
        static const Pitch* Db0; // NOLINT(readability-identifier-naming)
        static const Pitch* D0; // NOLINT(readability-identifier-naming)
        static const Pitch* DS0; // NOLINT(readability-identifier-naming)
        static const Pitch* Eb0; // NOLINT(readability-identifier-naming)
        static const Pitch* E0; // NOLINT(readability-identifier-naming)
        static const Pitch* F0; // NOLINT(readability-identifier-naming)
        static const Pitch* FS0; // NOLINT(readability-identifier-naming)
        static const Pitch* Gb0; // NOLINT(readability-identifier-naming)
        static const Pitch* G0; // NOLINT(readability-identifier-naming)
        static const Pitch* GS0; // NOLINT(readability-identifier-naming)
        static const Pitch* Ab0; // NOLINT(readability-identifier-naming)
        static const Pitch* A0; // NOLINT(readability-identifier-naming)
        static const Pitch* AS0; // NOLINT(readability-identifier-naming)
        static const Pitch* Bb0; // NOLINT(readability-identifier-naming)
        static const Pitch* B0; // NOLINT(readability-identifier-naming)
        static const Pitch* C1; // NOLINT(readability-identifier-naming)
        static const Pitch* CS1; // NOLINT(readability-identifier-naming)
        static const Pitch* Db1; // NOLINT(readability-identifier-naming)
        static const Pitch* D1; // NOLINT(readability-identifier-naming)
        static const Pitch* DS1; // NOLINT(readability-identifier-naming)
        static const Pitch* Eb1; // NOLINT(readability-identifier-naming)
        static const Pitch* E1; // NOLINT(readability-identifier-naming)
        static const Pitch* F1; // NOLINT(readability-identifier-naming)
        static const Pitch* FS1; // NOLINT(readability-identifier-naming)
        static const Pitch* Gb1; // NOLINT(readability-identifier-naming)
        static const Pitch* G1; // NOLINT(readability-identifier-naming)
        static const Pitch* GS1; // NOLINT(readability-identifier-naming)
        static const Pitch* Ab1; // NOLINT(readability-identifier-naming)
        static const Pitch* A1; // NOLINT(readability-identifier-naming)
        static const Pitch* AS1; // NOLINT(readability-identifier-naming)
        static const Pitch* Bb1; // NOLINT(readability-identifier-naming)
        static const Pitch* B1; // NOLINT(readability-identifier-naming)
        static const Pitch* C2; // NOLINT(readability-identifier-naming)
        static const Pitch* CS2; // NOLINT(readability-identifier-naming)
        static const Pitch* Db2; // NOLINT(readability-identifier-naming)
        static const Pitch* D2; // NOLINT(readability-identifier-naming)
        static const Pitch* DS2; // NOLINT(readability-identifier-naming)
        static const Pitch* Eb2; // NOLINT(readability-identifier-naming)
        static const Pitch* E2; // NOLINT(readability-identifier-naming)
        static const Pitch* F2; // NOLINT(readability-identifier-naming)
        static const Pitch* FS2; // NOLINT(readability-identifier-naming)
        static const Pitch* Gb2; // NOLINT(readability-identifier-naming)
        static const Pitch* G2; // NOLINT(readability-identifier-naming)
        static const Pitch* GS2; // NOLINT(readability-identifier-naming)
        static const Pitch* Ab2; // NOLINT(readability-identifier-naming)
        static const Pitch* A2; // NOLINT(readability-identifier-naming)
        static const Pitch* AS2; // NOLINT(readability-identifier-naming)
        static const Pitch* Bb2; // NOLINT(readability-identifier-naming)
        static const Pitch* B2; // NOLINT(readability-identifier-naming)
        static const Pitch* C3; // NOLINT(readability-identifier-naming)
        static const Pitch* CS3; // NOLINT(readability-identifier-naming)
        static const Pitch* Db3; // NOLINT(readability-identifier-naming)
        static const Pitch* D3; // NOLINT(readability-identifier-naming)
        static const Pitch* DS3; // NOLINT(readability-identifier-naming)
        static const Pitch* Eb3; // NOLINT(readability-identifier-naming)
        static const Pitch* E3; // NOLINT(readability-identifier-naming)
        static const Pitch* F3; // NOLINT(readability-identifier-naming)
        static const Pitch* FS3; // NOLINT(readability-identifier-naming)
        static const Pitch* Gb3; // NOLINT(readability-identifier-naming)
        static const Pitch* G3; // NOLINT(readability-identifier-naming)
        static const Pitch* GS3; // NOLINT(readability-identifier-naming)
        static const Pitch* Ab3; // NOLINT(readability-identifier-naming)
        static const Pitch* A3; // NOLINT(readability-identifier-naming)
        static const Pitch* AS3; // NOLINT(readability-identifier-naming)
        static const Pitch* Bb3; // NOLINT(readability-identifier-naming)
        static const Pitch* B3; // NOLINT(readability-identifier-naming)
        static const Pitch* C4; // NOLINT(readability-identifier-naming)
        static const Pitch* CS4; // NOLINT(readability-identifier-naming)
        static const Pitch* Db4; // NOLINT(readability-identifier-naming)
        static const Pitch* D4; // NOLINT(readability-identifier-naming)
        static const Pitch* DS4; // NOLINT(readability-identifier-naming)
        static const Pitch* Eb4; // NOLINT(readability-identifier-naming)
        static const Pitch* E4; // NOLINT(readability-identifier-naming)
        static const Pitch* F4; // NOLINT(readability-identifier-naming)
        static const Pitch* FS4; // NOLINT(readability-identifier-naming)
        static const Pitch* Gb4; // NOLINT(readability-identifier-naming)
        static const Pitch* G4; // NOLINT(readability-identifier-naming)
        static const Pitch* GS4; // NOLINT(readability-identifier-naming)
        static const Pitch* Ab4; // NOLINT(readability-identifier-naming)
        static const Pitch* A4; // NOLINT(readability-identifier-naming)
        static const Pitch* AS4; // NOLINT(readability-identifier-naming)
        static const Pitch* Bb4; // NOLINT(readability-identifier-naming)
        static const Pitch* B4; // NOLINT(readability-identifier-naming)
        static const Pitch* C5; // NOLINT(readability-identifier-naming)
        static const Pitch* CS5; // NOLINT(readability-identifier-naming)
        static const Pitch* Db5; // NOLINT(readability-identifier-naming)
        static const Pitch* D5; // NOLINT(readability-identifier-naming)
        static const Pitch* DS5; // NOLINT(readability-identifier-naming)
        static const Pitch* Eb5; // NOLINT(readability-identifier-naming)
        static const Pitch* E5; // NOLINT(readability-identifier-naming)
        static const Pitch* F5; // NOLINT(readability-identifier-naming)
        static const Pitch* FS5; // NOLINT(readability-identifier-naming)
        static const Pitch* Gb5; // NOLINT(readability-identifier-naming)
        static const Pitch* G5; // NOLINT(readability-identifier-naming)
        static const Pitch* GS5; // NOLINT(readability-identifier-naming)
        static const Pitch* Ab5; // NOLINT(readability-identifier-naming)
        static const Pitch* A5; // NOLINT(readability-identifier-naming)
        static const Pitch* AS5; // NOLINT(readability-identifier-naming)
        static const Pitch* Bb5; // NOLINT(readability-identifier-naming)
        static const Pitch* B5; // NOLINT(readability-identifier-naming)
        static const Pitch* C6; // NOLINT(readability-identifier-naming)
        static const Pitch* CS6; // NOLINT(readability-identifier-naming)
        static const Pitch* Db6; // NOLINT(readability-identifier-naming)
        static const Pitch* D6; // NOLINT(readability-identifier-naming)
        static const Pitch* DS6; // NOLINT(readability-identifier-naming)
        static const Pitch* Eb6; // NOLINT(readability-identifier-naming)
        static const Pitch* E6; // NOLINT(readability-identifier-naming)
        static const Pitch* F6; // NOLINT(readability-identifier-naming)
        static const Pitch* FS6; // NOLINT(readability-identifier-naming)
        static const Pitch* Gb6; // NOLINT(readability-identifier-naming)
        static const Pitch* G6; // NOLINT(readability-identifier-naming)
        static const Pitch* GS6; // NOLINT(readability-identifier-naming)
        static const Pitch* Ab6; // NOLINT(readability-identifier-naming)
        static const Pitch* A6; // NOLINT(readability-identifier-naming)
        static const Pitch* AS6; // NOLINT(readability-identifier-naming)
        static const Pitch* Bb6; // NOLINT(readability-identifier-naming)
        static const Pitch* B6; // NOLINT(readability-identifier-naming)
        static const Pitch* C7; // NOLINT(readability-identifier-naming)
        static const Pitch* CS7; // NOLINT(readability-identifier-naming)
        static const Pitch* Db7; // NOLINT(readability-identifier-naming)
        static const Pitch* D7; // NOLINT(readability-identifier-naming)
        static const Pitch* DS7; // NOLINT(readability-identifier-naming)
        static const Pitch* Eb7; // NOLINT(readability-identifier-naming)
        static const Pitch* E7; // NOLINT(readability-identifier-naming)
        static const Pitch* F7; // NOLINT(readability-identifier-naming)
        static const Pitch* FS7; // NOLINT(readability-identifier-naming)
        static const Pitch* Gb7; // NOLINT(readability-identifier-naming)
        static const Pitch* G7; // NOLINT(readability-identifier-naming)
        static const Pitch* GS7; // NOLINT(readability-identifier-naming)
        static const Pitch* Ab7; // NOLINT(readability-identifier-naming)
        static const Pitch* A7; // NOLINT(readability-identifier-naming)
        static const Pitch* AS7; // NOLINT(readability-identifier-naming)
        static const Pitch* Bb7; // NOLINT(readability-identifier-naming)
        static const Pitch* B7; // NOLINT(readability-identifier-naming)
        static const Pitch* C8; // NOLINT(readability-identifier-naming)
        static const Pitch* CS8; // NOLINT(readability-identifier-naming)
        static const Pitch* Db8; // NOLINT(readability-identifier-naming)
        static const Pitch* D8; // NOLINT(readability-identifier-naming)
        static const Pitch* DS8; // NOLINT(readability-identifier-naming)
        static const Pitch* Eb8; // NOLINT(readability-identifier-naming)
        static const Pitch* E8; // NOLINT(readability-identifier-naming)
        static const Pitch* F8; // NOLINT(readability-identifier-naming)
        static const Pitch* FS8; // NOLINT(readability-identifier-naming)
        static const Pitch* Gb8; // NOLINT(readability-identifier-naming)
        static const Pitch* G8; // NOLINT(readability-identifier-naming)
        static const Pitch* GS8; // NOLINT(readability-identifier-naming)
        static const Pitch* Ab8; // NOLINT(readability-identifier-naming)
        static const Pitch* A8; // NOLINT(readability-identifier-naming)
        static const Pitch* AS8; // NOLINT(readability-identifier-naming)
        static const Pitch* Bb8; // NOLINT(readability-identifier-naming)
        static const Pitch* B8; // NOLINT(readability-identifier-naming)
        static const Pitch* C9; // NOLINT(readability-identifier-naming)
        static const Pitch* CS9; // NOLINT(readability-identifier-naming)
        static const Pitch* Db9; // NOLINT(readability-identifier-naming)
        static const Pitch* D9; // NOLINT(readability-identifier-naming)
        static const Pitch* DS9; // NOLINT(readability-identifier-naming)
        static const Pitch* Eb9; // NOLINT(readability-identifier-naming)
        static const Pitch* E9; // NOLINT(readability-identifier-naming)
        static const Pitch* F9; // NOLINT(readability-identifier-naming)
        static const Pitch* FS9; // NOLINT(readability-identifier-naming)
        static const Pitch* Gb9; // NOLINT(readability-identifier-naming)
        static const Pitch* G9; // NOLINT(readability-identifier-naming)
        static const Pitch* GS9; // NOLINT(readability-identifier-naming)
        static const Pitch* Ab9; // NOLINT(readability-identifier-naming)
        static const Pitch* A9; // NOLINT(readability-identifier-naming)
        static const Pitch* AS9; // NOLINT(readability-identifier-naming)
        static const Pitch* Bb9; // NOLINT(readability-identifier-naming)
        static const Pitch* B9; // NOLINT(readability-identifier-naming)
        static const Pitch* C10; // NOLINT(readability-identifier-naming)
        static const Pitch* CS10; // NOLINT(readability-identifier-naming)
        static const Pitch* Db10; // NOLINT(readability-identifier-naming)
        static const Pitch* D10; // NOLINT(readability-identifier-naming)
        static const Pitch* DS10; // NOLINT(readability-identifier-naming)
        static const Pitch* Eb10; // NOLINT(readability-identifier-naming)
        static const Pitch* E10; // NOLINT(readability-identifier-naming)
        static const Pitch* F10; // NOLINT(readability-identifier-naming)
        static const Pitch* FS10; // NOLINT(readability-identifier-naming)
        static const Pitch* Gb10; // NOLINT(readability-identifier-naming)
        static const Pitch* G10; // NOLINT(readability-identifier-naming)
    }; // namespace gdmusickit

} // namespace gdmusickit

#endif
