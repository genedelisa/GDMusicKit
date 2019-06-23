#include "gdmusickit/PitchFactory.hpp"
#include "gdmusickit/Pitch.hpp"

#include <cmath>
#include <iostream>

// gene's music kit
namespace gdmusickit {

    Pitch PitchFactory::getPitch(int midiNumber) {
        // std::cout << "PitchFactory::getPitch() " << midiNumber << std::endl;
        
        // get the pointer to the map
        auto map = pitchMap.get();
        if (map->count(midiNumber) == 0) {
            std::cout << midiNumber << " is not in the map" << std::endl;
            // todo: update this to lazy init
        }
        Pitch pitch = map->at(midiNumber);
        //Pitch p = map[midiNumber];
        std::cout << "pitch from map " << pitch << std::endl;
        return pitch;

        // return Pitch(midiNumber);
    }

} // namespace gdmusickit
