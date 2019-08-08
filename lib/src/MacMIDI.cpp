// -*- C++ -*-

#include "gdmusickit/MIDITrack.hpp"
#include "gdmusickit/Note.hpp"
#include "gdmusickit/Pitch.hpp"
#include "gdmusickit/PitchFactory.hpp"
// class Pitch;
// class Note;
// class PitchFactory;
// class MIDITrack;

#include "Logging.hpp"
#include "gdmusickit/MacMIDI.hpp"

#include <algorithm>
#include <charconv> // from_char, to_char
#include <exception>
#include <iostream>
#include <map>
#include <regex>
#include <string>

#include <AudioToolbox/AudioToolbox.h> //for AUGraph
#include <AudioUnit/AudioUnit.h>
#include <CoreAudio/CoreAudio.h>
#include <CoreMIDI/CoreMIDI.h>

// does not work in c++
//#include <AVFoundation/AVFoundation.h>

#include <CoreServices/CoreServices.h>

namespace gdmusickit {

    void foo() {
        MusicSequence sequence;
        OSStatus result = noErr;
        result = NewMusicSequence(&sequence);
        if (result != noErr) {
        }
        MusicTrack track;
        

        result = MusicSequenceSetMIDIEndpoint(sequence, MIDIGetDestination(0));
        
        MusicPlayer player;
        result = NewMusicPlayer(&player);

        result = MusicPlayerSetSequence(player, sequence);
    }

    MacMIDI::MacMIDI() {
        // nope AVAudioPlayer player;

        auto name = CFStringRef("thing");

        OSStatus result = noErr;
        result = MIDIClientCreate(name, nullptr, nullptr, &mClient);
        if (result != noErr) {
            LOG_ERROR << "MIDIClientCreate() LOG_ERROR:" << result;

            return;
        }
        result = MIDISourceCreate(mClient, name, &mEndpoint);
        if (result != noErr) {
            LOG_ERROR << "MIDISourceCreate() LOG_ERROR:" << result;
            // LOG_ERROR << GetMacOSStatusLOG_ERRORString(result) << " ";
            // LOG_ERROR << GetMacOSStatusCommentString(result) << " ";
            return;
        }
        result = MIDIOutputPortCreate(mClient, name, &mPort);
        if (result != noErr) {
            LOG_ERROR << "MIDIOutputPortCreate() LOG_ERROR:" << result;

            return;
        }
        reloadDeviceList();
    }

    MacMIDI::~MacMIDI() {
        OSStatus result = noErr;
        if (mPort != 0) {
            result = MIDIPortDispose(mPort);
            if (result != noErr) {
                LOG_ERROR << "MIDIPortDispose() LOG_ERROR:" << result;

                mPort = 0;
            }
        }
        if (mEndpoint != 0) {
            result = MIDIEndpointDispose(mEndpoint);
            if (result != noErr) {
                LOG_ERROR << "MIDIEndpointDispose() err:" << result;

                mEndpoint = 0;
            }
        }
        if (mClient != 0) {
            result = MIDIClientDispose(mClient);
            if (result != noErr) {
                LOG_ERROR << "MIDIClientDispose() LOG_ERROR:" << result;

                mClient = 0;
            }
        }
    }

    void MacMIDI::reloadDeviceList() {

        mOutputDevices.clear();

        int num = MIDIGetNumberOfDestinations();

        for (int i = 0; i < num; ++i) {
            bool excluded = false;
            MIDIEndpointRef dest = MIDIGetDestination(i);
            if (dest != 0) {
                auto name = getEndpointName(dest);
                mOutputDevices.emplace_back(name);
            }
        }

        // if (!m_currentOutput.isEmpty() && mDestination != 0 &&
        //     !mOutputDevices.contains(m_currentOutput)) {

        //     m_currentOutput.clear();
        //     mDestination = 0;
        // }
    }

    void MacMIDI::sendEvents(const MIDIPacketList* events) {
        MIDIReceived(mEndpoint, events);
        if (mDestination != 0)
            MIDISend(mPort, mDestination, events);
    }

    //    void MacMIDI::sendNoteOn(std::byte chan, std::byte note, std::byte
    //    vel) {
    // std::byte data[3]; // apple. unsigned char.
    //         MIDIPacketList pktlist;
    //         MIDIPacket* packet = MIDIPacketListInit(&pktlist);
    //         data[0] = MIDI_STATUS_NOTEON | (chan & MIDI_CHANNEL_MASK);
    //         data[1] = note;
    //         data[2] = vel;
    //         unsigned char* bytes = reinterpret_cast<unsigned char*>(bytes);
    //         packet = MIDIPacketListAdd(&pktlist, sizeof(pktlist), packet, 0,
    //                                    sizeof(bytes), bytes);
    //                                  //                 sizeof(data), data);

