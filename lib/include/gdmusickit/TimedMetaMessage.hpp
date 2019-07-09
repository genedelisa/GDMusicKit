#pragma once

#include "Note.hpp"
#include "Pitch.hpp"
#include "PitchStringFormat.hpp"
#include <map>
#include <string>

//#include <AudioUnit/AudioUnit.h>
//#include <CoreAudio/CoreAudio.h>
#include <AudioToolbox/AudioToolbox.h> //for MIDIMetaEvent etc
#include <CoreMIDI/CoreMIDI.h>

namespace gdmusickit {

    class TimedMetaMessage {
      public:
      private:
        MusicTimeStamp eventTimeStamp;
        MIDIMetaEvent event;
    };
    
    class TimedChannelMessage {
      public:
      private:
        MusicTimeStamp eventTimeStamp;
        MIDIChannelMessage event;
    };

    class Timed {

        protected:
        double startBeat;

        double endBeat;

        double duration;
    };

} // namespace gdmusickit
