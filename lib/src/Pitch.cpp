
//#include <gdmusickit/Pitch.hpp>
#include "gdmusickit/Pitch.hpp"
//#include "Pitch.hpp"
//#include <Pitch.hpp>
#include <cmath>
#include <iostream>

// gene's music kit
namespace gdmusickit {

    Pitch::Pitch(int midiNumber) { this->midiNumber = midiNumber; }

    // @todo parse pitchString    
    Pitch::Pitch(std::wstring pitchString) {

    }

    int Pitch::pitchClass() { return midiNumber % 12; }

    int Pitch::octave() { return midiNumber / 12; }

    int Pitch::midiPitchNumber() { return midiNumber; }

    constexpr auto URL_PATTERN =
        "(http|https)://(\\w+\\.)+(\\w)/?(\\w+/{0,1})*";

    std::ostream& operator<<(std::ostream& os, Pitch const& pitch) {
        return os << "MIDI number: " << pitch.midiNumber;
    }

    /**
         Calculate the frequency in Hz for a given Pitch
         - returns: the frequence in Hz of the Pitch
         */
    static double midiEqualTemperamentFrequency(int midiNumber) {
        // 69 is midinumber for A5, 440 is that fq
        // do not use Pitch.A5.midiNumber since this is referenced from the ctor
        int a440 = 69;
        if (Pitch::octaveForMiddleC != 5) {
            int offset = 5 - Pitch::octaveForMiddleC;
            a440 = 69 - (offset * 12);
        }
        // log.debug("using midinumber \(a440) as A 440")
        return 440.0 * std::pow(2.0, (double(midiNumber - a440) / 12));
    }
} // namespace gdmusickit
