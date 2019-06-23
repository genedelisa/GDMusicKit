#pragma once

#include <regex>
#include <string>

namespace gdmusickit {

    class PitchStringParser {
      public:
        static int stringToMidiNumber(std::string pitchString);

      protected:
      private:
        // input is uppercased
        static inline constexpr auto pitchPattern =
            "([a-gA-G]{1}[S|F|B|#]?)([0-9]*)";
    };

} // namespace gdmusickit