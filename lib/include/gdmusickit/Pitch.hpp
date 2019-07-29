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
        explicit Pitch(const std::wstring& pitchString);

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
        static const Pitch* C0;
        static const Pitch* CS0;
        static const Pitch* Db0;
        static const Pitch* D0;
        static const Pitch* DS0;
        static const Pitch* Eb0;
        static const Pitch* E0;
        static const Pitch* F0;
        static const Pitch* FS0;
        static const Pitch* Gb0;
        static const Pitch* G0;
        static const Pitch* GS0;
        static const Pitch* Ab0;
        static const Pitch* A0;
        static const Pitch* AS0;
        static const Pitch* Bb0;
        static const Pitch* B0;
        static const Pitch* C1;
        static const Pitch* CS1;
        static const Pitch* Db1;
        static const Pitch* D1;
        static const Pitch* DS1;
        static const Pitch* Eb1;
        static const Pitch* E1;
        static const Pitch* F1;
        static const Pitch* FS1;
        static const Pitch* Gb1;
        static const Pitch* G1;
        static const Pitch* GS1;
        static const Pitch* Ab1;
        static const Pitch* A1;
        static const Pitch* AS1;
        static const Pitch* Bb1;
        static const Pitch* B1;
        static const Pitch* C2;
        static const Pitch* CS2;
        static const Pitch* Db2;
        static const Pitch* D2;
        static const Pitch* DS2;
        static const Pitch* Eb2;
        static const Pitch* E2;
        static const Pitch* F2;
        static const Pitch* FS2;
        static const Pitch* Gb2;
        static const Pitch* G2;
        static const Pitch* GS2;
        static const Pitch* Ab2;
        static const Pitch* A2;
        static const Pitch* AS2;
        static const Pitch* Bb2;
        static const Pitch* B2;
        static const Pitch* C3;
        static const Pitch* CS3;
        static const Pitch* Db3;
        static const Pitch* D3;
        static const Pitch* DS3;
        static const Pitch* Eb3;
        static const Pitch* E3;
        static const Pitch* F3;
        static const Pitch* FS3;
        static const Pitch* Gb3;
        static const Pitch* G3;
        static const Pitch* GS3;
        static const Pitch* Ab3;
        static const Pitch* A3;
        static const Pitch* AS3;
        static const Pitch* Bb3;
        static const Pitch* B3;
        static const Pitch* C4;
        static const Pitch* CS4;
        static const Pitch* Db4;
        static const Pitch* D4;
        static const Pitch* DS4;
        static const Pitch* Eb4;
        static const Pitch* E4;
        static const Pitch* F4;
        static const Pitch* FS4;
        static const Pitch* Gb4;
        static const Pitch* G4;
        static const Pitch* GS4;
        static const Pitch* Ab4;
        static const Pitch* A4;
        static const Pitch* AS4;
        static const Pitch* Bb4;
        static const Pitch* B4;
        static const Pitch* C5;
        static const Pitch* CS5;
        static const Pitch* Db5;
        static const Pitch* D5;
        static const Pitch* DS5;
        static const Pitch* Eb5;
        static const Pitch* E5;
        static const Pitch* F5;
        static const Pitch* FS5;
        static const Pitch* Gb5;
        static const Pitch* G5;
        static const Pitch* GS5;
        static const Pitch* Ab5;
        static const Pitch* A5;
        static const Pitch* AS5;
        static const Pitch* Bb5;
        static const Pitch* B5;
        static const Pitch* C6;
        static const Pitch* CS6;
        static const Pitch* Db6;
        static const Pitch* D6;
        static const Pitch* DS6;
        static const Pitch* Eb6;
        static const Pitch* E6;
        static const Pitch* F6;
        static const Pitch* FS6;
        static const Pitch* Gb6;
        static const Pitch* G6;
        static const Pitch* GS6;
        static const Pitch* Ab6;
        static const Pitch* A6;
        static const Pitch* AS6;
        static const Pitch* Bb6;
        static const Pitch* B6;
        static const Pitch* C7;
        static const Pitch* CS7;
        static const Pitch* Db7;
        static const Pitch* D7;
        static const Pitch* DS7;
        static const Pitch* Eb7;
        static const Pitch* E7;
        static const Pitch* F7;
        static const Pitch* FS7;
        static const Pitch* Gb7;
        static const Pitch* G7;
        static const Pitch* GS7;
        static const Pitch* Ab7;
        static const Pitch* A7;
        static const Pitch* AS7;
        static const Pitch* Bb7;
        static const Pitch* B7;
        static const Pitch* C8;
        static const Pitch* CS8;
        static const Pitch* Db8;
        static const Pitch* D8;
        static const Pitch* DS8;
        static const Pitch* Eb8;
        static const Pitch* E8;
        static const Pitch* F8;
        static const Pitch* FS8;
        static const Pitch* Gb8;
        static const Pitch* G8;
        static const Pitch* GS8;
        static const Pitch* Ab8;
        static const Pitch* A8;
        static const Pitch* AS8;
        static const Pitch* Bb8;
        static const Pitch* B8;
        static const Pitch* C9;
        static const Pitch* CS9;
        static const Pitch* Db9;
        static const Pitch* D9;
        static const Pitch* DS9;
        static const Pitch* Eb9;
        static const Pitch* E9;
        static const Pitch* F9;
        static const Pitch* FS9;
        static const Pitch* Gb9;
        static const Pitch* G9;
        static const Pitch* GS9;
        static const Pitch* Ab9;
        static const Pitch* A9;
        static const Pitch* AS9;
        static const Pitch* Bb9;
        static const Pitch* B9;
        static const Pitch* C10;
        static const Pitch* CS10;
        static const Pitch* Db10;
        static const Pitch* D10;
        static const Pitch* DS10;
        static const Pitch* Eb10;
        static const Pitch* E10;
        static const Pitch* F10;
        static const Pitch* FS10;
        static const Pitch* Gb10;
        static const Pitch* G10;
    }; // namespace gdmusickit

} // namespace gdmusickit

#endif
