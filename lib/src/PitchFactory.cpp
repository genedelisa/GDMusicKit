#include "gdmusickit/PitchFactory.hpp"
#include "gdmusickit/Pitch.hpp"

#include <cmath>
#include <iostream>

// gene's music kit
namespace gdmusickit {

    Pitch PitchFactory::getPitch(int midiNumber) {
        // std::cout << "PitchFactory::getPitch() " << midiNumber << std::endl;
        auto p = pitchMap.get(); 
        Pitch pitch = p->at(midiNumber);
        std::cout << "pitch from map " << pitch << std::endl;
        return pitch;

        //return Pitch(midiNumber);
    }

} // namespace gdmusickit
