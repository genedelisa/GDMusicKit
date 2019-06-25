#pragma once

#include "Pitch.hpp"
#include "PitchStringFormat.hpp"
#include <string>

namespace gdmusickit {

    /** @class Note Note.hpp "Note.hpp"
     *
     * @brief This is a Note class.
     *
     * Groovy, huh?
     *
     * ## Usage:
     *
     *  @code
     *  std::unique_ptr<Note> x = std::make_unique<Note>(60);
     *  std::cout << "x: " << x << std::endl;
     *  @endcode
     */

    class Note {
      public:
        Note(Pitch pitch, double startBeat = 1.0, double duration = 1.0);
        Note(std::string pitchString, double startBeat = 1.0, double duration = 1.0);

        const Pitch getPitch() const {return pitch;}
        const double getStartBeat() const {return startBeat;}        
        const double getDuration() const {return duration;}        

        bool operator<(const Note& note) const {
            return startBeat < note.startBeat;
        }
        friend std::ostream& operator<<(std::ostream& os, Note const& note);

        friend auto operator==(Note lhs, Note rhs) {
            return (rhs.pitch == lhs.pitch) && (rhs.startBeat == lhs.startBeat);
        }
        friend auto operator!=(Note lhs, Note rhs) {
            return (rhs.pitch != lhs.pitch) | (rhs.startBeat != lhs.startBeat);
        }

        friend struct NoteStartBeatComparator;

      protected:
      private:
        Pitch pitch{60};
        double startBeat{1.0};
        double duration{1.0};
        PitchStringFormat::Spelling spelling{PitchStringFormat::Spelling::flat};
    };

    /**
     * @brief Sort Notes based on start beat.
     *
     *
     * @code
     listofNotes.sort(NoteStartBeatComparator());
    * @endcode
     */
    struct NoteStartBeatComparator {
        // Compare 2 Note objects using start beat
        bool operator()(const Note& lhs, const Note& rhs) {
            if (lhs.startBeat == rhs.startBeat) {
                return lhs < rhs;
            }
            return lhs.startBeat < rhs.startBeat;
        }
    };

    // int usingLambda() {
    //     listofNotes.sort([](const Note& lhs, const Note& rhs) {
    //         if (lhs.startBeat == rhs.startBeat) {
    //             return lhs < rhs;
    //         }
    //         return lhs.startBeat < rhs.startBeat;
    //     });
    // }

} // namespace gdmusickit