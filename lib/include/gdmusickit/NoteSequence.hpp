#pragma once

#include "Note.hpp"
#include <regex>
#include <string>

namespace gdmusickit {

    // template <long FROM, long TO>
    class NoteSequence {
      public:
        NoteSequence() : notes{std::make_unique<std::vector<Note>>()} {}

        void addNote(Note note);
        void removeNote(Note note);        

        void clear();
        
        friend std::ostream& operator<<(std::ostream& os,
                                        NoteSequence const& noteSequence);

        Note& operator[](int i) { return notes->at(i); }

        size_t size() const;
        friend std::ostream& operator<<(std::ostream& os, NoteSequence const& noteSequence);


        std::vector<Note>::iterator begin() const { return notes->begin(); }
        std::vector<Note>::iterator end() const { return notes->end(); }


      protected:
      private:
        std::unique_ptr<std::vector<Note>> notes;
    }; //

} // namespace gdmusickit