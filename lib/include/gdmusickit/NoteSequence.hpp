#pragma once

#include "Note.hpp"
#include <regex>
#include <string>

namespace gdmusickit {

    class NoteSequence {
      public:
        NoteSequence() : notes{std::make_unique<std::vector<Note>>()} {}

        void addNote(Note note);
        friend std::ostream& operator<<(std::ostream& os, NoteSequence const& noteSequence);

      protected:
      private:
        std::unique_ptr<std::vector<Note>> notes;
    };

} // namespace gdmusickit