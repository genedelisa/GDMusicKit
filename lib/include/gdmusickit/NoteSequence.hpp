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

        void removeNote(Note& note);

        NoteSequence& makeSequential();
        
        double getEndBeat();

        std::vector<Note> search(std::function<bool(Note)> ifFun);

        void clear();

        friend std::ostream& operator<<(std::ostream& os,
                                        NoteSequence const& noteSequence);

        friend NoteSequence& operator<<(NoteSequence& ns, std::string const& pitchString);

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
