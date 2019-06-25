#pragma once

#include "Pitch.hpp"
#include <map>
#include <string>

namespace gdmusickit {

//PitchStringFormat::getSharedInstance().stringFromMIDINumber(60);
    class PitchStringFormat {
      public:
       static PitchStringFormat& getSharedInstance() {
            static PitchStringFormat instance;
            return instance;
        }
        enum class Spelling : int { sharp = 0, flat = 1 };
        enum class Justification : int { left = 0, center = 1, right = 2 };

        std::string stringFromMIDINumber(
            int midiNumber, PitchStringFormat::Spelling spelling,
            PitchStringFormat::Justification justification, bool includeOctave);

      protected:
      private:
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
    };

} // namespace gdmusickit