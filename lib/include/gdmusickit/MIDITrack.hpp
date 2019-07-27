/**
 * @file MIDITrack.hpp
 * @author Gene De Lisa (gene@rockhoppertech.com)
 * @brief 
 * @version 0.1.0
 * @date 2019-07-19
 * 
 * @copyright Copyright (c) 2019 Rockhopper Technologies, Inc.
 * 
 * 2019-07-19 Gene De Lisa gene@rockhoppertech.com
 * 
 *  ## Usage:
 * 
 *   @code
 * 
 *   @endcode
 */
#pragma once

#include "Note.hpp"
#include "Pitch.hpp"
#include "PitchStringFormat.hpp"
#include <map>
#include <string>
#include <functional>

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
        using Callback = std::function<void(const MIDITrack &)>;

        explicit MIDITrack(double startBeat = 1.0);

        double getStartBeat() const { return startBeat; }

        void addNote(Note note);
        void removeNote(Note note);
        //        void append(MIDITrack other);

        void clear();
        size_t size() const;

        std::multimap<double, Note> subset(int from, int to);

        void changeStartBeat(double toBeat);

        std::vector<Note> notesAtBeat(double beat);

        bool operator<(const MIDITrack& note) const {
            return startBeat < note.startBeat;
        }

        //Note  operator[](unsigned i) const;
        //Note& operator[](unsigned i);

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