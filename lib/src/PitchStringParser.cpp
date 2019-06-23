
#include "gdmusickit/PitchStringParser.hpp"
#include "gdmusickit/Pitch.hpp"
#include "gdmusickit/PitchFactory.hpp"

#include <algorithm>
#include <charconv> // from_char, to_char
#include <iostream>
#include <regex>
#include <string>

namespace gdmusickit {

    int PitchStringParser::stringToMidiNumber(std::string pitchString) {
        std::cout << std::endl;
        std::cout << "input string: '" << pitchString << "'" << std::endl;
        // std::regex r("([a-gA-G]{1}[S|F|B|#]?)([0-9]*)");
        std::regex r(PitchStringParser::pitchPattern);
        std::smatch m;

        std::transform(pitchString.begin(), pitchString.end(),
                       pitchString.begin(), ::toupper);
        std::cout << "input string: '" << pitchString << "'" << std::endl;

        if (std::regex_search(pitchString, m, r)) {
            auto pitch = m.str(1);

            auto pitchClass = PitchFactory::pitchClassNames.at(pitch);
            std::cout << "pitch class: " << pitchClass << std::endl;
            // auto pc = PitchFactory::pitchClassNames[pitch];

            auto octave = m.str(2);
            if (octave.empty()) {
                std::cout << "no octave" << std::endl;
            }
            std::cout << "s1 " << m.str(1) << std::endl;
            std::cout << "s2 " << m.str(2) << std::endl;
            for (auto v : m) {
                std::cout << v << std::endl;
            }

            int oct = 0;
            const auto res = std::from_chars(
                octave.data(), octave.data() + octave.size(), oct);

            // need a special case for cf
            int midiNumber = pitchClass + (oct * 12);
            std::cout << "midi number returned: " << midiNumber << std::endl;

            std::cout << std::endl;
            return midiNumber;
        }

        return 0;
    }

} // namespace gdmusickit