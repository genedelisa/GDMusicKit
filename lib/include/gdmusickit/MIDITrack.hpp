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

        const double getStartBeat() const { return startBeat; }

        void addNote(Note note);
        void removeNote(Note note);
        //        void append(MIDITrack other);

        void clear();
        size_t size() const;

        bool operator<(const MIDITrack& note) const {
            return startBeat < note.startBeat;
        }
        
        friend std::ostream& operator<<(std::ostream& os,
                                        MIDITrack const& note);

        friend auto operator==(MIDITrack lhs, MIDITrack rhs) {
            return true;
            //   return (rhs.pitch == lhs.pitch) && (rhs.startBeat ==
            //   lhs.startBeat);
        }
        friend auto operator!=(MIDITrack lhs, MIDITrack rhs) {
            return true;
            // return (rhs.pitch != lhs.pitch) | (rhs.startBeat !=
            // lhs.startBeat);
        }

      protected:
      private:
        std::map<double, Note> notes;
        double startBeat{1.0};
    };

} // namespace gdmusickit