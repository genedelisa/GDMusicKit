// -*- C++ -*-
/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License.
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/

#include <cmath>
#include <iostream>

//#include <gdmusickit/Pitch.hpp>
#include "gdmusickit/Pitch.hpp"
#include "gdmusickit/PitchFactory.hpp"
#include "gdmusickit/PitchStringParser.hpp"

namespace gdmusickit {

    /**
     * @brief Construct a new Pitch object
     * 
     * @param midiNumber 
     */
    Pitch::Pitch(int midiNumber) {
        this->midiNumber = midiNumber;
        this->frequency = midiEqualTemperamentFrequency(midiNumber);
    }

    
    Pitch::Pitch(const std::string& pitchString) {
        this->midiNumber = PitchStringParser::stringToMidiNumber(pitchString);
        this->frequency = midiEqualTemperamentFrequency(midiNumber);
    }

    int Pitch::pitchClass() const { return midiNumber % 12; }

    int Pitch::octave() const { return midiNumber / 12; }

    int Pitch::midiPitchNumber() const { return midiNumber; }

    // constexpr auto URL_PATTERN =
    //     "(http|https)://(\\w+\\.)+(\\w)/?(\\w+/{0,1})*";

    std::ostream& operator<<(std::ostream& os, const Pitch& pitch) {
        return os << "MIDI number: " << pitch.midiNumber;
    }

