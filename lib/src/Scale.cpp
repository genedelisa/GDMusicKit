// -*- C++ -*-
/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License.
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/

#include "gdmusickit/gdmusickit.h"

#include <algorithm>
#include <exception>
#include <iostream>
#include <string>

namespace gdmusickit {

    // const Scale Scale::major = Scale("Major", {2, 2, 1, 2, 2, 2, 1});
    // const Scale Scale::symmetricalDecatonic =
    //     Scale("Symmetrical Decatonic", {1, 1, 2, 1, 1, 1, 1, 2, 1, 1});

    // const std::map<std::string, const Scale> Scale::scaleMap = {
    //     std::pair<std::string, const Scale>("Major", major),
    //     std::pair<std::string, const Scale>("Symmetrical Decatonic",
    //                                         symmetricalDecatonic)};

    std::vector<Pitch*> Scale::pitchesFromIntervals(int root) {
        std::vector<Pitch*> pitches;
        Pitch* p        = PitchFactory::getSharedInstance().getPitch(root);
        Pitch* previous = p;

        pitches.emplace_back(p);

        for (const auto interval : intervals) {
            p = PitchFactory::getSharedInstance().getPitch(
                previous->midiPitchNumber() + interval);
            pitches.emplace_back(p);
            previous = p;
        }
        return pitches;
    }

    // Scale Constants

    const Scale Scale::Lydian = Scale("Lydian", {2, 2, 2, 1, 2, 2, 1},
                                      {0, 2, 4, 6, 7, 9, 11, 12}, "", "",
                                      {
                                          "Major/Minor",
                                          "Modal",
                                      });

    const Scale Scale::HarmonicMinor =
        Scale("Harmonic Minor", {2, 1, 2, 2, 1, 3, 1},
              {0, 2, 3, 5, 7, 8, 11, 12}, "", "",
              {
                  "Major/Minor",
                  "Modal",
              });

    const Scale Scale::Aeolian = Scale("Aeolian", {2, 1, 2, 2, 1, 2, 2},
                                       {0, 2, 3, 5, 7, 8, 10, 12}, "", "",
                                       {
                                           "Major/Minor",
                                           "Modal",
                                       });

    const Scale Scale::Persian =
        Scale("Persian", {1, 3, 1, 1, 2, 3, 1}, {0, 1, 4, 5, 6, 8, 11, 12},
              "1 b2 3 4 b5 b6 7 9", "", {});

    const Scale Scale::DoubleHarmonic =
        Scale("Double Harmonic", {1, 3, 1, 2, 1, 3, 1},
              {0, 1, 4, 5, 7, 8, 11, 12}, "1 b2 3 4 5 b6 7 8", "", {});

    const Scale Scale::Egyptian =
        Scale("Egyptian", {2, 3, 2, 3, 2}, {0, 2, 5, 7, 10, 12}, "1 2 4 5 b7 8",
              "", {});

    const Scale Scale::Mohammedan =
        Scale("Mohammedan", {2, 1, 2, 2, 1, 3, 1}, {0, 2, 3, 5, 7, 8, 11, 12},
              "1 2 b3 4 5 b6 7 8", "", {});

    const Scale Scale::MelodicMajor =
        Scale("Melodic Major", {2, 2, 1, 2, 1, 2, 2},
              {0, 2, 4, 5, 7, 8, 10, 12}, "", "",
              {
                  "Major/Minor",
                  "Modal",
              });

    const Scale Scale::Pelog2 =
        Scale("Pelog2", {1, 2, 4, 3, 2}, {0, 1, 3, 7, 10, 12}, "1 b2 b3 5 b7 8",
              "", {});

    const Scale Scale::TwoSemitoneTritone =
        Scale("Two Semitone Tritone", {1, 1, 4, 1, 1, 4},
              {0, 1, 2, 6, 7, 8, 12}, "", "",
              {
                  "Symmetrical",
              });

    const Scale Scale::Japanese = Scale(
        "Japanese", {1, 4, 2, 1, 4}, {0, 1, 5, 7, 8, 12}, "1 b2 4 5 b6 8", "",
        {
            "World",
        });

