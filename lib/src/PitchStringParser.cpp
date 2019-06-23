
#include "gdmusickit/PitchStringParser.hpp"
#include "gdmusickit/Pitch.hpp"
#include "gdmusickit/PitchFactory.hpp"

#include <iostream>
#include <regex>
#include <string>

namespace gdmusickit {

    int PitchStringParser::stringToMidiNumber(std::string pitchString) {
        
        //"([a-gA-G]+[b|#]?)([0-9]*)";
        std::cout << "input string: '" << pitchString << "'" << std::endl;
        std::regex r(PitchStringParser::pitchPattern);
        std::smatch m;
        if (std::regex_search(pitchString, m, r)) {
            auto pitch = m.str(1);
            auto octave = m.str(2);
            if(octave.empty()) {
                std::cout << "no octave" << std::endl;
            }
            std::cout << "s1 " << m.str(1) << std::endl;
            std::cout << "s2 " << m.str(2) << std::endl;
            for (auto v : m) {
                std::cout << v << std::endl;
            }
        }

        return 0;
    }

} // namespace gdmusickit