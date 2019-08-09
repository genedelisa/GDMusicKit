// -*- C++ -*-

/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License.
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/

#ifndef GDMUSICKIT_NOTESEQUENCE_HPP
#define GDMUSICKIT_NOTESEQUENCE_HPP

#pragma once

#include "Note.hpp"
#include <regex>
#include <string>

namespace gdmusickit {

    // template <long FROM, long TO>
    class NoteSequence {
      public:
        /**
         * @brief Construct a new Note Sequence object
         * The notes vector smart pointer is created.
         */
        NoteSequence() : notes{std::make_unique<std::vector<Note>>()} {}

        Note& addNote(const std::string& pitch, double startBeat,
                      double duration);

        void addNote(Note& note);

        void addNote(Note const& note);

        /**
         * @brief Append a Note to the sequence.
         *
         * @detail
         * This changes the Note's start beat to the end beat of the last
         * Note in the sequence.
         *
         * @param note
         */
        void appendNote(Note& note);

        /**
         * @brief Remove the specified note
         *
         * @param note
         */
        void removeNote(Note& note);

        /**
         * @brief Change all start beats to make the Notes sequential.
         *
         * @param gap The space between Notes. Default 0.
         * @return NoteSequence& The NoteSequence to cascade.
         */
        NoteSequence& makeSequential(double gap = 0.0);

        /**
         * @brief Extract just the Pitches as a vector.
         *
         * @return std::vector<Pitch*>
         */
        std::vector<Pitch*> getPitches();

        /**
         * @brief Get the end beat.
         *
         * @return double
         */
        double getEndBeat();

        template <typename F> void myFunctionWithLambda(F&& lambda) {
            // some things
            std::cout << "lambda: " << lambda << std::endl;
            LOG_INFO << "lambda: " << lambda << "\n";
            // lambda();
        }

        // what for_each requires
        // using NoteLambdaT = [](Note&){};
        // Note& modify(Note& n, double value, NoteLambdaT lamb);

        Note& modify(Note& n, double value,
                     std::function<Note&(Note&, double)> func);

        void modifyStartBeat(double value);

        std::vector<Note> search(std::function<bool(Note)> ifFun);

        void clear();

        friend std::ostream& operator<<(std::ostream& os,
                                        NoteSequence const& noteSequence);

        friend NoteSequence& operator<<(NoteSequence& ns,
                                        std::string const& pitchString);

        /**
         * @brief
         *
         * @param ns
         * @param note
         * @return NoteSequence&
         */
        friend NoteSequence& operator<<(NoteSequence& ns, Note& note);

        Note& operator[](int i) { return notes->at(i); }

        [[nodiscard]] size_t size() const;

        // friend std::ostream& operator<<(std::ostream& os, NoteSequence const&
        // noteSequence);

        [[nodiscard]] std::vector<Note>::iterator begin() const {
            return notes->begin();
        }

        [[nodiscard]] std::vector<Note>::iterator end() const {
            return notes->end();
        }

      protected:
      private:
        std::unique_ptr<std::vector<Note>> notes;
    }; //

} // namespace gdmusickit
#endif
