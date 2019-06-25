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
    void NoteSequence::clear() { this->notes.get()->clear(); }
    void NoteSequence::addNote(Note note) { notes->emplace_back(note); }
    void NoteSequence::removeNote(Note note) {
        //https://en.wikipedia.org/wiki/Erase–remove_idiom
        std::vector<Note>* v = notes.get();
        v->erase(std::remove(v->begin(), v->end(), note), v->end());
    }
    std::ostream& operator<<(std::ostream& os,
                             NoteSequence const& noteSequence) {

        for (auto note : noteSequence) {
            os << note << "\n";
        }

        return os;
    }

    size_t NoteSequence::size() const { return notes->size(); }

} // namespace gdmusickit