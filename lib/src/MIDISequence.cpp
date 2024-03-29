// -*- C++ -*-
/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License. 
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/



#include <algorithm>
#include <charconv> // from_char, to_char
#include <exception>
#include <iostream>
#include <regex>
#include <string>

#include "gdmusickit/MIDISequence.hpp"
#include "gdmusickit/MIDITrack.hpp"
#include "gdmusickit/Note.hpp"
#include "gdmusickit/Pitch.hpp"
#include "gdmusickit/PitchFactory.hpp"


namespace gdmusickit {

    void MIDISequence::addTrack(MIDITrack& track) {
        tracks.emplace(track.getStartBeat(), track);
    }
    
    size_t MIDISequence::size() const { return tracks.size(); }
    
    void MIDISequence::clear() { this->tracks.clear(); }

    std::ostream& operator<<(std::ostream& os,
                             MIDISequence const& midiSequence) {

        for (const auto& track : midiSequence.tracks) {
            os << track.second << "\n";
        }

        // for (const auto& note : midiTrack.notes) {
        //     os << note.first << " : " << note.second << "\n";
        // }

        return os;
    }

} // namespace gdmusickit