    /**
         @brief Calculate the frequency in Hz for a given Pitch
         @return: the frequency in Hz of the Pitch
    */
    double Pitch::midiEqualTemperamentFrequency(int midiNumber) {
        // 69 is midinumber for A5, 440 is that fq
        // do not use Pitch::A5.midiNumber since this is referenced from the
        // ctor
        int a440 = 69;
        if (Pitch::octaveForMiddleC == 5) {
            int offset = 5 - Pitch::octaveForMiddleC;
            a440 = 69 - (offset * 12);
        }
        // log.debug("using midinumber \(a440) as A 440")
        return 440.0 *
               std::pow(2.0, (static_cast<double>(midiNumber - a440) / 12.0));
    }

#pragma region Pitch constants
    const Pitch* Pitch::C0 = PitchFactory::getSharedInstance().getPitch(
        0 +
        Pitch::octaveAdjustment(-5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::CS0 = PitchFactory::getSharedInstance().getPitch(
        1 +
        Pitch::octaveAdjustment(-5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Db0 = PitchFactory::getSharedInstance().getPitch(
        1 +
        Pitch::octaveAdjustment(-5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::D0 = PitchFactory::getSharedInstance().getPitch(
        2 +
        Pitch::octaveAdjustment(-5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::DS0 = PitchFactory::getSharedInstance().getPitch(
        3 +
        Pitch::octaveAdjustment(-5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Eb0 = PitchFactory::getSharedInstance().getPitch(
        3 +
        Pitch::octaveAdjustment(-5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::E0 = PitchFactory::getSharedInstance().getPitch(
        4 +
        Pitch::octaveAdjustment(-5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::F0 = PitchFactory::getSharedInstance().getPitch(
        5 +
        Pitch::octaveAdjustment(-5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::FS0 = PitchFactory::getSharedInstance().getPitch(
        6 +
        Pitch::octaveAdjustment(-5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Gb0 = PitchFactory::getSharedInstance().getPitch(
        6 +
        Pitch::octaveAdjustment(-5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::G0 = PitchFactory::getSharedInstance().getPitch(
        7 +
        Pitch::octaveAdjustment(-5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::GS0 = PitchFactory::getSharedInstance().getPitch(
        8 +
        Pitch::octaveAdjustment(-5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Ab0 = PitchFactory::getSharedInstance().getPitch(
        8 +
        Pitch::octaveAdjustment(-5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::A0 = PitchFactory::getSharedInstance().getPitch(
        9 +
        Pitch::octaveAdjustment(-5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::AS0 = PitchFactory::getSharedInstance().getPitch(
        10 +
        Pitch::octaveAdjustment(-5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Bb0 = PitchFactory::getSharedInstance().getPitch(
        10 +
        Pitch::octaveAdjustment(-5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::B0 = PitchFactory::getSharedInstance().getPitch(
        11 +
        Pitch::octaveAdjustment(-5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::C1 = PitchFactory::getSharedInstance().getPitch(
        0 +
        Pitch::octaveAdjustment(-4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::CS1 = PitchFactory::getSharedInstance().getPitch(
        1 +
        Pitch::octaveAdjustment(-4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Db1 = PitchFactory::getSharedInstance().getPitch(
        1 +
        Pitch::octaveAdjustment(-4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::D1 = PitchFactory::getSharedInstance().getPitch(
        2 +
        Pitch::octaveAdjustment(-4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::DS1 = PitchFactory::getSharedInstance().getPitch(
        3 +
        Pitch::octaveAdjustment(-4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Eb1 = PitchFactory::getSharedInstance().getPitch(
        3 +
        Pitch::octaveAdjustment(-4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::E1 = PitchFactory::getSharedInstance().getPitch(
        4 +
        Pitch::octaveAdjustment(-4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::F1 = PitchFactory::getSharedInstance().getPitch(
        5 +
        Pitch::octaveAdjustment(-4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::FS1 = PitchFactory::getSharedInstance().getPitch(
        6 +
        Pitch::octaveAdjustment(-4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Gb1 = PitchFactory::getSharedInstance().getPitch(
        6 +
        Pitch::octaveAdjustment(-4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::G1 = PitchFactory::getSharedInstance().getPitch(
        7 +
        Pitch::octaveAdjustment(-4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::GS1 = PitchFactory::getSharedInstance().getPitch(
        8 +
        Pitch::octaveAdjustment(-4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Ab1 = PitchFactory::getSharedInstance().getPitch(
        8 +
        Pitch::octaveAdjustment(-4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::A1 = PitchFactory::getSharedInstance().getPitch(
        9 +
        Pitch::octaveAdjustment(-4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::AS1 = PitchFactory::getSharedInstance().getPitch(
        10 +
        Pitch::octaveAdjustment(-4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Bb1 = PitchFactory::getSharedInstance().getPitch(
        10 +
        Pitch::octaveAdjustment(-4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::B1 = PitchFactory::getSharedInstance().getPitch(
        11 +
        Pitch::octaveAdjustment(-4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::C2 = PitchFactory::getSharedInstance().getPitch(
        0 +
        Pitch::octaveAdjustment(-3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::CS2 = PitchFactory::getSharedInstance().getPitch(
        1 +
        Pitch::octaveAdjustment(-3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Db2 = PitchFactory::getSharedInstance().getPitch(
        1 +
        Pitch::octaveAdjustment(-3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::D2 = PitchFactory::getSharedInstance().getPitch(
        2 +
        Pitch::octaveAdjustment(-3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::DS2 = PitchFactory::getSharedInstance().getPitch(
        3 +
        Pitch::octaveAdjustment(-3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Eb2 = PitchFactory::getSharedInstance().getPitch(
        3 +
        Pitch::octaveAdjustment(-3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::E2 = PitchFactory::getSharedInstance().getPitch(
        4 +
        Pitch::octaveAdjustment(-3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::F2 = PitchFactory::getSharedInstance().getPitch(
        5 +
        Pitch::octaveAdjustment(-3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::FS2 = PitchFactory::getSharedInstance().getPitch(
        6 +
        Pitch::octaveAdjustment(-3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Gb2 = PitchFactory::getSharedInstance().getPitch(
        6 +
        Pitch::octaveAdjustment(-3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::G2 = PitchFactory::getSharedInstance().getPitch(
        7 +
        Pitch::octaveAdjustment(-3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::GS2 = PitchFactory::getSharedInstance().getPitch(
        8 +
        Pitch::octaveAdjustment(-3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Ab2 = PitchFactory::getSharedInstance().getPitch(
        8 +
        Pitch::octaveAdjustment(-3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::A2 = PitchFactory::getSharedInstance().getPitch(
        9 +
        Pitch::octaveAdjustment(-3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::AS2 = PitchFactory::getSharedInstance().getPitch(
        10 +
        Pitch::octaveAdjustment(-3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Bb2 = PitchFactory::getSharedInstance().getPitch(
        10 +
        Pitch::octaveAdjustment(-3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::B2 = PitchFactory::getSharedInstance().getPitch(
        11 +
        Pitch::octaveAdjustment(-3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::C3 = PitchFactory::getSharedInstance().getPitch(
        0 +
        Pitch::octaveAdjustment(-2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::CS3 = PitchFactory::getSharedInstance().getPitch(
        1 +
        Pitch::octaveAdjustment(-2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Db3 = PitchFactory::getSharedInstance().getPitch(
        1 +
        Pitch::octaveAdjustment(-2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::D3 = PitchFactory::getSharedInstance().getPitch(
        2 +
        Pitch::octaveAdjustment(-2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::DS3 = PitchFactory::getSharedInstance().getPitch(
        3 +
        Pitch::octaveAdjustment(-2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Eb3 = PitchFactory::getSharedInstance().getPitch(
        3 +
        Pitch::octaveAdjustment(-2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::E3 = PitchFactory::getSharedInstance().getPitch(
        4 +
        Pitch::octaveAdjustment(-2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::F3 = PitchFactory::getSharedInstance().getPitch(
        5 +
        Pitch::octaveAdjustment(-2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::FS3 = PitchFactory::getSharedInstance().getPitch(
        6 +
        Pitch::octaveAdjustment(-2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Gb3 = PitchFactory::getSharedInstance().getPitch(
        6 +
        Pitch::octaveAdjustment(-2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::G3 = PitchFactory::getSharedInstance().getPitch(
        7 +
        Pitch::octaveAdjustment(-2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::GS3 = PitchFactory::getSharedInstance().getPitch(
        8 +
        Pitch::octaveAdjustment(-2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Ab3 = PitchFactory::getSharedInstance().getPitch(
        8 +
        Pitch::octaveAdjustment(-2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::A3 = PitchFactory::getSharedInstance().getPitch(
        9 +
        Pitch::octaveAdjustment(-2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::AS3 = PitchFactory::getSharedInstance().getPitch(
        10 +
        Pitch::octaveAdjustment(-2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Bb3 = PitchFactory::getSharedInstance().getPitch(
        10 +
        Pitch::octaveAdjustment(-2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::B3 = PitchFactory::getSharedInstance().getPitch(
        11 +
        Pitch::octaveAdjustment(-2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::C4 = PitchFactory::getSharedInstance().getPitch(
        0 +
        Pitch::octaveAdjustment(-1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::CS4 = PitchFactory::getSharedInstance().getPitch(
        1 +
        Pitch::octaveAdjustment(-1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Db4 = PitchFactory::getSharedInstance().getPitch(
        1 +
        Pitch::octaveAdjustment(-1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::D4 = PitchFactory::getSharedInstance().getPitch(
        2 +
        Pitch::octaveAdjustment(-1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::DS4 = PitchFactory::getSharedInstance().getPitch(
        3 +
        Pitch::octaveAdjustment(-1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Eb4 = PitchFactory::getSharedInstance().getPitch(
        3 +
        Pitch::octaveAdjustment(-1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::E4 = PitchFactory::getSharedInstance().getPitch(
        4 +
        Pitch::octaveAdjustment(-1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::F4 = PitchFactory::getSharedInstance().getPitch(
        5 +
        Pitch::octaveAdjustment(-1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::FS4 = PitchFactory::getSharedInstance().getPitch(
        6 +
        Pitch::octaveAdjustment(-1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Gb4 = PitchFactory::getSharedInstance().getPitch(
        6 +
        Pitch::octaveAdjustment(-1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::G4 = PitchFactory::getSharedInstance().getPitch(
        7 +
        Pitch::octaveAdjustment(-1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::GS4 = PitchFactory::getSharedInstance().getPitch(
        8 +
        Pitch::octaveAdjustment(-1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Ab4 = PitchFactory::getSharedInstance().getPitch(
        8 +
        Pitch::octaveAdjustment(-1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::A4 = PitchFactory::getSharedInstance().getPitch(
        9 +
        Pitch::octaveAdjustment(-1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::AS4 = PitchFactory::getSharedInstance().getPitch(
        10 +
        Pitch::octaveAdjustment(-1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Bb4 = PitchFactory::getSharedInstance().getPitch(
        10 +
        Pitch::octaveAdjustment(-1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::B4 = PitchFactory::getSharedInstance().getPitch(
        11 +
        Pitch::octaveAdjustment(-1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::C5 = PitchFactory::getSharedInstance().getPitch(
        0 +
        Pitch::octaveAdjustment(0)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::CS5 = PitchFactory::getSharedInstance().getPitch(
        1 +
        Pitch::octaveAdjustment(0)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Db5 = PitchFactory::getSharedInstance().getPitch(
        1 +
        Pitch::octaveAdjustment(0)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::D5 = PitchFactory::getSharedInstance().getPitch(
        2 +
        Pitch::octaveAdjustment(0)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::DS5 = PitchFactory::getSharedInstance().getPitch(
        3 +
        Pitch::octaveAdjustment(0)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Eb5 = PitchFactory::getSharedInstance().getPitch(
        3 +
        Pitch::octaveAdjustment(0)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::E5 = PitchFactory::getSharedInstance().getPitch(
        4 +
        Pitch::octaveAdjustment(0)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::F5 = PitchFactory::getSharedInstance().getPitch(
        5 +
        Pitch::octaveAdjustment(0)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::FS5 = PitchFactory::getSharedInstance().getPitch(
        6 +
        Pitch::octaveAdjustment(0)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Gb5 = PitchFactory::getSharedInstance().getPitch(
        6 +
        Pitch::octaveAdjustment(0)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::G5 = PitchFactory::getSharedInstance().getPitch(
        7 +
        Pitch::octaveAdjustment(0)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::GS5 = PitchFactory::getSharedInstance().getPitch(
        8 +
        Pitch::octaveAdjustment(0)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Ab5 = PitchFactory::getSharedInstance().getPitch(
        8 +
        Pitch::octaveAdjustment(0)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::A5 = PitchFactory::getSharedInstance().getPitch(
        9 +
        Pitch::octaveAdjustment(0)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::AS5 = PitchFactory::getSharedInstance().getPitch(
        10 +
        Pitch::octaveAdjustment(0)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Bb5 = PitchFactory::getSharedInstance().getPitch(
        10 +
        Pitch::octaveAdjustment(0)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::B5 = PitchFactory::getSharedInstance().getPitch(
        11 +
        Pitch::octaveAdjustment(0)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::C6 = PitchFactory::getSharedInstance().getPitch(
        0 +
        Pitch::octaveAdjustment(1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::CS6 = PitchFactory::getSharedInstance().getPitch(
        1 +
        Pitch::octaveAdjustment(1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Db6 = PitchFactory::getSharedInstance().getPitch(
        1 +
        Pitch::octaveAdjustment(1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::D6 = PitchFactory::getSharedInstance().getPitch(
        2 +
        Pitch::octaveAdjustment(1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::DS6 = PitchFactory::getSharedInstance().getPitch(
        3 +
        Pitch::octaveAdjustment(1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Eb6 = PitchFactory::getSharedInstance().getPitch(
        3 +
        Pitch::octaveAdjustment(1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::E6 = PitchFactory::getSharedInstance().getPitch(
        4 +
        Pitch::octaveAdjustment(1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::F6 = PitchFactory::getSharedInstance().getPitch(
        5 +
        Pitch::octaveAdjustment(1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::FS6 = PitchFactory::getSharedInstance().getPitch(
        6 +
        Pitch::octaveAdjustment(1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Gb6 = PitchFactory::getSharedInstance().getPitch(
        6 +
        Pitch::octaveAdjustment(1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::G6 = PitchFactory::getSharedInstance().getPitch(
        7 +
        Pitch::octaveAdjustment(1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::GS6 = PitchFactory::getSharedInstance().getPitch(
        8 +
        Pitch::octaveAdjustment(1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Ab6 = PitchFactory::getSharedInstance().getPitch(
        8 +
        Pitch::octaveAdjustment(1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::A6 = PitchFactory::getSharedInstance().getPitch(
        9 +
        Pitch::octaveAdjustment(1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::AS6 = PitchFactory::getSharedInstance().getPitch(
        10 +
        Pitch::octaveAdjustment(1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Bb6 = PitchFactory::getSharedInstance().getPitch(
        10 +
        Pitch::octaveAdjustment(1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::B6 = PitchFactory::getSharedInstance().getPitch(
        11 +
        Pitch::octaveAdjustment(1)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::C7 = PitchFactory::getSharedInstance().getPitch(
        0 +
        Pitch::octaveAdjustment(2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::CS7 = PitchFactory::getSharedInstance().getPitch(
        1 +
        Pitch::octaveAdjustment(2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Db7 = PitchFactory::getSharedInstance().getPitch(
        1 +
        Pitch::octaveAdjustment(2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::D7 = PitchFactory::getSharedInstance().getPitch(
        2 +
        Pitch::octaveAdjustment(2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::DS7 = PitchFactory::getSharedInstance().getPitch(
        3 +
        Pitch::octaveAdjustment(2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Eb7 = PitchFactory::getSharedInstance().getPitch(
        3 +
        Pitch::octaveAdjustment(2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::E7 = PitchFactory::getSharedInstance().getPitch(
        4 +
        Pitch::octaveAdjustment(2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::F7 = PitchFactory::getSharedInstance().getPitch(
        5 +
        Pitch::octaveAdjustment(2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::FS7 = PitchFactory::getSharedInstance().getPitch(
        6 +
        Pitch::octaveAdjustment(2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Gb7 = PitchFactory::getSharedInstance().getPitch(
        6 +
        Pitch::octaveAdjustment(2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::G7 = PitchFactory::getSharedInstance().getPitch(
        7 +
        Pitch::octaveAdjustment(2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::GS7 = PitchFactory::getSharedInstance().getPitch(
        8 +
        Pitch::octaveAdjustment(2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Ab7 = PitchFactory::getSharedInstance().getPitch(
        8 +
        Pitch::octaveAdjustment(2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::A7 = PitchFactory::getSharedInstance().getPitch(
        9 +
        Pitch::octaveAdjustment(2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::AS7 = PitchFactory::getSharedInstance().getPitch(
        10 +
        Pitch::octaveAdjustment(2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Bb7 = PitchFactory::getSharedInstance().getPitch(
        10 +
        Pitch::octaveAdjustment(2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::B7 = PitchFactory::getSharedInstance().getPitch(
        11 +
        Pitch::octaveAdjustment(2)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::C8 = PitchFactory::getSharedInstance().getPitch(
        0 +
        Pitch::octaveAdjustment(3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::CS8 = PitchFactory::getSharedInstance().getPitch(
        1 +
        Pitch::octaveAdjustment(3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Db8 = PitchFactory::getSharedInstance().getPitch(
        1 +
        Pitch::octaveAdjustment(3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::D8 = PitchFactory::getSharedInstance().getPitch(
        2 +
        Pitch::octaveAdjustment(3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::DS8 = PitchFactory::getSharedInstance().getPitch(
        3 +
        Pitch::octaveAdjustment(3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Eb8 = PitchFactory::getSharedInstance().getPitch(
        3 +
        Pitch::octaveAdjustment(3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::E8 = PitchFactory::getSharedInstance().getPitch(
        4 +
        Pitch::octaveAdjustment(3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::F8 = PitchFactory::getSharedInstance().getPitch(
        5 +
        Pitch::octaveAdjustment(3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::FS8 = PitchFactory::getSharedInstance().getPitch(
        6 +
        Pitch::octaveAdjustment(3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Gb8 = PitchFactory::getSharedInstance().getPitch(
        6 +
        Pitch::octaveAdjustment(3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::G8 = PitchFactory::getSharedInstance().getPitch(
        7 +
        Pitch::octaveAdjustment(3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::GS8 = PitchFactory::getSharedInstance().getPitch(
        8 +
        Pitch::octaveAdjustment(3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Ab8 = PitchFactory::getSharedInstance().getPitch(
        8 +
        Pitch::octaveAdjustment(3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::A8 = PitchFactory::getSharedInstance().getPitch(
        9 +
        Pitch::octaveAdjustment(3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::AS8 = PitchFactory::getSharedInstance().getPitch(
        10 +
        Pitch::octaveAdjustment(3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Bb8 = PitchFactory::getSharedInstance().getPitch(
        10 +
        Pitch::octaveAdjustment(3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::B8 = PitchFactory::getSharedInstance().getPitch(
        11 +
        Pitch::octaveAdjustment(3)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::C9 = PitchFactory::getSharedInstance().getPitch(
        0 +
        Pitch::octaveAdjustment(4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::CS9 = PitchFactory::getSharedInstance().getPitch(
        1 +
        Pitch::octaveAdjustment(4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Db9 = PitchFactory::getSharedInstance().getPitch(
        1 +
        Pitch::octaveAdjustment(4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::D9 = PitchFactory::getSharedInstance().getPitch(
        2 +
        Pitch::octaveAdjustment(4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::DS9 = PitchFactory::getSharedInstance().getPitch(
        3 +
        Pitch::octaveAdjustment(4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Eb9 = PitchFactory::getSharedInstance().getPitch(
        3 +
        Pitch::octaveAdjustment(4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::E9 = PitchFactory::getSharedInstance().getPitch(
        4 +
        Pitch::octaveAdjustment(4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::F9 = PitchFactory::getSharedInstance().getPitch(
        5 +
        Pitch::octaveAdjustment(4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::FS9 = PitchFactory::getSharedInstance().getPitch(
        6 +
        Pitch::octaveAdjustment(4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Gb9 = PitchFactory::getSharedInstance().getPitch(
        6 +
        Pitch::octaveAdjustment(4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::G9 = PitchFactory::getSharedInstance().getPitch(
        7 +
        Pitch::octaveAdjustment(4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::GS9 = PitchFactory::getSharedInstance().getPitch(
        8 +
        Pitch::octaveAdjustment(4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Ab9 = PitchFactory::getSharedInstance().getPitch(
        8 +
        Pitch::octaveAdjustment(4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::A9 = PitchFactory::getSharedInstance().getPitch(
        9 +
        Pitch::octaveAdjustment(4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::AS9 = PitchFactory::getSharedInstance().getPitch(
        10 +
        Pitch::octaveAdjustment(4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Bb9 = PitchFactory::getSharedInstance().getPitch(
        10 +
        Pitch::octaveAdjustment(4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::B9 = PitchFactory::getSharedInstance().getPitch(
        11 +
        Pitch::octaveAdjustment(4)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::C10 = PitchFactory::getSharedInstance().getPitch(
        0 +
        Pitch::octaveAdjustment(5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::CS10 = PitchFactory::getSharedInstance().getPitch(
        1 +
        Pitch::octaveAdjustment(5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Db10 = PitchFactory::getSharedInstance().getPitch(
        1 +
        Pitch::octaveAdjustment(5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::D10 = PitchFactory::getSharedInstance().getPitch(
        2 +
        Pitch::octaveAdjustment(5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::DS10 = PitchFactory::getSharedInstance().getPitch(
        3 +
        Pitch::octaveAdjustment(5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Eb10 = PitchFactory::getSharedInstance().getPitch(
        3 +
        Pitch::octaveAdjustment(5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::E10 = PitchFactory::getSharedInstance().getPitch(
        4 +
        Pitch::octaveAdjustment(5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::F10 = PitchFactory::getSharedInstance().getPitch(
        5 +
        Pitch::octaveAdjustment(5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::FS10 = PitchFactory::getSharedInstance().getPitch(
        6 +
        Pitch::octaveAdjustment(5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::Gb10 = PitchFactory::getSharedInstance().getPitch(
        6 +
        Pitch::octaveAdjustment(5)); // NOLINT(readability-identifier-naming)

    const Pitch* Pitch::G10 = PitchFactory::getSharedInstance().getPitch(
        7 +
        Pitch::octaveAdjustment(5)); // NOLINT(readability-identifier-naming)

#pragma endregion Pitch constants

} // namespace gdmusickit