    //         if (packet != nullptr) {
    //             sendEvents(&pktlist);
    //         }
    //     }

    void MacMIDI::sendNoteOn(int chan, int note, int vel) {
        //UInt8 data[3];
        std::array<UInt8> data;
        MIDIPacketList pktlist;
        MIDIPacket* packet = MIDIPacketListInit(&pktlist);
        data[0] = midiStatusNoteon | (chan & 0x0f);
        data[1] = note;
        data[2] = vel;
        packet = MIDIPacketListAdd(&pktlist, sizeof(pktlist), packet, 0,
                                   sizeof(data), data);
        if (packet != nullptr) {
            sendEvents(&pktlist);
        }
    }

    void MacMIDI::sendNoteOff(int chan, int note, int vel) {
        UInt8 data[3];
        MIDIPacketList pktlist;
        MIDIPacket* packet = MIDIPacketListInit(&pktlist);
        data[0] = midiStatusNoteoff | (chan & 0x0f);
        data[1] = note;
        data[2] = vel;
        packet = MIDIPacketListAdd(&pktlist, sizeof(pktlist), packet, 0,
                                   sizeof(data), data);
        if (packet != nullptr) {
            sendEvents(&pktlist);
        }

        MIDITimeStamp timestamp = 0; // 0 will mean play now.
        Byte buffer[1024]; // storage space for MIDI Packets (max 65536)
        MIDIPacketList* packetlist = (MIDIPacketList*)buffer;
        MIDIPacket* currentpacket = MIDIPacketListInit(packetlist);
    }

    void MacMIDI::sendController(int chan, int control, int value) {
        UInt8 data[3];
        MIDIPacketList pktlist;
        MIDIPacket* packet = MIDIPacketListInit(&pktlist);
        data[0] = midiStatusControlchange | (chan & 0x0f);
        data[1] = control;
        data[2] = value;
        packet = MIDIPacketListAdd(&pktlist, sizeof(pktlist), packet, 0,
                                   sizeof(data), data);
        if (packet != nullptr) {
            sendEvents(&pktlist);
        }
    }

    void MacMIDI::sendKeyPressure(int chan, int note, int value) {
        UInt8 data[3];
        MIDIPacketList pktlist;
        MIDIPacket* packet = MIDIPacketListInit(&pktlist);
        data[0] = midiStatusKeypresure | (chan & 0x0f);
        data[1] = note;
        data[2] = value;
        packet = MIDIPacketListAdd(&pktlist, sizeof(pktlist), packet, 0,
                                   sizeof(data), data);
        if (packet != nullptr) {
            sendEvents(&pktlist);
        }
    }

    void MacMIDI::sendProgram(int chan, int program) {
        UInt8 data[2];
        MIDIPacketList pktlist;
        MIDIPacket* packet = MIDIPacketListInit(&pktlist);
        data[0] = midiStatusProgramchange | (chan & 0x0f);
        data[1] = program;
        packet = MIDIPacketListAdd(&pktlist, sizeof(pktlist), packet, 0,
                                   sizeof(data), data);
        if (packet != nullptr) {
            sendEvents(&pktlist);
        }
    }

    void MacMIDI::sendChannelPressure(int chan, int value) {
        UInt8 data[2];
        MIDIPacketList pktlist;
        MIDIPacket* packet = MIDIPacketListInit(&pktlist);
        data[0] = midiStatusChannelpressure | (chan & 0x0f);
        data[1] = value;
        packet = MIDIPacketListAdd(&pktlist, sizeof(pktlist), packet, 0,
                                   sizeof(data), data);
        if (packet != nullptr) {
            sendEvents(&pktlist);
        }
    }

    void MacMIDI::sendPitchBend(int chan, int value) {
        UInt16 val = value + 8192; // value between -8192 and +8191
        UInt8 data[3];
        MIDIPacketList pktlist;
        MIDIPacket* packet = MIDIPacketListInit(&pktlist);
        data[0] = midiStatusPitchbend | (chan & 0x0f);
        data[1] = MIDI_LSB(val); // LSB
        data[2] = MIDI_MSB(val); // MSB
        packet = MIDIPacketListAdd(&pktlist, sizeof(pktlist), packet, 0,
                                   sizeof(data), data);
        if (packet != nullptr) {
            sendEvents(&pktlist);
        }
    }

