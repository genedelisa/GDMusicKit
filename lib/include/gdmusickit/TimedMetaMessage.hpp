#pragma once

#include "Note.hpp"
#include "Pitch.hpp"
#include "PitchStringFormat.hpp"
#include <map>
#include <string>

//#include <AudioUnit/AudioUnit.h>
//#include <CoreAudio/CoreAudio.h>
//#include <AudioToolbox/AudioToolbox.h> //for MIDIMetaEvent etc
//#include <CoreMIDI/CoreMIDI.h>

namespace gdmusickit {

    typedef float MusicTimeStamp;

    typedef struct MIDIChannelMessage {
        unsigned char status;
        unsigned char data1;
        unsigned char data2;
    } MIDIChannelMessage;

    typedef struct MIDIMetaEvent {
        unsigned char data[1];
        int32_t dataLength;
        unsigned char metaEventType;

    } MIDIMetaEvent;

    typedef struct MIDINoteMessage {
        unsigned char channel;

        unsigned char duration;

        unsigned char note;

        unsigned char releaseVelocity;

        unsigned char velocity;
    } MIDINoteMessage;

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
