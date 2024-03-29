// -*- C++ -*-
/*---------------------------------------------------------------------------------------------
 *  Copyright (c); Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License.
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/

#include <algorithm>
#include <exception>
#include <iostream>
#include <string>

//#include "gdmusickit/gdmusickit.h"
#include "gdmusickit/Interval.hpp"

namespace gdmusickit {

    std::ostream& operator<<(std::ostream& os, const Interval& interval) {

        return os << "Interval: " << interval.name << " semitones "
                  << interval.semitones;
    }

    const Interval Interval::P1 =
        Interval("Unison", Interval::Quality::perfect, 1, 0);

    const Interval Interval::P4 =
        Interval("Perfect Fourth", Interval::Quality::perfect, 4, 5);

    const Interval Interval::P5 =
        Interval("Perfect Fifth", Interval::Quality::perfect, 5, 7);

    const Interval Interval::P8 =
        Interval("Octave", Interval::Quality::perfect, 8, 12);

    const Interval Interval::P11 =
        Interval("perfect eleventh", Interval::Quality::perfect, 11, 17);

    const Interval Interval::P12 =
        Interval("Perfect twelfth", Interval::Quality::perfect, 12, 19);

    const Interval Interval::P15 =
        Interval("Two Octaves", Interval::Quality::perfect, 15, 24);

    const Interval Interval::m2 = Interval("Minor ", Interval::Quality::minor, 2, 1);

    const Interval Interval::m3 = Interval("Minor ", Interval::Quality::minor, 3, 3);

    const Interval Interval::m6 = Interval("Minor ", Interval::Quality::minor, 6, 8);

    const Interval Interval::m7 = Interval("Minor ", Interval::Quality::minor, 7, 10);

    const Interval Interval::m9 = Interval("Minor ", Interval::Quality::minor, 9, 13);

    const Interval Interval::m10 =
        Interval("Minor ", Interval::Quality::minor, 10, 15);

    const Interval Interval::m13 =
        Interval("Minor ", Interval::Quality::minor, 13, 20);

    const Interval Interval::m14 =
        Interval("Minor ", Interval::Quality::minor, 14, 22);

    const Interval Interval::M2 = Interval("Major ", Interval::Quality::major, 2, 2);

    const Interval Interval::M3 = Interval("Major ", Interval::Quality::major, 3, 4);

    const Interval Interval::M6 = Interval("Major ", Interval::Quality::major, 6, 9);

    const Interval Interval::M7 = Interval("Major ", Interval::Quality::major, 7, 11);

    const Interval Interval::M9 = Interval("Major ", Interval::Quality::major, 9, 14);

    const Interval Interval::M10 =
        Interval("Major ", Interval::Quality::major, 10, 16);

    const Interval Interval::M13 =
        Interval("Major ", Interval::Quality::major, 13, 21);

    const Interval Interval::M14 =
        Interval("Major ", Interval::Quality::major, 14, 23);

    const Interval Interval::d1 =
        Interval("Diminished ", Interval::Quality::diminished, 1, -1);

    const Interval Interval::d2 =
        Interval("Diminished ", Interval::Quality::diminished, 2, 0);

    const Interval Interval::d3 =
        Interval("Diminished ", Interval::Quality::diminished, 3, 2);

    const Interval Interval::d4 =
        Interval("Diminished ", Interval::Quality::diminished, 4, 4);

    const Interval Interval::d5 =
        Interval("Diminished ", Interval::Quality::diminished, 5, 6);

    const Interval Interval::d6 =
        Interval("Diminished ", Interval::Quality::diminished, 6, 7);

    const Interval Interval::d7 =
        Interval("Diminished ", Interval::Quality::diminished, 7, 9);

    const Interval Interval::d8 =
        Interval("Diminished ", Interval::Quality::diminished, 8, 11);

    const Interval Interval::d9 =
        Interval("Diminished ", Interval::Quality::diminished, 9, 12);

    const Interval Interval::d10 =
        Interval("Diminished ", Interval::Quality::diminished, 10, 14);

    const Interval Interval::d11 =
        Interval("Diminished ", Interval::Quality::diminished, 11, 16);

    const Interval Interval::d12 =
        Interval("Diminished ", Interval::Quality::diminished, 12, 18);

    const Interval Interval::d13 =
        Interval("Diminished ", Interval::Quality::diminished, 13, 19);

    const Interval Interval::d14 =
        Interval("Diminished ", Interval::Quality::diminished, 14, 21);

    const Interval Interval::d15 =
        Interval("Diminished ", Interval::Quality::diminished, 15, 23);

    const Interval Interval::A1 =
        Interval("Augmented ", Interval::Quality::augmented, 1, 1);

    const Interval Interval::A2 =
        Interval("Augmented ", Interval::Quality::augmented, 2, 3);

    const Interval Interval::A3 =
        Interval("Augmented ", Interval::Quality::augmented, 3, 5);

    const Interval Interval::A4 =
        Interval("Augmented ", Interval::Quality::augmented, 4, 6);

    const Interval Interval::A5 =
        Interval("Augmented ", Interval::Quality::augmented, 5, 8);

    const Interval Interval::A6 =
        Interval("Augmented ", Interval::Quality::augmented, 6, 10);

    const Interval Interval::A7 =
        Interval("Augmented ", Interval::Quality::augmented, 7, 12);

    const Interval Interval::A8 =
        Interval("Augmented ", Interval::Quality::augmented, 8, 13);

    const Interval Interval::A9 =
        Interval("Augmented ", Interval::Quality::augmented, 9, 15);

    const Interval Interval::A10 =
        Interval("Augmented ", Interval::Quality::augmented, 10, 17);

    const Interval Interval::A11 =
        Interval("Augmented ", Interval::Quality::augmented, 11, 18);

    const Interval Interval::A12 =
        Interval("Augmented twel", Interval::Quality::augmented, 12, 20);

    const Interval Interval::A13 =
        Interval("Augmented Thirteenth", Interval::Quality::augmented, 13, 22);

    const Interval Interval::A14 =
        Interval("Augmented Fourteenth", Interval::Quality::augmented, 14, 24);

    const Interval Interval::A15 =
        Interval("Augmented Fifteenth", Interval::Quality::augmented, 15, 25);

} // namespace gdmusickit