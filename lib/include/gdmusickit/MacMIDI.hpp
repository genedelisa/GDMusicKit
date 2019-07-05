#pragma once

#define MIDI_CHANNELS 16
#define MIDI_GM_DRUM_CHANNEL (10 - 1)
#define MIDI_CTL_MSB_MAIN_VOLUME 0x07
#define MIDI_CTL_ALL_SOUNDS_OFF 0x78
#define MIDI_CTL_ALL_NOTES_OFF 0x7b
#define MIDI_CTL_RESET_CONTROLLERS 0x79

#define MIDI_STATUS_NOTEOFF 0x80
#define MIDI_STATUS_NOTEON 0x90
#define MIDI_STATUS_KEYPRESURE 0xa0
#define MIDI_STATUS_CONTROLCHANGE 0xb0
#define MIDI_STATUS_PROGRAMCHANGE 0xc0
#define MIDI_STATUS_CHANNELPRESSURE 0xd0
#define MIDI_STATUS_PITCHBEND 0xe0
#define MIDI_STATUS_SYSEX 0xf0
#define MIDI_STATUS_ENDSYSEX 0xf7
#define MIDI_STATUS_REALTIME 0xf8

#define MIDI_STATUS_MASK 0xf0
#define MIDI_CHANNEL_MASK 0x0f

#define MIDI_COMMON_QTRFRAME 0xF1
#define MIDI_COMMON_SONGPP 0xF2
#define MIDI_COMMON_SONSELECT 0xF3
#define MIDI_COMMON_TUNEREQ 0xF6

#define MIDI_REALTIME_CLOCK 0xF8
#define MIDI_REALTIME_START 0xFA
#define MIDI_REALTIME_CONTINUE 0xFB
#define MIDI_REALTIME_STOP 0xFC
#define MIDI_REALTIME_SENSING 0xFE
#define MIDI_REALTIME_RESET 0xFF

#define MIDI_LSB(x) (x % 0x80)
#define MIDI_MSB(x) (x / 0x80)

#include "gdmusickit/MIDITrack.hpp"
#include "gdmusickit/Note.hpp"
#include "gdmusickit/Pitch.hpp"
#include "gdmusickit/PitchFactory.hpp"

#include "Logging.hpp"

#include <algorithm>
#include <charconv> // from_char, to_char
#include <exception>
#include <iostream>
#include <map>
#include <regex>
#include <string>

#include <AudioUnit/AudioUnit.h>
#include <CoreAudio/CoreAudio.h>
#include <CoreMIDI/CoreMIDI.h>
//#include <CoreServices/CoreServices.h>

namespace gdmusickit {

    class MacMIDI {

      public:
        /**
         * @brief sendNoteOff 0x8
         * @param chan
         * @param note
         * @param vel
         */
        virtual void sendNoteOff(int chan, int note, int vel) = 0;

        /**
         * @brief sendNoteOn 0x9
         * @param chan
         * @param note
         * @param vel
         */
        virtual void sendNoteOn(int chan, int note, int vel) = 0;

        /**
         * @brief sendKeyPressure 0xA
         * @param chan
         * @param note
         * @param value
         */
        virtual void sendKeyPressure(int chan, int note, int value) = 0;

        /**
         * @brief sendController 0xB
         * @param chan
         * @param control
         * @param value
         */
        virtual void sendController(int chan, int control, int value) = 0;

        /**
         * @brief sendProgram 0xC
         * @param chan
         * @param program
         */
        virtual void sendProgram(int chan, int program) = 0;

        /**
         * @brief sendChannelPressure 0xD
         * @param chan
         * @param value
         */
        virtual void sendChannelPressure(int chan, int value) = 0;

        /**
         * @brief sendPitchBend 0xE
         * @param chan
         * @param value
         */
        virtual void sendPitchBend(int chan, int value) = 0;

        /**
         * @brief sendSysex
         * @param data 0xF0 ... 0xF7
         */
        virtual void sendSysex(const std::vector<UInt8> data) = 0;

        /**
         * @brief sendSystemMsg
         * @param status 0xF
         */
        virtual void sendSystemMsg(const int status) = 0;

        MacMIDI();
        virtual ~MacMIDI();

      protected:
      private:
        MIDIClientRef m_client;
        MIDIPortRef m_port;
        MIDIEndpointRef m_endpoint;
        MIDIEndpointRef m_destination;

        std::vector<std::string> m_outputDevices;
        void reloadDeviceList();
        void sendEvents(const MIDIPacketList* events);
        std::string getEndpointName(MIDIEndpointRef endpoint);
        std::string cfStringToStdString(CFStringRef cfString);

    };
} // namespace gdmusickit