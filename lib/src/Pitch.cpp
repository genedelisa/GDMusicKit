
//#include <gdmusickit/Pitch.hpp>
#include "gdmusickit/Pitch.hpp"
#include "gdmusickit/PitchFactory.hpp"
#include <cmath>
#include <iostream>


// gene's music kit
namespace gdmusickit {

    Pitch::Pitch(int midiNumber) { this->midiNumber = midiNumber; }

    // @todo parse pitchString
    Pitch::Pitch(const std::wstring& pitchString) {}

    int Pitch::pitchClass() const { return midiNumber % 12; }

    int Pitch::octave() const { return midiNumber / 12; }

    int Pitch::midiPitchNumber() const { return midiNumber; }

    // constexpr auto URL_PATTERN =
    //     "(http|https)://(\\w+\\.)+(\\w)/?(\\w+/{0,1})*";

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
        if (Pitch::octaveForMiddleC == 5) {
            int offset = 5 - Pitch::octaveForMiddleC;
            a440 = 69 - (offset * 12);
        }
        // log.debug("using midinumber \(a440) as A 440")
        return 440.0 * std::pow(2.0, (double(midiNumber - a440) / 12));
    }

    static void createConstants() {
        //     static Pitch A5;
        // Pitch::A5 = PitchFactory::getSharedInstance().getPitch(
        //     9 + Pitch::octaveAdjustment(0));
    }
    // Constants
    static Pitch C0 = PitchFactory::getSharedInstance().getPitch(
        0 + Pitch::octaveAdjustment(-5));

    static Pitch CS0 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(-5));

    static Pitch Db0 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(-5));

    static Pitch D0 = PitchFactory::getSharedInstance().getPitch(
        2 + Pitch::octaveAdjustment(-5));

    static Pitch DS0 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(-5));

    static Pitch Eb0 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(-5));

    static Pitch E0 = PitchFactory::getSharedInstance().getPitch(
        4 + Pitch::octaveAdjustment(-5));

    static Pitch F0 = PitchFactory::getSharedInstance().getPitch(
        5 + Pitch::octaveAdjustment(-5));

    static Pitch FS0 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(-5));

    static Pitch Gb0 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(-5));

    static Pitch G0 = PitchFactory::getSharedInstance().getPitch(
        7 + Pitch::octaveAdjustment(-5));

    static Pitch GS0 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(-5));

    static Pitch Ab0 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(-5));

    static Pitch A0 = PitchFactory::getSharedInstance().getPitch(
        9 + Pitch::octaveAdjustment(-5));

    static Pitch AS0 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(-5));

    static Pitch Bb0 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(-5));

    static Pitch B0 = PitchFactory::getSharedInstance().getPitch(
        11 + Pitch::octaveAdjustment(-5));

    static Pitch C1 = PitchFactory::getSharedInstance().getPitch(
        0 + Pitch::octaveAdjustment(-4));

    static Pitch CS1 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(-4));

    static Pitch Db1 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(-4));

    static Pitch D1 = PitchFactory::getSharedInstance().getPitch(
        2 + Pitch::octaveAdjustment(-4));

    static Pitch DS1 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(-4));

    static Pitch Eb1 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(-4));

    static Pitch E1 = PitchFactory::getSharedInstance().getPitch(
        4 + Pitch::octaveAdjustment(-4));

    static Pitch F1 = PitchFactory::getSharedInstance().getPitch(
        5 + Pitch::octaveAdjustment(-4));

    static Pitch FS1 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(-4));

    static Pitch Gb1 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(-4));

    static Pitch G1 = PitchFactory::getSharedInstance().getPitch(
        7 + Pitch::octaveAdjustment(-4));

    static Pitch GS1 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(-4));

    static Pitch Ab1 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(-4));

    static Pitch A1 = PitchFactory::getSharedInstance().getPitch(
        9 + Pitch::octaveAdjustment(-4));

    static Pitch AS1 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(-4));

    static Pitch Bb1 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(-4));

    static Pitch B1 = PitchFactory::getSharedInstance().getPitch(
        11 + Pitch::octaveAdjustment(-4));

    static Pitch C2 = PitchFactory::getSharedInstance().getPitch(
        0 + Pitch::octaveAdjustment(-3));

    static Pitch CS2 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(-3));

    static Pitch Db2 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(-3));

    static Pitch D2 = PitchFactory::getSharedInstance().getPitch(
        2 + Pitch::octaveAdjustment(-3));

    static Pitch DS2 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(-3));

    static Pitch Eb2 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(-3));

    static Pitch E2 = PitchFactory::getSharedInstance().getPitch(
        4 + Pitch::octaveAdjustment(-3));

    static Pitch F2 = PitchFactory::getSharedInstance().getPitch(
        5 + Pitch::octaveAdjustment(-3));

    static Pitch FS2 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(-3));

    static Pitch Gb2 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(-3));

    static Pitch G2 = PitchFactory::getSharedInstance().getPitch(
        7 + Pitch::octaveAdjustment(-3));

    static Pitch GS2 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(-3));

    static Pitch Ab2 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(-3));

    static Pitch A2 = PitchFactory::getSharedInstance().getPitch(
        9 + Pitch::octaveAdjustment(-3));

    static Pitch AS2 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(-3));

    static Pitch Bb2 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(-3));

    static Pitch B2 = PitchFactory::getSharedInstance().getPitch(
        11 + Pitch::octaveAdjustment(-3));

    static Pitch C3 = PitchFactory::getSharedInstance().getPitch(
        0 + Pitch::octaveAdjustment(-2));

    static Pitch CS3 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(-2));

    static Pitch Db3 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(-2));

    static Pitch D3 = PitchFactory::getSharedInstance().getPitch(
        2 + Pitch::octaveAdjustment(-2));

    static Pitch DS3 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(-2));

    static Pitch Eb3 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(-2));

    static Pitch E3 = PitchFactory::getSharedInstance().getPitch(
        4 + Pitch::octaveAdjustment(-2));

    static Pitch F3 = PitchFactory::getSharedInstance().getPitch(
        5 + Pitch::octaveAdjustment(-2));

    static Pitch FS3 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(-2));

    static Pitch Gb3 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(-2));

    static Pitch G3 = PitchFactory::getSharedInstance().getPitch(
        7 + Pitch::octaveAdjustment(-2));

    static Pitch GS3 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(-2));

    static Pitch Ab3 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(-2));

    static Pitch A3 = PitchFactory::getSharedInstance().getPitch(
        9 + Pitch::octaveAdjustment(-2));

    static Pitch AS3 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(-2));

    static Pitch Bb3 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(-2));

    static Pitch B3 = PitchFactory::getSharedInstance().getPitch(
        11 + Pitch::octaveAdjustment(-2));

    static Pitch C4 = PitchFactory::getSharedInstance().getPitch(
        0 + Pitch::octaveAdjustment(-1));

    static Pitch CS4 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(-1));

    static Pitch Db4 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(-1));

    static Pitch D4 = PitchFactory::getSharedInstance().getPitch(
        2 + Pitch::octaveAdjustment(-1));

    static Pitch DS4 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(-1));

    static Pitch Eb4 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(-1));

    static Pitch E4 = PitchFactory::getSharedInstance().getPitch(
        4 + Pitch::octaveAdjustment(-1));

    static Pitch F4 = PitchFactory::getSharedInstance().getPitch(
        5 + Pitch::octaveAdjustment(-1));

    static Pitch FS4 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(-1));

    static Pitch Gb4 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(-1));

    static Pitch G4 = PitchFactory::getSharedInstance().getPitch(
        7 + Pitch::octaveAdjustment(-1));

    static Pitch GS4 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(-1));

    static Pitch Ab4 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(-1));

    static Pitch A4 = PitchFactory::getSharedInstance().getPitch(
        9 + Pitch::octaveAdjustment(-1));

    static Pitch AS4 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(-1));

    static Pitch Bb4 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(-1));

    static Pitch B4 = PitchFactory::getSharedInstance().getPitch(
        11 + Pitch::octaveAdjustment(-1));

    static Pitch C5 = PitchFactory::getSharedInstance().getPitch(
        0 + Pitch::octaveAdjustment(0));

    static Pitch CS5 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(0));

    static Pitch Db5 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(0));

    static Pitch D5 = PitchFactory::getSharedInstance().getPitch(
        2 + Pitch::octaveAdjustment(0));

    static Pitch DS5 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(0));

    static Pitch Eb5 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(0));

    static Pitch E5 = PitchFactory::getSharedInstance().getPitch(
        4 + Pitch::octaveAdjustment(0));

    static Pitch F5 = PitchFactory::getSharedInstance().getPitch(
        5 + Pitch::octaveAdjustment(0));

    static Pitch FS5 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(0));

    static Pitch Gb5 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(0));

    static Pitch G5 = PitchFactory::getSharedInstance().getPitch(
        7 + Pitch::octaveAdjustment(0));

    static Pitch GS5 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(0));

    static Pitch Ab5 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(0));

    // static Pitch A5 = PitchFactory::getSharedInstance().getPitch(
    //     9 + Pitch::octaveAdjustment(0));

    static Pitch AS5 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(0));

    static Pitch Bb5 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(0));

    static Pitch B5 = PitchFactory::getSharedInstance().getPitch(
        11 + Pitch::octaveAdjustment(0));

    static Pitch C6 = PitchFactory::getSharedInstance().getPitch(
        0 + Pitch::octaveAdjustment(1));

    static Pitch CS6 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(1));

    static Pitch Db6 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(1));

    static Pitch D6 = PitchFactory::getSharedInstance().getPitch(
        2 + Pitch::octaveAdjustment(1));

    static Pitch DS6 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(1));

    static Pitch Eb6 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(1));

    static Pitch E6 = PitchFactory::getSharedInstance().getPitch(
        4 + Pitch::octaveAdjustment(1));

    static Pitch F6 = PitchFactory::getSharedInstance().getPitch(
        5 + Pitch::octaveAdjustment(1));

    static Pitch FS6 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(1));

    static Pitch Gb6 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(1));

    static Pitch G6 = PitchFactory::getSharedInstance().getPitch(
        7 + Pitch::octaveAdjustment(1));

    static Pitch GS6 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(1));

    static Pitch Ab6 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(1));

    static Pitch A6 = PitchFactory::getSharedInstance().getPitch(
        9 + Pitch::octaveAdjustment(1));

    static Pitch AS6 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(1));

    static Pitch Bb6 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(1));

    static Pitch B6 = PitchFactory::getSharedInstance().getPitch(
        11 + Pitch::octaveAdjustment(1));

    static Pitch C7 = PitchFactory::getSharedInstance().getPitch(
        0 + Pitch::octaveAdjustment(2));

    static Pitch CS7 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(2));

    static Pitch Db7 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(2));

    static Pitch D7 = PitchFactory::getSharedInstance().getPitch(
        2 + Pitch::octaveAdjustment(2));

    static Pitch DS7 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(2));

    static Pitch Eb7 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(2));

    static Pitch E7 = PitchFactory::getSharedInstance().getPitch(
        4 + Pitch::octaveAdjustment(2));

    static Pitch F7 = PitchFactory::getSharedInstance().getPitch(
        5 + Pitch::octaveAdjustment(2));

    static Pitch FS7 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(2));

    static Pitch Gb7 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(2));

    static Pitch G7 = PitchFactory::getSharedInstance().getPitch(
        7 + Pitch::octaveAdjustment(2));

    static Pitch GS7 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(2));

    static Pitch Ab7 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(2));

    static Pitch A7 = PitchFactory::getSharedInstance().getPitch(
        9 + Pitch::octaveAdjustment(2));

    static Pitch AS7 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(2));

    static Pitch Bb7 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(2));

    static Pitch B7 = PitchFactory::getSharedInstance().getPitch(
        11 + Pitch::octaveAdjustment(2));

    static Pitch C8 = PitchFactory::getSharedInstance().getPitch(
        0 + Pitch::octaveAdjustment(3));

    static Pitch CS8 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(3));

    static Pitch Db8 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(3));

    static Pitch D8 = PitchFactory::getSharedInstance().getPitch(
        2 + Pitch::octaveAdjustment(3));

    static Pitch DS8 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(3));

    static Pitch Eb8 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(3));

    static Pitch E8 = PitchFactory::getSharedInstance().getPitch(
        4 + Pitch::octaveAdjustment(3));

    static Pitch F8 = PitchFactory::getSharedInstance().getPitch(
        5 + Pitch::octaveAdjustment(3));

    static Pitch FS8 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(3));

    static Pitch Gb8 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(3));

    static Pitch G8 = PitchFactory::getSharedInstance().getPitch(
        7 + Pitch::octaveAdjustment(3));

    static Pitch GS8 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(3));

    static Pitch Ab8 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(3));

    static Pitch A8 = PitchFactory::getSharedInstance().getPitch(
        9 + Pitch::octaveAdjustment(3));

    static Pitch AS8 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(3));

    static Pitch Bb8 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(3));

    static Pitch B8 = PitchFactory::getSharedInstance().getPitch(
        11 + Pitch::octaveAdjustment(3));

    static Pitch C9 = PitchFactory::getSharedInstance().getPitch(
        0 + Pitch::octaveAdjustment(4));

    static Pitch CS9 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(4));

    static Pitch Db9 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(4));

    static Pitch D9 = PitchFactory::getSharedInstance().getPitch(
        2 + Pitch::octaveAdjustment(4));

    static Pitch DS9 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(4));

    static Pitch Eb9 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(4));

    static Pitch E9 = PitchFactory::getSharedInstance().getPitch(
        4 + Pitch::octaveAdjustment(4));

    static Pitch F9 = PitchFactory::getSharedInstance().getPitch(
        5 + Pitch::octaveAdjustment(4));

    static Pitch FS9 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(4));

    static Pitch Gb9 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(4));

    static Pitch G9 = PitchFactory::getSharedInstance().getPitch(
        7 + Pitch::octaveAdjustment(4));

    static Pitch GS9 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(4));

    static Pitch Ab9 = PitchFactory::getSharedInstance().getPitch(
        8 + Pitch::octaveAdjustment(4));

    static Pitch A9 = PitchFactory::getSharedInstance().getPitch(
        9 + Pitch::octaveAdjustment(4));

    static Pitch AS9 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(4));

    static Pitch Bb9 = PitchFactory::getSharedInstance().getPitch(
        10 + Pitch::octaveAdjustment(4));

    static Pitch B9 = PitchFactory::getSharedInstance().getPitch(
        11 + Pitch::octaveAdjustment(4));

    static Pitch C10 = PitchFactory::getSharedInstance().getPitch(
        0 + Pitch::octaveAdjustment(5));

    static Pitch CS10 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(5));

    static Pitch Db10 = PitchFactory::getSharedInstance().getPitch(
        1 + Pitch::octaveAdjustment(5));

    static Pitch D10 = PitchFactory::getSharedInstance().getPitch(
        2 + Pitch::octaveAdjustment(5));

    static Pitch DS10 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(5));

    static Pitch Eb10 = PitchFactory::getSharedInstance().getPitch(
        3 + Pitch::octaveAdjustment(5));

    static Pitch E10 = PitchFactory::getSharedInstance().getPitch(
        4 + Pitch::octaveAdjustment(5));

    static Pitch F10 = PitchFactory::getSharedInstance().getPitch(
        5 + Pitch::octaveAdjustment(5));

    static Pitch FS10 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(5));

    static Pitch Gb10 = PitchFactory::getSharedInstance().getPitch(
        6 + Pitch::octaveAdjustment(5));

    static Pitch G10 = PitchFactory::getSharedInstance().getPitch(
        7 + Pitch::octaveAdjustment(5));

} // namespace gdmusickit
