#include "gdmusickit/MIDITrack.hpp"
#include "gdmusickit/Note.hpp"
#include "gdmusickit/Pitch.hpp"
#include "gdmusickit/PitchFactory.hpp"

#include <algorithm>
#include <charconv> // from_char, to_char
#include <exception>
#include <iostream>
#include <regex>
#include <string>

namespace gdmusickit {

    MIDITrack::MIDITrack(double startBeat) { this->startBeat = startBeat; }

    //  MIDITrack::MIDITrack(ı) noexcept {
    //     notes = std::make_unique<std::vector<Note>>();
    // }
    void MIDITrack::clear() { this->notes.clear(); }

    void MIDITrack::addNote(Note note) {
        notes.emplace(note.getStartBeat(), note);
    }

    void MIDITrack::removeNote(Note note) {
        for (auto it = notes.begin(); it != notes.end();) {
            it = notes.erase(it);
        }

        // https://en.wikipedia.org/wiki/Erase–remove_idiom
        // std::vector<Note>* v = notes.get();
        // notes.erase(std::remove(notes.begin(), notes.end(), note),
        // notes.end());
    }

    std::ostream& operator<<(std::ostream& os, MIDITrack const& MIDITrack) {

        for (const auto& note : MIDITrack.notes) {
            os << note.first << " : " << note.second << "\n";
        }

        return os;
    }

    size_t MIDITrack::size() const { return notes.size(); }

    // std::vector<Note> MIDITrack::search() {
    //     std::vector<Note>* v = notes.get();

    //     std::vector<Note> results;

    //     std::function<Note(Note)> f1 = [](Note n) { return n; };

    //     std::function<bool(Note)> ifFun = [](Note n) {
    //         return n.getStartBeat() >= 2;
    //     };

    //     const std::vector<Note>::const_iterator result =
    //         std::find_if(v->begin(), v->end(), ifFun);

    //     // lambda right here
    //     const std::vector<Note>::const_iterator result2 = find_if(
    //         v->begin(), v->end(), [](Note n) { return n.getStartBeat() >= 2;
    //         });

    //     if (result != v->end()) {
    //         std::cout << "find of results" << std::endl;
    //         for (auto p = result; p != v->end(); p++) {
    //             std::cout << *p << std::endl;
    //             results.emplace_back(*p);
    //         }
    //     }

    //     // results will be moved.
    //     // Section 12.8 of n3337 standard draft (C++11)
    //     // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3337.pdf

    //     return results;
    // }
} // namespace gdmusickit