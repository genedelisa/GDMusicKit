#pragma once

#include "Note.hpp"
#include "Pitch.hpp"
#include "PitchStringFormat.hpp"
#include <map>
#include <string>

namespace gdmusickit {

    /** @class MIDITrack MIDITrack.hpp "MIDITrack.hpp"
     *
     * @brief This is a MIDITrack class.
     *
     * Groovy, huh?
     *
     * ## Usage:
     *
     *  @code
     *  std::unique_ptr<MIDITrack> x = std::make_unique<MIDITrack>(60);
     *  std::cout << "x: " << x << std::endl;
     *  @endcode
     */

    class MIDITrack {
      public:
        explicit MIDITrack(double startBeat = 1.0);

        double getStartBeat() const { return startBeat; }

        void addNote(Note note);
        void removeNote(Note note);
        //        void append(MIDITrack other);

        void clear();
        size_t size() const;

        std::multimap<double, Note> subset(int from, int to);

        bool operator<(const MIDITrack& note) const {
            return startBeat < note.startBeat;
        }

        friend std::ostream& operator<<(std::ostream& os,
                                        MIDITrack const& midiTrack);

        friend auto operator==(MIDITrack lhs, MIDITrack rhs) {
            return (rhs.startBeat == lhs.startBeat);
            //   return (rhs.pitch == lhs.pitch) && (rhs.startBeat ==
            //   lhs.startBeat);
        }
        friend auto operator!=(MIDITrack lhs, MIDITrack rhs) {

            return (rhs.startBeat != lhs.startBeat);

            // return (rhs.pitch != lhs.pitch) | (rhs.startBeat !=
            // lhs.startBeat);
        }

      protected:
      private:
        std::multimap<double, Note> notes;
        double startBeat{1.0};

        // auto metaEvents = [TimedMetaMessage]()

        // auto channelMessages = [TimedChannelMessage]()
        /// will be a meta text event if set
        std::string name;

        // loopDuration = MusicTimeStamp(0)

        // bool loop = false;
        // unsigned char patchNum = GMPatch.piano
    };

} // namespace gdmusickit