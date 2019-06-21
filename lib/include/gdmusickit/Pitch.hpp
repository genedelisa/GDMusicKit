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
#include <iostream>

// gene's music kit

/**
 * @brief A namespace containing Gene's frobs.
 *
 * Right now it contains just the **Account** class.
 *
 * @author Gene De Lisa <gene@rockhoppertech.com>
 */
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
      public:
        /**
         * @brief The ctor.
         *
         */
        Pitch(int midiNumber);

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
        Pitch(std::wstring pitchString);

        int midiPitchNumber();
        int pitchClass();
        int octave();

        static double midiEqualTemperamentFrequency(int midiNumber);
        inline static int octaveForMiddleC = 5;

        friend std::ostream& operator<<(std::ostream& out, const Pitch& pitch);

      protected:
      private:
        int midiNumber{0};
        double frequency{0};

        // pitchbend? cents? spelling?
    };

} // namespace gdmusickit
