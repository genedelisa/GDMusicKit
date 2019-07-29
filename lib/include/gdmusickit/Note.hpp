// -*- C++ -*-

#ifndef GDMUSICKIT_NOTE_HPP
#define GDMUSICKIT_NOTE_HPP

#pragma once

#include "Logging.hpp"
#include "Pitch.hpp"
#include "PitchFactory.hpp"
#include "PitchStringFormat.hpp"
#include <string>

namespace gdmusickit {

    /** @class Note Note.hpp "Note.hpp"
     *
     * @brief This is a Note class.
     * @details
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
#pragma mark -
#pragma mark === Public Interface ===
#pragma mark> Constructors

        /** @name Constructors */
        ///@{

        /**
         * @brief Constructor
         * @param pitch
         * @param startBeat
         * @param duration
         */
        explicit Note(Pitch& pitch, double startBeat = 1.0,
                      double duration = 1.0);
        /**
         * @brief Construct a new gdmusickit::Note object
         *
         * @param pitchString
         * @param startBeat
         * @param duration
         */
        explicit Note(std::string pitchString, double startBeat = 1.0,
             double duration = 1.0);

        // Note(const std::string& pitchString, double startBeat,
        //       double duration)

        // Note(const Note& note) :
        // pitch(note.pitch), startBeat(note.startBeat), duration(note.duration)
        // {
        //     // this->pitch = note.pitch;
        //     // this->startBeat = note.startBeat;
        //     // this->duration = note.duration;
        // }

        /**
         * @brief Constructor
         * @param p a Pitch.
         */
        // Note(std::shared_ptr<Pitch> p, double start = 1.0, double dur = 1.0)
        //     : pitch(p), startBeat(start), duration(dur) {}
        explicit Note(Pitch* p, double start = 1.0, double dur = 1.0)
            : pitch(p), startBeat(start), duration(dur) {}

        ~Note();
        ///@}

#pragma mark> Accessors
        /** @name Accessors */
        ///@{
        [[nodiscard]] Pitch* getPitch() const { return pitch; }
        [[nodiscard]] double getStartBeat() const { return startBeat; }
        [[nodiscard]] double getDuration() const { return duration; }
        [[nodiscard]] int midiPitchNumber() const {
            return pitch->midiPitchNumber();
        }
        ///@}

#pragma mark> Utilities
        /** @name Utilities */
        ///@{
        /**
         * @brief Set the Start Beat object
         *
         * @param startBeat
         * @return Note& so you can cascade calls
         */
        Note& setStartBeat(const double startBeat) {
            this->startBeat = startBeat;
            return *this;
        }
        /**
         * @brief Set the Duration object
         *
         * @param duration
         * @return Note& for cascading calls
         */
        Note& setDuration(const double duration) {
            this->duration = duration;
            return *this;
        }
        /**
         * @brief Set the Pitch object
         *
         * @param pitch
         * @return Note& for cascading calls
         */
        Note& setPitch(Pitch* pitch) {
            this->pitch = pitch;
            return *this;
        }
        /**
         * @brief Change Pitch to new Pitch with midiPitchNumber.
         * This will look up the Pitch by midiPitchNumber
         * and assign it to the Note.
         * @param pitch
         * @return Note&
         * @throws std::invalid_argument if the number param is out of range.
         */
        Note& setMidiPitchNumber(const int midiPitchNumber) {
            if (!isValidMIDINumber(midiPitchNumber)) {
                throw std::invalid_argument("MIDI pitch number is out of range");
            }
            this->pitch =
                PitchFactory::getSharedInstance().getPitch(midiPitchNumber);
            return *this;
        }
        /**
         * @brief Checks validity of pitch number
         * @details MIDI pitch numbers must be between 0 and 127
         * @param midiPitchNumber the number to be tested
         * @return true if valid
         * @return false if not valid
         */
        bool isValidMIDINumber(const int midiPitchNumber) {
            return (midiPitchNumber >=0 &&  midiPitchNumber <= 127);
        }
        ///@}

#pragma mark> Operators
        /** @name Operators */
        ///@{

        /**
         * @brief less than comparison operator by start beat
         *
         * @param note
         * @return true or false
         */
        bool operator<(const Note& note) const {
            return startBeat < note.startBeat;
        }

        /**
         * @brief Assignment operator
         *
         * @param rhs
         */
        Note& operator=(const Note& rhs) {
            //pitch is a pointer. But it's a flyweight!
            // it's ok to point to the same thing
            pitch = rhs.pitch;
            startBeat = rhs.startBeat;
            duration = rhs.duration;
            return *this;
        }

        /**
         * @brief Insertion operator
         * @details prints a formatted description of the Note
         * @param os the output stream
         * @param note the note that's going to be printed
         * @return std::ostream& the stream for cascading calls
         */
        friend std::ostream& operator<<(std::ostream& os, Note const& note);

        // friend auto operator==(Note lhs, Note rhs) {
        //     return (rhs.pitch == lhs.pitch) && (rhs.startBeat ==
        //     lhs.startBeat);
        // }

        // friend auto operator!=(Note lhs, Note rhs) {
        //     return (rhs.pitch != lhs.pitch) | (rhs.startBeat !=
        //     lhs.startBeat);
        // }

        /**
         * @brief Equality operator
         *
         * @param rhs
         * @return true
         * @return false
         */
        bool operator==(const Note& rhs) const {
            return (this->pitch == rhs.pitch &&
                    this->startBeat == rhs.startBeat &&
                    this->duration == rhs.duration);
        }
        /**
         * @brief Inequality operator
         *
         * @param rhs
         * @return true
         * @return false
         */
        bool operator!=(const Note& rhs) const {
            return (this->pitch == rhs.pitch);
        }

        ///@}

        friend struct NoteStartBeatComparator;

      protected:
      private:
        // pimpl
        // https://www.fluentcpp.com/2017/09/22/make-pimpl-using-unique_ptr/
        // class NoteImpl;
        // std::unique_ptr<NoteImpl> impl_;

        Pitch* pitch{nullptr};
        // Pitch pitch{60};
        // const Pitch& pitch;

        // const Pitch& pitch{60};

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
#endif
