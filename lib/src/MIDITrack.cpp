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

    Note& MIDITrack::addNote(const std::string& pitch, double startBeat,
                             double duration) {

        Note note{pitch, startBeat, duration};
        auto it = notes.emplace(note.getStartBeat(), note);
        return it->second;

        // auto sp = std::make_unique<Note>(pitch, startBeat, duration);
        // auto note = sp.get();
        // notes->emplace_back(*note);
        // return *(note);
    }

    Note& MIDITrack::addNote(Note note) {
        auto it = notes.emplace(note.getStartBeat(), note);
        return it->second;

        // MIDIPacketList pktlist{0};
        // auto packet = MIDIPacketListInit(&pktlist);
        // auto p = MIDIPacketListAdd(&pktlist, ByteCount listSize,
        // MIDIPacket *curPacket, MIDITimeStamp time,
        // ByteCount nData,
        // const Byte *data);
    }

    Note& MIDITrack::removeNote(Note note) {

        auto it = notes.begin();
        while (it != notes.end()) {
            LOG_INFO << "checking" << note << " against " << it->second << "\n";
            if (it->second == note) {
                LOG_INFO << "match"
                         << "\n";
                it = notes.erase(it);
                return it->second;
            } else {
                it++;
                LOG_INFO << "no match"
                         << "\n";
            }
        }
        throw std::invalid_argument("Note not in track!");

        // for (auto it = notes.begin(); it != notes.end();) {
        //     it = notes.erase(it);
        // }

        // https://en.wikipedia.org/wiki/Erase–remove_idiom
        // std::vector<Note>* v = notes.get();
        // std::pair<double, Note> n{note.getStartBeat(), note};
        // notes.erase(std::remove(notes.begin(), notes.end(), n), notes.end());
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

    std::vector<Note> MIDITrack::notesAtBeat(double beat) {
        std::vector<Note> vector;
        auto er = notes.equal_range(beat);
        for (auto it = er.first; it != er.second; ++it) {
            LOG_INFO << "at beat " << beat << " : " << it->second << "\n";
            vector.push_back(it->second);
        }

        // find returns just one. So, that's the wrong one to use

        // for (auto it = notes.find(beat); it != notes.end(); ++it) {
        auto eer = notes.find(beat);
        LOG_INFO << "eer: " << eer->second << "\n";

        // for (auto it = eer.first; it != eer.second; ++it) {
        // }

        //                for ( auto iter = it->first; iter != it->second;
        //                ++iter) {

        // while ( it++) {
        //     LOG_INFO << "at beat " << beat << " : " << it->second << "\n";
        //     vector.push_back(it->second);
        // }

        // while (it != notes.end()) {
        //     ++it;
        //     //        for (auto i = it.; i != it.end(); ++i) {
        //     // for (auto i = it.; i != it.end(); ++i) {
        //     vector.push_back(it->second);
        // }
        return vector;
    }
    void MIDITrack::changeStartBeat(double toBeat) {

        if (toBeat < 1.0) {
            LOG_ERROR << "beat " << toBeat << " is cannot be < 1";
            throw std::invalid_argument("bad start beat");
        }
        LOG_INFO << "changing to startBeat: " << toBeat << "\n";

        // auto firstNote = notes.find(1)->second;
        auto firstNote = notes.begin()->second;
        LOG_INFO << "firstNote: " << firstNote << "\n";

        double now = firstNote.getStartBeat();
        LOG_INFO << "now: " << now << "\n";

        // double diff = now - toBeat;
        double diff = toBeat - now;
        // LOG_INFO << "diff: " << diff << "\n";
        for (auto& [sb, note] : notes) {

            //            double newstart = sb + diff;
            LOG_INFO << "loop sb: " << sb << "\n";
            LOG_INFO << "note sb: " << note.getStartBeat() << "\n";
            LOG_INFO << "note : " << note << "\n";
            // double diff = toBeat - note.getStartBeat();
            LOG_INFO << "diff: " << diff << "\n";

            double newstart = note.getStartBeat() + diff;

            LOG_INFO << "New start " << newstart << "\n";
            note.setStartBeat(newstart);

            // this breaks the loop
            // auto nodeHandler = notes.extract(sb);
            // nodeHandler.key() = newstart;
            // note.setStartBeat(newstart);
            // notes.insert(std::move(nodeHandler));
        }

        // update the keys
        std::multimap<double, Note> map;
        for (auto& [sb, note] : notes) {
            map.emplace(note.getStartBeat(), note);
        }
        // notes = map;
        notes.swap(map);

        // this breaks the loop too
        // for (auto& [sb, note] : notes) {
        //     auto nodeHandle = notes.extract(sb);
        //     nodeHandle.key() = note.getStartBeat();
        //     std::cout << sb << " nodeh " << nodeHandle.mapped() << "\n";
        //     notes.insert(std::move(nodeHandle));
        // }

        // for (auto const& pair : notes) {
        //     std::cout << "notes {" << pair.first << ": " << pair.second <<
        //     "}\n";
        // }

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