// -*- C++ -*-
/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License. 
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/


#include <cmath>
#include <iostream>
#include <memory>
#include <stdexcept>

#include "gdmusickit/PitchFactory.hpp"
#include "gdmusickit/Pitch.hpp"
#include "gdmusickit/PitchStringParser.hpp"
#include "Logging.hpp"

// gene's music kit
namespace gdmusickit {
class Pitch;

    Pitch* PitchFactory::getPitch(std::string pitchString) {
        int n = PitchStringParser::stringToMidiNumber(pitchString);
        return PitchFactory::getSharedInstance().getPitch(n);
    }

    //  Pitch& PitchFactory::getPitch(const int midiNumber) {
    //     // std::cout << "PitchFactory::getPitch() " << midiNumber <<
    //     std::endl;

    //     // get the pointer to the map
    //     auto map = pitchMap.get();
    //     if (map->count(midiNumber) == 0) {
    //         LOG_INFO << midiNumber << " is not in the map" << std::endl;
    //         // todo: update this to lazy init
    //         throw std::invalid_argument("bad midi number");
    //     }
    //     LOG_INFO << "looking up " << midiNumber << " in the map" <<
    //     std::endl;
    //      Pitch& pitch = map->at(midiNumber);
    //     LOG_INFO << "retrieved " << pitch << "\n";
    //     LOG_INFO << "addressof " << std::addressof(pitch) << "\n";
    //     // Pitch p = map[midiNumber];
    //     //std::cout << "pitch from map " << pitch << std::endl;
    //     return pitch;

    //     // return Pitch(midiNumber);
    // }

    // lazily fill the map. Never deleted which is what we want.
    Pitch* PitchFactory::getPitch(const int midiNumber) {
        Pitch* ptr = pitchMap[midiNumber];
        //Pitch* ptr = const_cast<Pitch*>(pitchMap[midiNumber]);

        if (ptr == nullptr) {
            pitchMap[midiNumber] = new Pitch(midiNumber);
            ptr = pitchMap[midiNumber];
        }

        /// @todo. why not cache the constants like this?
        // pitchMap[0] = Pitch::C0;
        // pitchMap[1] = Pitch::CS0;
        // pitchMap[2] = Pitch::D0;
        // pitchMap[3] = Pitch::DS0;
        // pitchMap[4] = Pitch::E0;
        // pitchMap[5] = Pitch::F0;
        // pitchMap[6] = Pitch::FS0;
        // pitchMap[7] = Pitch::G0;
        // pitchMap[8] = Pitch::GS0;
        // pitchMap[9] = Pitch::A0;
        // pitchMap[10] = Pitch::AS0;
        // pitchMap[11] = Pitch::B0;   
                                                                                 

        return ptr;
    }

    // if (it == pitchMap.end()) {
    //     auto p = std::make_shared<Pitch>(n);
    //     pitchMap[n] = p;
    //     return p;
    // } else {
    //     return it->second;
    // }

} // namespace gdmusickit
