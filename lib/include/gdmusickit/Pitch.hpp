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

//class Pitch;
//#include "PitchFactory.hpp"
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
         * @brief The ctor.
         *
         */
        explicit Pitch(int midiNumber);

        /**
         * @brief Create a Pitch with a MIDI pitch number.
         *
         *
         * ## Typical usage:
         *
         * @code
         * Pitch* account = new Pitch(60);
         * @endcode
         *
         * @param pitchString wstring. A string to be parsed into a midi number.
         * @returns nothing.
         *
         *  @todo Fix this I think. Maybe not.
         */
        explicit Pitch(const std::wstring& pitchString);
        //Pitch(const Pitch &) = delete;
        //Pitch(Pitch &&) = delete;

        [[nodiscard]] int midiPitchNumber() const;
        
        [[nodiscard]] int pitchClass() const; /**< midinumber mod 12 */

        [[nodiscard]] int octave() const;

        static double midiEqualTemperamentFrequency(int midiNumber);

        inline static int octaveForMiddleC = 5;

        static int octaveAdjustment(int fromDefault) {
            auto offset = 5 - octaveForMiddleC;
            return ((5 + offset + fromDefault) * 12);
        }





        // static Pitch A5;
        // inline static const int sValue = 777;

        //static Pitch A5{Pitch(69)}
        //  static const Pitch A5 =
        //     PitchFactory::getSharedInstance().getPitch(
        //         9 + Pitch::octaveAdjustment(0));

      protected:
      private:
        int midiNumber{0}; /* 0 to 127 */
        double frequency{0};

        // pitchbend? cents? spelling?
    }; // namespace gdmusickit

} // namespace gdmusickit

#endif
