#pragma once

#include <regex>
#include <string>

namespace gdmusickit {

    class PitchStringParser {
      public:
        static int stringToMidiNumber(std::string pitchString);

      protected:

      private:
        static inline constexpr auto pitchPattern =
            "([a-gA-G]+[b|#]?)([0-9]*)";
    };

} // namespace gdmusickit