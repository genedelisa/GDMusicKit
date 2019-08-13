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

    const Scale Scale::major = Scale("Major", {2, 2, 1, 2, 2, 2, 1});
    const Scale Scale::symmetricalDecatonic =
        Scale("Symmetrical Decatonic", {1, 1, 2, 1, 1, 1, 1, 2, 1, 1});

    const std::map<std::string, const Scale> Scale::scaleMap = {
        std::pair<std::string, const Scale>("Major", major),
        std::pair<std::string, const Scale>("Symmetrical Decatonic",
                                            symmetricalDecatonic)};

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

} // namespace gdmusickit