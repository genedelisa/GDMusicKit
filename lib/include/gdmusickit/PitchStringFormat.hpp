#ifndef GDMUSICKIT_PITCHSTRINGFORMAT_HPP
#define GDMUSICKIT_PITCHSTRINGFORMAT_HPP

#pragma once

#include "Pitch.hpp"
#include <map>
#include <string>

namespace gdmusickit {

    // PitchStringFormat::getSharedInstance().stringFromMIDINumber(60);
    class PitchStringFormat {
      public:
        static PitchStringFormat& getSharedInstance() {
            static PitchStringFormat instance;
            return instance;
        }
        enum class Spelling : int { sharp = 0, flat = 1, solfege = 2 };
        enum class Justification : int { left = 0, center = 1, right = 2 };

        std::string stringFromMIDINumber(
            int midiNumber,
            PitchStringFormat::Spelling spelling = Spelling::flat,
            PitchStringFormat::Justification justification =
                Justification::left,
            bool includeOctave = true);

            void setWidth(int w) {
                width = w;
            }

      protected:
      private:
        int width{3};

        std::map<int, std::string> sharpPitches = {
            std::make_pair(0, "C"),   std::make_pair(1, "C#"),
            std::make_pair(2, "D"),   std::make_pair(3, "D#"),
            std::make_pair(4, "E"),   std::make_pair(5, "F"),
            std::make_pair(6, "F#"),  std::make_pair(7, "G"),
            std::make_pair(8, "G#"),  std::make_pair(9, "A"),
            std::make_pair(10, "A#"), std::make_pair(11, "B")};

        std::map<int, std::string> flatPitches = {
            std::make_pair(0, "C"),   std::make_pair(1, "Db"),
            std::make_pair(2, "D"),   std::make_pair(3, "Eb"),
            std::make_pair(4, "E"),   std::make_pair(5, "F"),
            std::make_pair(6, "Gb"),  std::make_pair(7, "G"),
            std::make_pair(8, "Ab"),  std::make_pair(9, "A"),
            std::make_pair(10, "Bb"), std::make_pair(11, "B")};


        std::map<int, std::string> solfegePitches = {
            std::make_pair(0, "do"),   std::make_pair(1, "di"),
            std::make_pair(2, "re"),   std::make_pair(3, "ri"),
            std::make_pair(4, "mi"),   std::make_pair(5, "fa"),
            std::make_pair(6, "fi"),  std::make_pair(7, "sol"),
            std::make_pair(8, "si"),  std::make_pair(9, "la"),
            std::make_pair(10, "li"), std::make_pair(11, "ti")};

        // do di re ri mi fa fi sol si la li ti do
        // but descending: do ti te la le sol se fa mi me re ra do
    };

} // namespace gdmusickit
#endif
