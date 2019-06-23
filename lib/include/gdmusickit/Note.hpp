#pragma once

#include "Pitch.hpp"
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
        Note(Pitch pitch, double startTime = 1.0, double duration = 1.0);

      protected:
      
      private:
        Pitch pitch{60};
        double startTime{1.0};
        double duration{1.0};
    };

} // namespace gdmusickit