    const Scale Scale::MelodicMinor =
        Scale("Melodic Minor", {2, 1, 2, 2, 2, 2, 1, 2, 1, 2, 2, 1, 2, 2},
              {0, 2, 3, 5, 7, 9, 11, 12, 14, 15, 17, 19, 20, 22, 24},
              "1 2 b3 4 5 6 7 8", "different up and down",
              {
                  "Basic",
              });

    const Scale Scale::DiminishedDominant =
        Scale("Diminished Dominant", {1, 2, 1, 2, 1, 2, 1, 2},
              {0, 1, 3, 4, 6, 7, 9, 10, 12}, "1 b2 #2 3 #4 5 6 b7 8", "", {});

    const Scale Scale::Pelog = Scale(
        "Pelog", {3, 2, 2, 1, 2}, {0, 3, 5, 7, 8, 10}, "1 b3 4 #5 6 b7 8", "",
        {
            "World",
            "Gamelan",
        });

    const Scale Scale::Hawaiian =
        Scale("Hawaiian", {2, 1, 2, 2, 2, 2, 1}, {0, 2, 3, 5, 7, 9, 11, 12},
              "1 2 b3 4 5 6 7 8", "",
              {
                  "World",
              });

    const Scale Scale::Jewish =
        Scale("Jewish", {1, 3, 1, 2, 1, 2, 2}, {0, 1, 4, 5, 7, 8, 10, 12},
              "1 b2 3 4 5 b6 b7 8", "", {});

    const Scale Scale::Augmented =
        Scale("Augmented", {3, 1, 3, 1, 3, 1}, {0, 3, 4, 7, 8, 11, 12}, "", "",
              {
                  "Symmetrical",
              });

    const Scale Scale::HarmonicMajor =
        Scale("Harmonic Major", {2, 2, 1, 2, 1, 3, 1},
              {0, 2, 4, 5, 7, 8, 11, 12}, "1 2 3 4 5 b6 7 8", "", {});

    const Scale Scale::Overtone =
        Scale("Overtone", {2, 2, 2, 1, 2, 1, 2}, {0, 2, 4, 6, 7, 9, 10, 12},
              "1 2 3 #4 5 6 b7 8", "", {});

    const Scale Scale::HalfDiminished =
        Scale("Half Diminished", {2, 1, 2, 1, 2, 2, 2},
              {0, 2, 3, 5, 6, 8, 10, 12}, "", "",
              {
                  "Major/Minor",
                  "Modal",
              });

    const Scale Scale::PelogBarang = Scale(
        "Pelog Barang", {1, 4, 1, 2}, {0, 1, 5, 6, 8}, "1 b2 4 b5 b6 8", "",
        {
            "World",
            "Gamelan",
            "Pentatonic",
        });

    const Scale Scale::Tritone =
        Scale("Tritone", {1, 3, 2, 1, 3, 2}, {0, 1, 4, 6, 7, 10, 12}, "", "",
              {
                  "Symmetrical",
              });

    const Scale Scale::Messiaen4thModeInverse =
        Scale("Messiaen 4th Mode Inverse", {3, 1, 1, 1, 3, 1, 1, 1},
              {0, 3, 4, 5, 6, 9, 10, 11, 12}, "", "",
              {
                  "Symmetrical",
              });

    const Scale Scale::NeapolitanMinor =
        Scale("Neapolitan Minor", {1, 2, 2, 2, 1, 3, 1},
              {0, 1, 3, 5, 7, 8, 11, 12}, "1 b2 b3 4 5 b6 7 8", "", {});

    const Scale Scale::LydianMinor =
        Scale("Lydian Minor", {2, 2, 2, 1, 1, 2, 2}, {0, 2, 4, 6, 7, 8, 10, 12},
              "1 2 3 #4 5 b6 b7 8", "", {});

    const Scale Scale::OctatonicMode2 =
        Scale("Octatonic Mode 2", {1, 2, 1, 2, 1, 2, 1, 2},
              {0, 1, 3, 4, 6, 7, 9, 10, 12}, "1 b2 b3 3 b5 5 6 b7", "",
              {
                  "Basic",
              });

