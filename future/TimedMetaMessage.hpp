

#ifndef GDMUSICKIT_TIMEDMETAMESSAGE_HPP
#define GDMUSICKIT_TIMEDMETAMESSAGE_HPP
#pragma once

#include <array>
#include <iostream>
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

        std::ostream& operator<<(std::ostream& os,
                                 const MIDIChannelMessage& mess) {
            return os << "status: " << mess.status << " d1: " << mess.data1;
        }
    };
    using MIDIChannelMessage = MIDIChannelMessage;

    struct MIDIMetaEvent {
        // unsigned char data[1];
        std::array<unsigned char, 1> data;
        int32_t dataLength;
        unsigned char metaEventType;

        std::ostream& operator<<(std::ostream& os, const MIDIMetaEvent& mess) {
            return os << "len: " << mess.dataLength
                      << " event type: " << mess.metaEventType;
        }
    };
    using MIDIMetaEvent = MIDIMetaEvent;

    struct MIDINoteMessage {
        unsigned char channel;

        unsigned char duration;

        unsigned char note;

        unsigned char releaseVelocity;

        unsigned char velocity;

        std::ostream& operator<<(std::ostream& os,
                                 const MIDINoteMessage& mess) {
            return os << "channel: " << mess.channel
                      << " duration: " << mess.duration;
        }
    };
    using MIDINoteMessage = MIDINoteMessage;

    class TimedMetaMessage {
      public:
        TimedMetaMessage(MusicTimeStamp ts, MIDIMetaEvent me)
            : eventTimeStamp(ts), metaEvent(me) {}

        std::ostream& operator<<(std::ostream& os,
                                 const TimedMetaMessage& mess) {
            return os << "ts: " << mess.eventTimeStamp
                      << " meta: " << mess.metaEvent;
        }

      private:
        MusicTimeStamp eventTimeStamp;
        MIDIMetaEvent metaEvent;
    };

    class TimedChannelMessage {
      public:
        TimedChannelMessage(MusicTimeStamp ts, MIDIChannelMessage cm)
            : eventTimeStamp(ts), channelMessage(cm) {}

        std::ostream& operator<<(std::ostream& os,
                                 const TimedChannelMessage& mess) {
            return os << "ts: " << mess.eventTimeStamp
                      << " cm: " << mess.channelMessage;
        }

      private:
        MusicTimeStamp eventTimeStamp;
        MIDIChannelMessage channelMessage;
    };

    class Timed {
      public:
        Timed(double s, double e, double d)
            : startBeat(s), endBeat(e), duration(d) {}

      protected:
        // NOLINT(misc-non-private-member-variables-in-classes)
        double startBeat;
        // NOLINT(misc-non-private-member-variables-in-classes)
        double endBeat;
        // NOLINT(misc-non-private-member-variables-in-classes)
        double duration;
    };

} // namespace gdmusickit

#endif