    void MacMIDI::sendSysex(const std::vector<UInt8>& data) {
        UInt8 buf[4096];
        if (data.size() > 4096)
            return;

        // MIDIPacketList* pktlist = (MIDIPacketList*)&buf;
        // MIDIPacket* packet = MIDIPacketListInit(pktlist);
        // packet = MIDIPacketListAdd(pktlist, sizeof(buf), packet, 0,
        // data.size(),
        //                            (const Byte*)data.data());
        // if (packet != nullptr) {
        //     sendEvents(&pktlist);
        // }
    }

    void MacMIDI::sendSystemMsg(const int status) {
        UInt8 data;
        MIDIPacketList pktlist;
        MIDIPacket* packet = MIDIPacketListInit(&pktlist);
        data = status;
        packet = MIDIPacketListAdd(&pktlist, sizeof(pktlist), packet, 0,
                                   sizeof(data), &data);
        if (packet != nullptr) {
            sendEvents(&pktlist);
        }
    }

    void emitSignals(MIDIPacket* packet) {}

    void playPacketListOnAllDevices(MIDIPortRef midiout,
                                    const MIDIPacketList* pktlist) {
        // send MIDI message to all MIDI output devices connected to computer:
        ItemCount nDests = MIDIGetNumberOfDestinations();
        ItemCount iDest;
        OSStatus status{noErr};
        MIDIEndpointRef dest;
        for (iDest = 0; iDest < nDests; iDest++) {
            dest = MIDIGetDestination(iDest);
            status = MIDISend(midiout, dest, pktlist);
            if (status != noErr) {
                LOG_ERROR << "Problem sendint MIDI data on port " << iDest;
                //                LOG_ERROR <<
                //                GetMacOSStatusLOG_ERRORString(status);
                return;
            }
        }
    }

    std::string MacMIDI::getEndpointName(MIDIEndpointRef endpoint) {
        std::string result{"Not found"};
        CFStringRef str = nullptr;
        MIDIObjectGetStringProperty(endpoint, kMIDIPropertyName, &str);
        if (str != nullptr) {
            result = cfStringToStdString(str);
            CFRelease(str);
            str = nullptr;
        }

        MIDIEntityRef entity = 0;
        MIDIEndpointGetEntity(endpoint, &entity);
        if (entity == 0)
            return result;

        if (result.empty()) {
            MIDIObjectGetStringProperty(entity, kMIDIPropertyName, &str);
            if (str != 0) {
                result = cfStringToStdString(str);

                CFRelease(str);
                str = 0;
            }
        }

        MIDIDeviceRef device = 0;
        MIDIEntityGetDevice(entity, &device);
        if (device == 0) {
            return result;
        }

        MIDIObjectGetStringProperty(device, kMIDIPropertyName, &str);
        if (str != 0) {
            auto s = cfStringToStdString(str);
            CFRelease(str);
            str = 0;
            if (!(result.find(s) == 0)) {
                // result = trim(s + ' ' + result);
            }
        }
        return result;
    }

    void MacMIDIReadProc(const MIDIPacketList* pktlist, void* refCon,
                         void* connRefCon) {

        gdmusickit::MacMIDI* obj = nullptr;
        if (refCon != nullptr) {
            obj = static_cast<gdmusickit::MacMIDI*>(refCon);
        }

        MIDIPacket* packet = (MIDIPacket*)pktlist->packet;
        for (unsigned int i = 0; i < pktlist->numPackets; ++i) {
            if (obj != NULL) {
                // obj->emitSignals(packet);
            }
            packet = MIDIPacketNext(packet);
        }
    }

    std::string MacMIDI::cfStringToStdString(CFStringRef cfString) {
        CFIndex bufferSize =
            CFStringGetLength(cfString) + 1; // The +1 is for having space for
                                             // the string to be NULL terminated
        char buffer[bufferSize];

        // CFStringGetCString is documented to return a false if the buffer is
        // too small (which shouldn't happen in this example) or if the
        // conversion generally fails
        if (CFStringGetCString(cfString, buffer, bufferSize,
                               kCFStringEncodingUTF8)) {
            std::string cppString(buffer);
            return cppString;
        }
        return 0;
    }

    std::string& ltrim(std::string& str,
                       const std::string& chars = "\t\n\v\f\r ") {
        str.erase(0, str.find_first_not_of(chars));
        return str;
    }

    std::string& rtrim(std::string& str,
                       const std::string& chars = "\t\n\v\f\r ") {
        str.erase(str.find_last_not_of(chars) + 1);
        return str;
    }

    std::string& trim(std::string& str,
                      const std::string& chars = "\t\n\v\f\r ") {
        return ltrim(rtrim(str, chars), chars);
    }

} // namespace gdmusickit