    const Scale Scale::Chromatic =
        Scale("Chromatic", {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
              {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, "", "",
              {
                  "Basic",
                  "Symmetrical",
              });

    const Scale Scale::MajorLocrian =
        Scale("Major Locrian", {2, 2, 1, 1, 2, 2, 2},
              {0, 2, 4, 5, 6, 8, 10, 12}, "1 2 3 4 b5 b6 b7 8", "", {});

    const Scale Scale::Balinese =
        Scale("Balinese", {1, 2, 4, 1, 4}, {0, 1, 3, 7, 8, 12},
              "1 b2 b3 5 b6 8", "", {});

    const Scale Scale::NeapolitanMajor =
        Scale("Neapolitan Major", {1, 2, 2, 2, 2, 2, 1},
              {0, 1, 3, 5, 7, 9, 11, 12}, "1 b2 b3 4 5 6 7 8", "", {});

    const Scale Scale::Oriental =
        Scale("Oriental", {1, 3, 1, 1, 3, 1, 2}, {0, 1, 4, 5, 6, 9, 10, 12},
              "1 b2 3 4 b5 6 b7 8", "", {});

    const Scale Scale::Arabian =
        Scale("Arabian", {2, 2, 1, 1, 2, 2, 2}, {0, 2, 4, 5, 6, 8, 10, 12},
              "1 2 3 4 b5 b6 b7 8", "", {});

    const Scale Scale::Hindu =
        Scale("Hindu", {2, 2, 1, 2, 1, 2, 2}, {0, 2, 4, 5, 7, 8, 10, 12},
              "1 2 3 4 5 b6 b7 8", "", {});

    const Scale Scale::PentatonicMinor =
        Scale("Pentatonic Minor", {3, 2, 2, 3, 2}, {0, 3, 5, 7, 10, 12},
              "1 b3 4 5 b7 8", "",
              {
                  "Basic",
                  "Pentatonic",
              });

    const Scale Scale::HungarianMinor =
        Scale("Hungarian Minor", {2, 1, 3, 1, 1, 3, 1},
              {0, 2, 3, 6, 7, 8, 11, 12}, "1 2 b3 #4 5 b6 7 8", "", {});

    const Scale Scale::PentatonicMajor =
        Scale("Pentatonic Major", {2, 2, 3, 2, 3}, {0, 2, 4, 7, 9, 12},
              "1 2 3 5 6 8", "",
              {
                  "Basic",
                  "Pentatonic",
              });

    const Scale Scale::WholeTone =
        Scale("Whole Tone", {2, 2, 2, 2, 2, 2}, {0, 2, 4, 6, 8, 10, 12}, "", "",
              {
                  "Symmetrical",
              });

    const Scale Scale::Messiaen6thMode =
        Scale("Messiaen 6th Mode", {2, 2, 1, 1, 2, 2, 1, 1},
              {0, 2, 4, 5, 6, 8, 10, 11, 12}, "", "",
              {
                  "Symmetrical",
              });

    const Scale Scale::Iwato =
        Scale("Iwato", {1, 4, 1, 4, 2}, {0, 1, 5, 6, 10, 12}, "1 b2 4 b5 b7 8",
              "", {});

    const Scale Scale::HungarianGypsy =
        Scale("Hungarian Gypsy", {2, 1, 3, 1, 1, 2, 2},
              {0, 2, 3, 6, 7, 8, 10, 12}, "1 2 b3 #4 5 b6 b7 8", "", {});

    const Scale Scale::Phrygian = Scale("Phrygian", {1, 2, 2, 2, 1, 2, 2},
                                        {0, 1, 3, 5, 7, 8, 10, 12}, "", "",
                                        {
                                            "Major/Minor",
                                            "Modal",
                                        });

    const Scale Scale::AlteredDominant =
        Scale("Altered Dominant", {1, 2, 1, 2, 2, 2, 2},
              {0, 1, 3, 4, 6, 8, 10, 12}, "", "",
              {
                  "Major/Minor",
                  "Modal",
              });

    const Scale Scale::Kumoi = Scale(
        "Kumoi", {1, 4, 2, 1, 4}, {0, 1, 5, 7, 8, 12}, "1 b2 4 5 b6 8", "", {});

    const Scale Scale::LydianDominant =
        Scale("Lydian Dominant", {2, 2, 2, 1, 2, 1, 2},
              {0, 2, 4, 6, 7, 9, 10, 12}, "", "",
              {
                  "Major/Minor",
                  "Modal",
              });

    const Scale Scale::InvertedAugmented =
        Scale("Inverted Augmented", {1, 3, 1, 3, 1, 3}, {0, 1, 4, 5, 8, 9, 12},
              "", "",
              {
                  "Symmetrical",
              });

    const Scale Scale::Octatonic =
        Scale("Octatonic", {2, 1, 2, 1, 2, 1, 2, 1},
              {0, 2, 3, 5, 6, 8, 9, 11, 12}, "1 2 b3 4 b5 b6 7 8", "",
              {
                  "Basic",
              });

    const Scale Scale::EightToneSpanish =
        Scale("Eight Tone Spanish", {1, 2, 1, 1, 1, 2, 2, 2},
              {0, 1, 3, 4, 5, 6, 8, 10, 12}, "1 b2 #2 3 4 b5 b6 b7 8", "", {});

    const Scale Scale::HungarianMajor =
        Scale("Hungarian Major", {3, 1, 2, 1, 2, 1, 2},
              {0, 3, 4, 6, 7, 9, 10, 12}, "1 #2 3 #4 5 6 b7 8", "", {});

    const Scale Scale::IonianAugmented =
        Scale("Ionian Augmented", {2, 2, 1, 3, 1, 2, 1},
              {0, 2, 4, 5, 8, 9, 11, 12}, "", "",
              {
                  "Major/Minor",
                  "Modal",
              });

    const Scale Scale::Mixolydian = Scale("Mixolydian", {2, 1, 2, 2, 2, 1, 2},
                                          {0, 2, 3, 5, 7, 9, 10, 12}, "", "",
                                          {
                                              "Major/Minor",
                                              "Modal",
                                          });

    const Scale Scale::Messiaen7thMode =
        Scale("Messiaen 7th Mode", {1, 1, 1, 2, 1, 1, 1, 1, 2, 1},
              {0, 1, 2, 3, 5, 6, 7, 8, 9, 11, 12}, "", "",
              {
                  "Symmetrical",
              });

    const Scale Scale::Locrian = Scale("Locrian", {1, 2, 2, 1, 2, 2, 2},
                                       {0, 1, 3, 5, 6, 8, 10, 12}, "", "",
                                       {
                                           "Major/Minor",
                                           "Modal",
                                       });

    const Scale Scale::Diminished =
        Scale("Diminished", {2, 1, 2, 1, 2, 1, 2, 1},
              {0, 2, 3, 5, 6, 8, 9, 11, 12}, "", "",
              {
                  "Symmetrical",
              });

    const Scale Scale::Messiaen5thModeInverse =
        Scale("Messiaen 5th Mode Inverse", {4, 1, 1, 4, 1, 1},
              {0, 4, 5, 6, 10, 11, 12}, "", "",
              {
                  "Symmetrical",
              });

    const Scale Scale::LydianAugmented =
        Scale("Lydian Augmented", {2, 2, 2, 2, 1, 2, 1},
              {0, 2, 4, 6, 8, 9, 11, 12}, "", "",
              {
                  "Major/Minor",
                  "Modal",
              });

    const Scale Scale::Messiaen6thModeInverse =
        Scale("Messiaen 6th Mode Inverse", {1, 1, 2, 2, 1, 1, 2, 2},
              {0, 1, 2, 4, 6, 7, 8, 10, 12}, "", "",
              {
                  "Symmetrical",
              });

    const Scale Scale::Javanese =
        Scale("Javanese", {1, 2, 2, 2, 2, 1, 2}, {0, 1, 3, 5, 7, 9, 10, 12},
              "1 b2 b3 4 5 6 b7 8", "", {});

    const Scale Scale::Major =
        Scale("Major", {2, 2, 1, 2, 2, 2, 1}, {0, 2, 4, 5, 7, 9, 11, 12},
              "1 2 3 4 5 6 7", "",
              {
                  "Basic",
              });

    const Scale Scale::SymmetricalDecatonic =
        Scale("Symmetrical Decatonic", {1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
              {0, 1, 2, 4, 5, 6, 7, 8, 10, 11, 12}, "", "",
              {
                  "Symmetrical",
                  "Decatonic",
              });

    const Scale Scale::Mongolian =
        Scale("Mongolian", {2, 2, 3, 2, 3}, {0, 2, 4, 7, 9, 12}, "1 2 3 5 6 8",
              "", {});

    const Scale Scale::Messiaen2ndModeTruncated =
        Scale("Messiaen 2nd Mode Truncated", {1, 2, 3, 1, 2, 3},
              {0, 1, 3, 6, 7, 9, 12}, "", "",
              {
                  "Symmetrical",
              });

    const Scale Scale::Bebopminor =
        Scale("Bebop minor", {2, 1, 1, 1, 2, 2, 1, 2},
              {0, 2, 3, 4, 5, 7, 9, 10, 12}, "1 2 b3 3 4 5 6 b7 8", "",
              {
                  "Jazz",
              });

    const Scale Scale::Spanish =
        Scale("Spanish", {1, 3, 1, 2, 1, 2, 2}, {0, 1, 4, 5, 7, 8, 10, 12},
              "1 b2 3 4 5 b6 b7 8", "", {});

    const Scale Scale::Slendro = Scale("Slendro", {2, 3, 2, 2, 3},
                                       {0, 2, 5, 7, 9, 12}, "1 2 4 5 6 8", "",
                                       {
                                           "World",
                                           "Gamelan",
                                           "Pentatonic",
                                       });

    const Scale Scale::RomanianMinor =
        Scale("Romanian Minor", {2, 1, 3, 1, 2, 1, 2},
              {0, 2, 3, 6, 7, 9, 10, 12}, "", "",
              {
                  "Major/Minor",
                  "Modal",
              });

    const Scale Scale::LydianRaised2 =
        Scale("Lydian Raised2", {3, 1, 2, 1, 2, 2, 1},
              {0, 3, 4, 6, 7, 9, 11, 12}, "", "",
              {
                  "Major/Minor",
                  "Modal",
              });

    const Scale Scale::Ethiopian =
        Scale("Ethiopian", {2, 1, 2, 2, 1, 2, 2}, {0, 2, 3, 5, 7, 8, 10, 12},
              "1 2 b3 4 5 b6 b7 8", "", {});

    const Scale Scale::Hirajoshi =
        Scale("Hirajoshi", {2, 1, 4, 1, 4}, {0, 2, 3, 7, 8, 12},
              "1 2 b3 5 b6 8", "", {});

    const Scale Scale::Messiaen5thMode =
        Scale("Messiaen 5th Mode", {1, 4, 1, 1, 4, 1}, {0, 1, 5, 6, 7, 11, 12},
              "", "",
              {
                  "Symmetrical",
              });

    const Scale Scale::GenusChromaticum =
        Scale("Genus Chromaticum", {1, 2, 1, 1, 2, 1, 1, 2, 1},
              {0, 1, 3, 4, 5, 7, 8, 9, 11, 12}, "", "",
              {
                  "Symmetrical",
                  "Decatonic",
              });

    const Scale Scale::Byzantine =
        Scale("Byzantine", {1, 3, 1, 2, 1, 3, 1}, {0, 1, 4, 5, 7, 8, 11, 12},
              "1 b2 3 4 5 b6 7 8", "", {});

    const Scale Scale::RagaNeelangi = Scale("Raga Neelangi", {2, 1, 3, 2, 1, 3},
                                            {0, 2, 3, 6, 8, 9, 12}, "", "",
                                            {
                                                "Symmetrical",
                                            });

    const Scale Scale::Messiaen3rdMode =
        Scale("Messiaen 3rd Mode", {2, 1, 1, 2, 1, 1, 2, 1, 1},
              {0, 2, 3, 4, 6, 7, 8, 10, 11, 12}, "", "",
              {
                  "Symmetrical",
              });

    const Scale Scale::LeadingWholeTone =
        Scale("Leading Whole Tone", {2, 2, 2, 2, 2, 1, 1},
              {0, 2, 4, 6, 8, 10, 11, 12}, "1 2 3 #4 #5 #6 7 8", "", {});

    const Scale Scale::Gypsy =
        Scale("Gypsy", {1, 3, 1, 2, 1, 3, 1}, {0, 1, 4, 5, 7, 8, 11, 12},
              "1 b2 3 4 5 b6 7 8", "", {});

    const Scale Scale::WholeToneFlat5 =
        Scale("Whole Tone Flat5", {2, 2, 2, 2, 2, 2}, {0, 2, 4, 6, 8, 10, 12},
              "1 2 3 b5 b6 b7 8", "", {});

    const Scale Scale::VanDerHost =
        Scale("Van Der Host", {1, 2, 2, 1, 1, 2, 2, 1},
              {0, 1, 3, 5, 6, 7, 9, 11, 12}, "", "",
              {
                  "Symmetrical",
              });

    const Scale Scale::PelogBem =
        Scale("Pelog Bem", {1, 5, 1, 1}, {0, 1, 6, 7, 8}, "1 b2 #4 5 b6 8", "",
              {
                  "World",
                  "Gamelan",
                  "Pentatonic",
              });

    const Scale Scale::Dorian = Scale("Dorian", {2, 1, 2, 2, 2, 1, 2},
                                      {0, 2, 3, 5, 7, 9, 10, 12}, "", "",
                                      {
                                          "Major/Minor",
                                          "Modal",
                                      });

    const Scale Scale::Ultralocrian =
        Scale("Ultralocrian", {1, 2, 1, 2, 2, 1, 3}, {0, 1, 3, 4, 6, 8, 9, 12},
              "", "",
              {
                  "Major/Minor",
                  "Modal",
              });

    const Scale Scale::Enigmatic =
        Scale("Enigmatic", {1, 3, 2, 2, 2, 1, 1}, {0, 1, 4, 6, 8, 10, 11, 12},
              "1 b2 3 #4 #5 #6 7 8", "", {});

    const Scale Scale::DiminishedMinor =
        Scale("Diminished Minor", {2, 1, 2, 1, 2, 1, 2, 1},
              {0, 2, 3, 5, 6, 8, 9, 11, 12}, "1 2 b3 4 b5 b6 bb7 b8 8", "", {});

    const Scale Scale::PhrygianDominant =
        Scale("Phrygian Dominant", {1, 3, 1, 2, 1, 2, 2},
              {0, 1, 4, 5, 7, 8, 10, 12}, "", "",
              {
                  "Major/Minor",
                  "Modal",
              });

    const Scale Scale::Messiaen7thModeInverse =
        Scale("Messiaen 7th Mode Inverse", {2, 1, 1, 1, 1, 2, 1, 1, 1, 1},
              {0, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12}, "", "",
              {
                  "Symmetrical",
              });

    const Scale Scale::Algerian =
        Scale("Algerian", {2, 1, 3, 1, 1, 3, 1}, {0, 2, 3, 6, 7, 8, 11, 12},
              "1 2 b3 #4 5 b6 7 8", "", {});

    const Scale Scale::Chinese =
        Scale("Chinese", {4, 2, 1, 4, 1}, {0, 4, 6, 7, 11, 12}, "1 3 #4 5 7 8",
              "", {});

    const Scale Scale::LocrianRaised6 =
        Scale("Locrian Raised6", {1, 2, 2, 1, 3, 1, 2},
              {0, 1, 3, 5, 6, 9, 10, 12}, "", "",
              {
                  "Major/Minor",
                  "Modal",
              });

    const Scale Scale::DorianFlat2 =
        Scale("Dorian Flat2", {1, 2, 2, 2, 2, 1, 2}, {0, 1, 3, 5, 7, 9, 10, 12},
              "", "",
              {
                  "Major/Minor",
                  "Modal",
              });

    const Scale Scale::BebopDominant =
        Scale("Bebop Dominant", {2, 2, 1, 2, 2, 1, 1, 1},
              {0, 2, 4, 5, 7, 9, 10, 11, 12}, "1 2 3 4 5 6 b7 7 8", "",
              {
                  "Jazz",
              });

    const Scale Scale::BebopHalfDiminished =
        Scale("Bebop Half Diminished", {1, 2, 2, 1, 1, 1, 2, 2},
              {0, 1, 3, 5, 6, 7, 8, 10, 12}, "1 b2 b3 4 b5 5 b6 b7 8", "", {});

    const Scale Scale::MajorPhrygian =
        Scale("Major Phrygian", {1, 3, 1, 2, 1, 2, 2},
              {0, 1, 4, 5, 7, 8, 10, 12}, "1 b2 3 4 5 b6 b7 8", "", {});

    const Scale Scale::DiminishedHalfTone =
        Scale("Diminished Half Tone", {1, 2, 1, 2, 1, 2, 1, 2},
              {0, 1, 3, 4, 6, 7, 9, 10, 12}, "", "",
              {
                  "Symmetrical",
              });

    const Scale Scale::Messiaen4thMode =
        Scale("Messiaen 4th Mode", {1, 1, 3, 1, 1, 1, 3, 1},
              {0, 1, 2, 5, 6, 7, 8, 11, 12}, "", "",
              {
                  "Symmetrical",
              });

    const std::map<std::string, const Scale> Scale::scaleMap = {
        std::pair<std::string, const Scale>("Lydian", Lydian),
        std::pair<std::string, const Scale>("Harmonic Minor", HarmonicMinor),
        std::pair<std::string, const Scale>("Aeolian", Aeolian),
        std::pair<std::string, const Scale>("Persian", Persian),
        std::pair<std::string, const Scale>("Double Harmonic", DoubleHarmonic),
        std::pair<std::string, const Scale>("Egyptian", Egyptian),
        std::pair<std::string, const Scale>("Mohammedan", Mohammedan),
        std::pair<std::string, const Scale>("Melodic Major", MelodicMajor),
        std::pair<std::string, const Scale>("Pelog2", Pelog2),
        std::pair<std::string, const Scale>("Two Semitone Tritone",
                                            TwoSemitoneTritone),
        std::pair<std::string, const Scale>("Japanese", Japanese),
        std::pair<std::string, const Scale>("Melodic Minor", MelodicMinor),
        std::pair<std::string, const Scale>("Diminished Dominant",
                                            DiminishedDominant),
        std::pair<std::string, const Scale>("Pelog", Pelog),
        std::pair<std::string, const Scale>("Hawaiian", Hawaiian),
        std::pair<std::string, const Scale>("Jewish", Jewish),
        std::pair<std::string, const Scale>("Augmented", Augmented),
        std::pair<std::string, const Scale>("Harmonic Major", HarmonicMajor),
        std::pair<std::string, const Scale>("Overtone", Overtone),
        std::pair<std::string, const Scale>("Half Diminished", HalfDiminished),
        std::pair<std::string, const Scale>("Pelog Barang", PelogBarang),
        std::pair<std::string, const Scale>("Tritone", Tritone),
        std::pair<std::string, const Scale>("Messiaen 4th Mode Inverse",
                                            Messiaen4thModeInverse),
        std::pair<std::string, const Scale>("Neapolitan Minor",
                                            NeapolitanMinor),
        std::pair<std::string, const Scale>("Lydian Minor", LydianMinor),
        std::pair<std::string, const Scale>("Octatonic Mode 2", OctatonicMode2),
        std::pair<std::string, const Scale>("Chromatic", Chromatic),
        std::pair<std::string, const Scale>("Major Locrian", MajorLocrian),
        std::pair<std::string, const Scale>("Balinese", Balinese),
        std::pair<std::string, const Scale>("Neapolitan Major",
                                            NeapolitanMajor),
        std::pair<std::string, const Scale>("Oriental", Oriental),
        std::pair<std::string, const Scale>("Arabian", Arabian),
        std::pair<std::string, const Scale>("Hindu", Hindu),
        std::pair<std::string, const Scale>("Pentatonic Minor",
                                            PentatonicMinor),
        std::pair<std::string, const Scale>("Hungarian Minor", HungarianMinor),
        std::pair<std::string, const Scale>("Pentatonic Major",
                                            PentatonicMajor),
        std::pair<std::string, const Scale>("Whole Tone", WholeTone),
        std::pair<std::string, const Scale>("Messiaen 6th Mode",
                                            Messiaen6thMode),
        std::pair<std::string, const Scale>("Iwato", Iwato),
        std::pair<std::string, const Scale>("Hungarian Gypsy", HungarianGypsy),
        std::pair<std::string, const Scale>("Phrygian", Phrygian),
        std::pair<std::string, const Scale>("Altered Dominant",
                                            AlteredDominant),
        std::pair<std::string, const Scale>("Kumoi", Kumoi),
        std::pair<std::string, const Scale>("Lydian Dominant", LydianDominant),
        std::pair<std::string, const Scale>("Inverted Augmented",
                                            InvertedAugmented),
        std::pair<std::string, const Scale>("Octatonic", Octatonic),
        std::pair<std::string, const Scale>("Eight Tone Spanish",
                                            EightToneSpanish),
        std::pair<std::string, const Scale>("Hungarian Major", HungarianMajor),
        std::pair<std::string, const Scale>("Ionian Augmented",
                                            IonianAugmented),
        std::pair<std::string, const Scale>("Mixolydian", Mixolydian),
        std::pair<std::string, const Scale>("Messiaen 7th Mode",
                                            Messiaen7thMode),
        std::pair<std::string, const Scale>("Locrian", Locrian),
        std::pair<std::string, const Scale>("Diminished", Diminished),
        std::pair<std::string, const Scale>("Messiaen 5th Mode Inverse",
                                            Messiaen5thModeInverse),
        std::pair<std::string, const Scale>("Lydian Augmented",
                                            LydianAugmented),
        std::pair<std::string, const Scale>("Messiaen 6th Mode Inverse",
                                            Messiaen6thModeInverse),
        std::pair<std::string, const Scale>("Javanese", Javanese),
        std::pair<std::string, const Scale>("Major", Major),
        std::pair<std::string, const Scale>("Symmetrical Decatonic",
                                            SymmetricalDecatonic),
        std::pair<std::string, const Scale>("Mongolian", Mongolian),
        std::pair<std::string, const Scale>("Messiaen 2nd Mode Truncated",
                                            Messiaen2ndModeTruncated),
        std::pair<std::string, const Scale>("Bebop minor", Bebopminor),
        std::pair<std::string, const Scale>("Spanish", Spanish),
        std::pair<std::string, const Scale>("Slendro", Slendro),
        std::pair<std::string, const Scale>("Romanian Minor", RomanianMinor),
        std::pair<std::string, const Scale>("Lydian Raised2", LydianRaised2),
        std::pair<std::string, const Scale>("Ethiopian", Ethiopian),
        std::pair<std::string, const Scale>("Hirajoshi", Hirajoshi),
        std::pair<std::string, const Scale>("Messiaen 5th Mode",
                                            Messiaen5thMode),
        std::pair<std::string, const Scale>("Genus Chromaticum",
                                            GenusChromaticum),
        std::pair<std::string, const Scale>("Byzantine", Byzantine),
        std::pair<std::string, const Scale>("Raga Neelangi", RagaNeelangi),
        std::pair<std::string, const Scale>("Messiaen 3rd Mode",
                                            Messiaen3rdMode),
        std::pair<std::string, const Scale>("Leading Whole Tone",
                                            LeadingWholeTone),
        std::pair<std::string, const Scale>("Gypsy", Gypsy),
        std::pair<std::string, const Scale>("Whole Tone Flat5", WholeToneFlat5),
        std::pair<std::string, const Scale>("Van Der Host", VanDerHost),
        std::pair<std::string, const Scale>("Pelog Bem", PelogBem),
        std::pair<std::string, const Scale>("Dorian", Dorian),
        std::pair<std::string, const Scale>("Ultralocrian", Ultralocrian),
        std::pair<std::string, const Scale>("Enigmatic", Enigmatic),
        std::pair<std::string, const Scale>("Diminished Minor",
                                            DiminishedMinor),
        std::pair<std::string, const Scale>("Phrygian Dominant",
                                            PhrygianDominant),
        std::pair<std::string, const Scale>("Messiaen 7th Mode Inverse",
                                            Messiaen7thModeInverse),
        std::pair<std::string, const Scale>("Algerian", Algerian),
        std::pair<std::string, const Scale>("Chinese", Chinese),
        std::pair<std::string, const Scale>("Locrian Raised6", LocrianRaised6),
        std::pair<std::string, const Scale>("Dorian Flat2", DorianFlat2),
        std::pair<std::string, const Scale>("Bebop Dominant", BebopDominant),
        std::pair<std::string, const Scale>("Bebop Half Diminished",
                                            BebopHalfDiminished),
        std::pair<std::string, const Scale>("Major Phrygian", MajorPhrygian),
        std::pair<std::string, const Scale>("Diminished Half Tone",
                                            DiminishedHalfTone),
        std::pair<std::string, const Scale>("Messiaen 4th Mode",
                                            Messiaen4thMode)};

} // namespace gdmusickit