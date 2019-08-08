#pragma once

#ifndef GDMUSICKIT_TIMEDMETAMESSAGE_HPP
#define GDMUSICKIT_TIMEDMETAMESSAGE_HPP

#include <array>
#include <map>
#include <string>

#include "Note.hpp"
#include "Pitch.hpp"
#include "PitchStringFormat.hpp"

//#include <AudioUnit/AudioUnit.h>
//#include <CoreAudio/CoreAudio.h>
//#include <AudioToolbox/AudioToolbox.h> //for MIDIMetaEvent etc
//#include <CoreMIDI/CoreMIDI.h>

namespace gdmusickit {

    using MusicTimeStamp = float;

    struct MIDIChannelMessage {
        unsigned char status;
        unsigned char data1;
        unsigned char data2;
    };
    using MIDIChannelMessage = MIDIChannelMessage;

    struct MIDIMetaEvent {
        // unsigned char data[1];
        std::array<unsigned char, 1> data;
        int32_t dataLength;
        unsigned char metaEventType;
    };
    using MIDIMetaEvent = MIDIMetaEvent;

    struct MIDINoteMessage {
        unsigned char channel;

        unsigned char duration;

        unsigned char note;

        unsigned char releaseVelocity;

        unsigned char velocity;
    };
    using MIDINoteMessage = MIDINoteMessage;

    class TimedMetaMessage {
      public:
        TimedMetaMessage(MusicTimeStamp ts, MIDIMetaEvent me)
            : eventTimeStamp(ts), metaEvent(me) {}

      private:
        MusicTimeStamp eventTimeStamp;
        MIDIMetaEvent metaEvent;
    };

    class TimedChannelMessage {
      public:
        TimedChannelMessage(MusicTimeStamp ts, MIDIChannelMessage cm)
            : eventTimeStamp(ts), channelMessage(cm) {}

      private:
        MusicTimeStamp eventTimeStamp;
        MIDIChannelMessage channelMessage;
    };

    class Timed {
      public:
        Timed(double s, double e, double d)
            : startBeat(s), endBeat(e), duration(d) {}

      protected:
        double startBeat;

        double endBeat;

        double duration;
    };

} // namespace gdmusickit

#endif
