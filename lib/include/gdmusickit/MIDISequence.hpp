#ifndef GDMUSICKIT_MIDISEQUENCE_HPP
#define GDMUSICKIT_MIDISEQUENCE_HPP

#pragma once

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

    /**
     * @brief A Collection of MIDITracks.
     *
     * @see gdmusickit::MIDITrack
     */
    class MIDISequence {
        friend std::ostream& operator<<(std::ostream& os,
                                        MIDISequence const& midiSequence);

      public:
        /**
         * @brief Add a MIDITrack to the sequence.
         *
         * @param track
         */
        void addTrack(MIDITrack& track);

        /**
         * @brief Return how many MIDITracks are in the sequence.
         *
         * @return size_t
         */
        [[nodiscard]] size_t size() const;

        /**
         * @brief Remove all the tracks from th sequence.
         *
         */
        void clear();

        MIDITrack& operator[](int i) { return tracks.at(i); }

        using TrackMapT = std::map<double, MIDITrack>;

        [[nodiscard]] TrackMapT::const_iterator begin() const {
            return tracks.begin();
        }

        [[nodiscard]] TrackMapT::const_iterator end() const {
            return tracks.end();
        }

      private:

        TrackMapT tracks;
    };

} // namespace gdmusickit
#endif
