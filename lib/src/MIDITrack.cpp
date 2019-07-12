#include "gdmusickit/MIDITrack.hpp"
#include "gdmusickit/Note.hpp"
#include "gdmusickit/Pitch.hpp"
#include "gdmusickit/PitchFactory.hpp"

#include "Logging.hpp"
#include "gdmusickit/MacMIDI.hpp"

#include <algorithm>
#include <charconv> // from_char, to_char
#include <exception>
#include <iostream>
#include <map>
#include <regex>
#include <stdexcept>
#include <string>

namespace gdmusickit {

    MIDITrack::MIDITrack(double startBeat) { this->startBeat = startBeat; }

    //  MIDITrack::MIDITrack(ı) noexcept {
    //     notes = std::make_unique<std::vector<Note>>();
    // }
    void MIDITrack::clear() { this->notes.clear(); }

    void MIDITrack::addNote(Note note) {
        notes.emplace(note.getStartBeat(), note);

        // MIDIPacketList pktlist{0};
        // auto packet = MIDIPacketListInit(&pktlist);
        // auto p = MIDIPacketListAdd(&pktlist, ByteCount listSize,
        // MIDIPacket *curPacket, MIDITimeStamp time,
        // ByteCount nData,
        // const Byte *data);
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

    std::multimap<double, Note> MIDITrack::subset(int from, int to) {
        std::multimap<double, Note> resultMap;

        auto rangeStart = notes.find(from);
        auto rangeEnd = notes.find(to);
        //        auto range_end = notes.end();
        resultMap.insert(rangeStart, rangeEnd);

        // std::copy_if(begin(notes), end(notes),
        //              std::inserter(resultMap, begin(resultMap)),
        //              [&from](std::pair<int, int> p) {
        //                  return p.first >= from;
        //              });

        return resultMap;
    }

    std::ostream& operator<<(std::ostream& os, MIDITrack const& midiTrack) {

        for (const auto& note : midiTrack.notes) {
            os << note.first << " : " << note.second << "\n";
        }

        return os;
    }

    size_t MIDITrack::size() const { return notes.size(); }

    void MIDITrack::changeStartBeat(double toBeat) {

        if (toBeat < 1.0) {
            throw std::invalid_argument("bad start beat");
            // log.error("beat is < 1. wtf?")
            return;
        }
        LOG_INFO << "changing to startBeat: " << toBeat << "\n";

        //auto firstNote = notes.find(1)->second;
        auto firstNote = notes.begin()->second;
        LOG_INFO << "firstNote: " << firstNote << "\n";

        double now = firstNote.getStartBeat();
        LOG_INFO << "now: " << now << "\n";

        double diff = now - toBeat;
        LOG_INFO << "diff: " << diff << "\n";
        for (auto& [sb, note] : notes) {

            double newstart = sb - diff;

//            double newstart = note.getStartBeat() - diff;
            LOG_INFO << "New start " << newstart << "\n";

            auto nodeHandler = notes.extract(sb);
            nodeHandler.key() = newstart;
            note.setStartBeat(newstart);
            notes.insert(std::move(nodeHandler));
        }
        startBeat = toBeat;
        // with new starbeat \(self)")
    }

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