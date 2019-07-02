#include "gdmusickit/MIDITrack.hpp"
#include "gdmusickit/Note.hpp"
#include "gdmusickit/Pitch.hpp"
#include "gdmusickit/PitchFactory.hpp"

#include <algorithm>
#include <charconv> // from_char, to_char
#include <exception>
#include <iostream>
#include <regex>
#include <string>

namespace gdmusickit {

    class MIDISequence {
      public:
        void addTrack(MIDITrack track);

      private:
        std::map<double, MIDITrack> tracks;
    };
    
} // namespace gdmusickit