// -*- C++ -*-

/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License. 
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/


#ifndef GDMUSICKIT_MIDITRACK_HPP
#define GDMUSICKIT_MIDITRACK_HPP
/** @file MIDITrack.hpp
*  @brief The tracks inside a MIDISequence.
*
*  MIDITracks live inside a MIDISequence.
*
*  @date 2019-07-19
*  @copyright Copyright (c) 2019 Rockhopper Technologies, Inc.
*  @version 0.1.0
*  @author Gene De Lisa (gene@rockhoppertech.com)
*  @bug No known bugs.
*/

#pragma once

#include "Note.hpp"
#include "Pitch.hpp"
#include "PitchStringFormat.hpp"
#include <functional>
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
        using Callback = std::function<void(const MIDITrack&)>;

        explicit MIDITrack(double startBeat = 1.0);

        [[nodiscard]] double getStartBeat() const { return startBeat; }

        Note& addNote(const std::string& pitch, double startBeat,
                      double duration);
        Note& addNote(Note note);
        Note& removeNote(Note note);
        //        void append(MIDITrack other);


        void clear();
        
        [[nodiscard]] size_t size() const;

        std::multimap<double, Note> subset(int from, int to);

        void changeStartBeat(double toBeat);

        std::vector<Note> notesAtBeat(double beat);

        bool operator<(const MIDITrack& note) const {
            return startBeat < note.startBeat;
        }

        // Note  operator[](unsigned i) const;
        // Note& operator[](unsigned i);

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
#endif
