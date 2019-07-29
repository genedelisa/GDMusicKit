// -*- C++ -*-

//#include <gdmusickit/Pitch.hpp>
#include "gdmusickit/Pitch.hpp"
#include "gdmusickit/PitchFactory.hpp"
#include <cmath>
#include <iostream>


namespace gdmusickit {

    Pitch::Pitch(int midiNumber) { this->midiNumber = midiNumber; }

    // @todo parse pitchString
    Pitch::Pitch(const std::wstring& pitchString) {}

    int Pitch::pitchClass() const { return midiNumber % 12; }

    int Pitch::octave() const { return midiNumber / 12; }

    int Pitch::midiPitchNumber() const { return midiNumber; }

    // constexpr auto URL_PATTERN =
    //     "(http|https)://(\\w+\\.)+(\\w)/?(\\w+/{0,1})*";

    std::ostream& operator<<(std::ostream& os, const Pitch& pitch) {
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
        if (Pitch::octaveForMiddleC == 5) {
            int offset = 5 - Pitch::octaveForMiddleC;
            a440 = 69 - (offset * 12);
        }
        // log.debug("using midinumber \(a440) as A 440")
        return 440.0 * std::pow(2.0, (double(midiNumber - a440) / 12));
    }

   
    // Pitch Constants


// inline const int Pitch::crap = 55;

// inline int Pitch::fooVar() {
//   static const int value = 42;
//   return value;
// }


   const Pitch* Pitch::C0 = PitchFactory::getSharedInstance().getPitch(
         0 + Pitch::octaveAdjustment(-5));

