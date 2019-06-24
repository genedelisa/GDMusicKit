#include "gdmusickit/NoteSequence.hpp"
#include "gdmusickit/Pitch.hpp"
#include "gdmusickit/PitchFactory.hpp"

#include <algorithm>
#include <charconv> // from_char, to_char
#include <exception>
#include <iostream>
#include <regex>
#include <string>

namespace gdmusickit {
    //  NoteSequence::NoteSequence() noexcept {
    //     notes = std::make_unique<std::vector<Note>>();
    // }
    
    void NoteSequence::addNote(Note note) { notes->emplace_back(note); }
    
    // std::ostream& operator<<(std::ostream& os,
    //                          NoteSequence const& noteSequence) {
    //     for (note : NoteSequence) {
    //         os << "Pitch: " << note.pitch << " Start " << note.startBeat
    //            << " Duration " << note.duration << "\n";
    //     }

    //     return os;
    // }

} // namespace gdmusickit