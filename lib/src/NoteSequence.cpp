// -*- C++ -*-

#include "gdmusickit/NoteSequence.hpp"
#include "gdmusickit/Pitch.hpp"
#include "gdmusickit/PitchFactory.hpp"

#include <algorithm>
#include <charconv> // from_char, to_char
#include <exception>
#include <iostream>
#include <regex>
#include <string>
#include "Logging.hpp"

namespace gdmusickit {

    //  NoteSequence::NoteSequence() noexcept {
    //     notes = std::make_unique<std::vector<Note>>();
    // }
    void NoteSequence::clear() { this->notes.get()->clear(); }
    
    Note& NoteSequence::addNote(const std::string& pitch, double startBeat, double duration) {
        //Note note{pitch, startBeat, duration};
        auto sp = std::make_unique<Note>(pitch, startBeat, duration);
        auto note = sp.get();
        notes->emplace_back(*note);
        return *(note);
    }

    void NoteSequence::addNote(Note& note) { 
        notes->emplace_back(note); }
    void NoteSequence::removeNote(Note& note) {
        // https://en.wikipedia.org/wiki/Erase–remove_idiom
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

    std::vector<Note> NoteSequence::search(std::function<bool(Note)> ifFun) {
        std::vector<Note>* v = notes.get();
        std::vector<Note> results;
        const std::vector<Note>::const_iterator result =
            std::find_if(v->begin(), v->end(), ifFun);

        if (result != v->end()) {
            LOG_INFO << "find of results" << std::endl;
            for (auto p = result; p != v->end(); p++) {
                LOG_INFO << *p << std::endl;
                results.emplace_back(*p);
            }
        }
        
        // results will be moved.
        // Section 12.8 of n3337 standard draft (C++11)
        // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3337.pdf

        return results;
    }

    // std::vector<Note> NoteSequence::search() {
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