    static const Pitch* CS0 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(-5));

    static const Pitch* Db0 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(-5));

    static const Pitch* D0 = PitchFactory::getSharedInstance().getPitch(
        2 + Pitch::octaveAdjustment(-5));

    static const Pitch* DS0 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(-5));

    static const Pitch* Eb0 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(-5));

    static const Pitch* E0 = PitchFactory::getSharedInstance().getPitch(
        4 + Pitch::octaveAdjustment(-5));

    static const Pitch* F0 = PitchFactory::getSharedInstance().getPitch(
        5 + Pitch::octaveAdjustment(-5));

    static const Pitch* FS0 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(-5));

    static const Pitch* Gb0 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(-5));

    static const Pitch* G0 = PitchFactory::getSharedInstance().getPitch(
        7 + Pitch::octaveAdjustment(-5));

    static const Pitch* GS0 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(-5));

    static const Pitch* Ab0 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(-5));

    static const Pitch* A0 = PitchFactory::getSharedInstance().getPitch(
        9 + Pitch::octaveAdjustment(-5));

    static const Pitch* AS0 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(-5));

    static const Pitch* Bb0 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(-5));

    static const Pitch* B0 = PitchFactory::getSharedInstance().getPitch(
        11 + Pitch::octaveAdjustment(-5));

    static const Pitch* C1 = PitchFactory::getSharedInstance().getPitch(
        0 + Pitch::octaveAdjustment(-4));

    static const Pitch* CS1 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(-4));

    static const Pitch* Db1 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(-4));

    static const Pitch* D1 = PitchFactory::getSharedInstance().getPitch(
        2 + Pitch::octaveAdjustment(-4));

    static const Pitch* DS1 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(-4));

    static const Pitch* Eb1 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(-4));

    static const Pitch* E1 = PitchFactory::getSharedInstance().getPitch(
        4 + Pitch::octaveAdjustment(-4));

    static const Pitch* F1 = PitchFactory::getSharedInstance().getPitch(
        5 + Pitch::octaveAdjustment(-4));

    static const Pitch* FS1 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(-4));

    static const Pitch* Gb1 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(-4));

    static const Pitch* G1 = PitchFactory::getSharedInstance().getPitch(
        7 + Pitch::octaveAdjustment(-4));

    static const Pitch* GS1 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(-4));

    static const Pitch* Ab1 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(-4));

    static const Pitch* A1 = PitchFactory::getSharedInstance().getPitch(
        9 + Pitch::octaveAdjustment(-4));

    static const Pitch* AS1 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(-4));

    static const Pitch* Bb1 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(-4));

    static const Pitch* B1 = PitchFactory::getSharedInstance().getPitch(
        11 + Pitch::octaveAdjustment(-4));

    static const Pitch* C2 = PitchFactory::getSharedInstance().getPitch(
        0 + Pitch::octaveAdjustment(-3));

    static const Pitch* CS2 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(-3));

    static const Pitch* Db2 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(-3));

    static const Pitch* D2 = PitchFactory::getSharedInstance().getPitch(
        2 + Pitch::octaveAdjustment(-3));

    static const Pitch* DS2 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(-3));

    static const Pitch* Eb2 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(-3));

    static const Pitch* E2 = PitchFactory::getSharedInstance().getPitch(
        4 + Pitch::octaveAdjustment(-3));

    static const Pitch* F2 = PitchFactory::getSharedInstance().getPitch(
        5 + Pitch::octaveAdjustment(-3));

    static const Pitch* FS2 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(-3));

    static const Pitch* Gb2 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(-3));

    static const Pitch* G2 = PitchFactory::getSharedInstance().getPitch(
        7 + Pitch::octaveAdjustment(-3));

    static const Pitch* GS2 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(-3));

    static const Pitch* Ab2 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(-3));

    static const Pitch* A2 = PitchFactory::getSharedInstance().getPitch(
        9 + Pitch::octaveAdjustment(-3));

    static const Pitch* AS2 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(-3));

    static const Pitch* Bb2 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(-3));

    static const Pitch* B2 = PitchFactory::getSharedInstance().getPitch(
        11 + Pitch::octaveAdjustment(-3));

    static const Pitch* C3 = PitchFactory::getSharedInstance().getPitch(
        0 + Pitch::octaveAdjustment(-2));

    static const Pitch* CS3 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(-2));

    static const Pitch* Db3 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(-2));

    static const Pitch* D3 = PitchFactory::getSharedInstance().getPitch(
        2 + Pitch::octaveAdjustment(-2));

    static const Pitch* DS3 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(-2));

    static const Pitch* Eb3 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(-2));

    static const Pitch* E3 = PitchFactory::getSharedInstance().getPitch(
        4 + Pitch::octaveAdjustment(-2));

    static const Pitch* F3 = PitchFactory::getSharedInstance().getPitch(
        5 + Pitch::octaveAdjustment(-2));

    static const Pitch* FS3 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(-2));

    static const Pitch* Gb3 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(-2));

    static const Pitch* G3 = PitchFactory::getSharedInstance().getPitch(
        7 + Pitch::octaveAdjustment(-2));

    static const Pitch* GS3 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(-2));

    static const Pitch* Ab3 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(-2));

    static const Pitch* A3 = PitchFactory::getSharedInstance().getPitch(
        9 + Pitch::octaveAdjustment(-2));

    static const Pitch* AS3 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(-2));

    static const Pitch* Bb3 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(-2));

    static const Pitch* B3 = PitchFactory::getSharedInstance().getPitch(
        11 + Pitch::octaveAdjustment(-2));

    static const Pitch* C4 = PitchFactory::getSharedInstance().getPitch(
        0 + Pitch::octaveAdjustment(-1));

    static const Pitch* CS4 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(-1));

    static const Pitch* Db4 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(-1));

    static const Pitch* D4 = PitchFactory::getSharedInstance().getPitch(
        2 + Pitch::octaveAdjustment(-1));

    static const Pitch* DS4 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(-1));

    static const Pitch* Eb4 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(-1));

    static const Pitch* E4 = PitchFactory::getSharedInstance().getPitch(
        4 + Pitch::octaveAdjustment(-1));

    static const Pitch* F4 = PitchFactory::getSharedInstance().getPitch(
        5 + Pitch::octaveAdjustment(-1));

    static const Pitch* FS4 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(-1));

    static const Pitch* Gb4 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(-1));

    static const Pitch* G4 = PitchFactory::getSharedInstance().getPitch(
        7 + Pitch::octaveAdjustment(-1));

    static const Pitch* GS4 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(-1));

    static const Pitch* Ab4 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(-1));

    static const Pitch* A4 = PitchFactory::getSharedInstance().getPitch(
        9 + Pitch::octaveAdjustment(-1));

    static const Pitch* AS4 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(-1));

    static const Pitch* Bb4 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(-1));

    static const Pitch* B4 = PitchFactory::getSharedInstance().getPitch(
        11 + Pitch::octaveAdjustment(-1));

    static const Pitch* C5 = PitchFactory::getSharedInstance().getPitch(
        0 + Pitch::octaveAdjustment(0));

    static const Pitch* CS5 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(0));

    static const Pitch* Db5 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(0));

    static const Pitch* D5 = PitchFactory::getSharedInstance().getPitch(
        2 + Pitch::octaveAdjustment(0));

    static const Pitch* DS5 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(0));

    static const Pitch* Eb5 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(0));

    static const Pitch* E5 = PitchFactory::getSharedInstance().getPitch(
        4 + Pitch::octaveAdjustment(0));

    static const Pitch* F5 = PitchFactory::getSharedInstance().getPitch(
        5 + Pitch::octaveAdjustment(0));

    static const Pitch* FS5 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(0));

    static const Pitch* Gb5 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(0));

    static const Pitch* G5 = PitchFactory::getSharedInstance().getPitch(
        7 + Pitch::octaveAdjustment(0));

    static const Pitch* GS5 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(0));

    static const Pitch* Ab5 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(0));

    // static const Pitch* A5 = PitchFactory::getSharedInstance().getPitch(
    //     9 + Pitch::octaveAdjustment(0));

    static const Pitch* AS5 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(0));

    static const Pitch* Bb5 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(0));

    static const Pitch* B5 = PitchFactory::getSharedInstance().getPitch(
        11 + Pitch::octaveAdjustment(0));

    static const Pitch* C6 = PitchFactory::getSharedInstance().getPitch(
        0 + Pitch::octaveAdjustment(1));

    static const Pitch* CS6 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(1));

    static const Pitch* Db6 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(1));

    static const Pitch* D6 = PitchFactory::getSharedInstance().getPitch(
        2 + Pitch::octaveAdjustment(1));

    static const Pitch* DS6 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(1));

    static const Pitch* Eb6 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(1));

    static const Pitch* E6 = PitchFactory::getSharedInstance().getPitch(
        4 + Pitch::octaveAdjustment(1));

    static const Pitch* F6 = PitchFactory::getSharedInstance().getPitch(
        5 + Pitch::octaveAdjustment(1));

    static const Pitch* FS6 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(1));

    static const Pitch* Gb6 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(1));

    static const Pitch* G6 = PitchFactory::getSharedInstance().getPitch(
        7 + Pitch::octaveAdjustment(1));

    static const Pitch* GS6 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(1));

    static const Pitch* Ab6 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(1));

    static const Pitch* A6 = PitchFactory::getSharedInstance().getPitch(
        9 + Pitch::octaveAdjustment(1));

    static const Pitch* AS6 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(1));

    static const Pitch* Bb6 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(1));

    static const Pitch* B6 = PitchFactory::getSharedInstance().getPitch(
        11 + Pitch::octaveAdjustment(1));

    static const Pitch* C7 = PitchFactory::getSharedInstance().getPitch(
        0 + Pitch::octaveAdjustment(2));

    static const Pitch* CS7 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(2));

    static const Pitch* Db7 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(2));

    static const Pitch* D7 = PitchFactory::getSharedInstance().getPitch(
        2 + Pitch::octaveAdjustment(2));

    static const Pitch* DS7 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(2));

    static const Pitch* Eb7 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(2));

    static const Pitch* E7 = PitchFactory::getSharedInstance().getPitch(
        4 + Pitch::octaveAdjustment(2));

    static const Pitch* F7 = PitchFactory::getSharedInstance().getPitch(
        5 + Pitch::octaveAdjustment(2));

    static const Pitch* FS7 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(2));

    static const Pitch* Gb7 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(2));

    static const Pitch* G7 = PitchFactory::getSharedInstance().getPitch(
        7 + Pitch::octaveAdjustment(2));

    static const Pitch* GS7 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(2));

    static const Pitch* Ab7 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(2));

    static const Pitch* A7 = PitchFactory::getSharedInstance().getPitch(
        9 + Pitch::octaveAdjustment(2));

    static const Pitch* AS7 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(2));

    static const Pitch* Bb7 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(2));

    static const Pitch* B7 = PitchFactory::getSharedInstance().getPitch(
        11 + Pitch::octaveAdjustment(2));

    static const Pitch* C8 = PitchFactory::getSharedInstance().getPitch(
        0 + Pitch::octaveAdjustment(3));

    static const Pitch* CS8 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(3));

    static const Pitch* Db8 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(3));

    static const Pitch* D8 = PitchFactory::getSharedInstance().getPitch(
        2 + Pitch::octaveAdjustment(3));

    static const Pitch* DS8 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(3));

    static const Pitch* Eb8 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(3));

    static const Pitch* E8 = PitchFactory::getSharedInstance().getPitch(
        4 + Pitch::octaveAdjustment(3));

    static const Pitch* F8 = PitchFactory::getSharedInstance().getPitch(
        5 + Pitch::octaveAdjustment(3));

    static const Pitch* FS8 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(3));

    static const Pitch* Gb8 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(3));

    static const Pitch* G8 = PitchFactory::getSharedInstance().getPitch(
        7 + Pitch::octaveAdjustment(3));

    static const Pitch* GS8 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(3));

    static const Pitch* Ab8 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(3));

    static const Pitch* A8 = PitchFactory::getSharedInstance().getPitch(
        9 + Pitch::octaveAdjustment(3));

    static const Pitch* AS8 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(3));

    static const Pitch* Bb8 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(3));

    static const Pitch* B8 = PitchFactory::getSharedInstance().getPitch(
        11 + Pitch::octaveAdjustment(3));

    static const Pitch* C9 = PitchFactory::getSharedInstance().getPitch(
        0 + Pitch::octaveAdjustment(4));

    static const Pitch* CS9 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(4));

    static const Pitch* Db9 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(4));

    static const Pitch* D9 = PitchFactory::getSharedInstance().getPitch(
        2 + Pitch::octaveAdjustment(4));

    static const Pitch* DS9 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(4));

    static const Pitch* Eb9 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(4));

    static const Pitch* E9 = PitchFactory::getSharedInstance().getPitch(
        4 + Pitch::octaveAdjustment(4));

    static const Pitch* F9 = PitchFactory::getSharedInstance().getPitch(
        5 + Pitch::octaveAdjustment(4));

    static const Pitch* FS9 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(4));

    static const Pitch* Gb9 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(4));

    static const Pitch* G9 = PitchFactory::getSharedInstance().getPitch(
        7 + Pitch::octaveAdjustment(4));

    static const Pitch* GS9 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(4));

    static const Pitch* Ab9 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(4));

    static const Pitch* A9 = PitchFactory::getSharedInstance().getPitch(
        9 + Pitch::octaveAdjustment(4));

    static const Pitch* AS9 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(4));

    static const Pitch* Bb9 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(4));

    static const Pitch* B9 = PitchFactory::getSharedInstance().getPitch(
        11 + Pitch::octaveAdjustment(4));

    static const Pitch* C10 = PitchFactory::getSharedInstance().getPitch(
        0 + Pitch::octaveAdjustment(5));

    static const Pitch* CS10 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(5));

    static const Pitch* Db10 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(5));

    static const Pitch* D10 = PitchFactory::getSharedInstance().getPitch(
        2 + Pitch::octaveAdjustment(5));

    static const Pitch* DS10 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(5));

    static const Pitch* Eb10 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(5));

    static const Pitch* E10 = PitchFactory::getSharedInstance().getPitch(
        4 + Pitch::octaveAdjustment(5));

    static const Pitch* F10 = PitchFactory::getSharedInstance().getPitch(
        5 + Pitch::octaveAdjustment(5));

    static const Pitch* FS10 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(5));

    static const Pitch* Gb10 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(5));

    static const Pitch* G10 = PitchFactory::getSharedInstance().getPitch(
        7 + Pitch::octaveAdjustment(5));

} // namespace gdmusickit
