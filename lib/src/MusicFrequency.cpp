#include "gdmusickit/MusicFrequency.hpp"
#include "gdmusickit/Pitch.hpp"

//#include <iostream>
#include <cmath>

namespace gdmusickit {

    double MusicFrequency::midiEqualTemperamentFrequency(int midiNumber) {
        // 69 is midinumber for A5, 440 is that fq
        // do not use Pitch.A5.midiNumber since this is referenced from the ctor
        int a440{69};

        if (octaveForMiddleC != 5) {
            int offset = 5 - octaveForMiddleC;
            a440 = 69 - (offset * 12);
        }
        return 440.0 * std::pow(2.0, (double(midiNumber - a440) / 12));
    }

    // just
    //    tone    Ratio    Interval    Natural    Half Step
    //    0    1:1    unison    480    0
    //    1    16:15    minor semitone    512    16:15
    //    2    9:8    major second    540    135:128
    //    3    6:5    minor third    576    16:15
    //    4    5:4    major third    600    25:24
    //    5    4:3    perfect fourth    640    16:15
    //    6    45:32    diatonic tritone    675    135:128
    //    7    3:2    perfect fifth    720    16:15
    //    8    8:5    minor sixth    768    16:15
    //    9    5:3    major sixth    800    25:24
    //    10    9:5    minor seventh    864    27:25
    //    11    15:8    major seventh    900    25:24
    //    12    2:1    octave    960    16:15

    // var oct = (Math.log (freq) - Math.log (261.626)) / Math.log (2) + 4.0;
    double lognote(double freq) {
        return (std::log(freq) - std::log(261.626)) / std::log(2) + 4.0;
    }

    // Formulas:
    // f = 440 × 2(−58/12) × (2(1/12))n
    // f = 440 × 2((n−58)/12)
    //    class func f(n:Int) {
    //        let trt = Darwin.pow(2.0, 1.0/12.0)
    //        let f = 440.0 * Darwin.pow(2.0, -58 / 12) * Darwin.pow(trt,
    //        Double(n)) let c = 440.0 * Darwin.pow(2.0, Double(n-58 / 12))
    //        print("\(f) \(c)")
    //    }
    //    func freq_to_note(freq:Double) {
    //        var lnote = lognote(freq:freq)
    //        var oct = floor(lnote)
    //        var cents = 1200 * (lnote - oct)
    //        var note_table = "C C#D D#E F F#G G#A A#B"
    //        var offset = 50.0
    //        var x = 2
    //        var note = ""
    //        if cents < 50 {
    //            note = "C "
    //        } else if cents >= 1150{
    //            note = "C "
    //            cents -= 1200
    //            oct += 1
    //        } else {
    //            for j in 1 ..< 12 {
    //                if (cents >= offset && cents < (offset + 100)) {
    //                    note = "\(note_table[x])\(note_table[x + 1])"
    ////                    note = note_table.charAt(x) + note_table.charAt(x +
    /// 1)
    //                    cents -= (Double(j) * 100.0)
    //                    break
    //                }
    //                offset += 100
    //                x += 2
    //            }
    //        }
    //        var centResult = round(cents, 2)
    //        var noteResult = note + (oct + "")
    //    }

    /*
     */

    double MusicFrequency::semiTonesFromFq(double fq, double referenceFq) {
        return 12.0 * std::log2(fq / referenceFq);
    }

    double MusicFrequency::semiTonesFrom440(double fq) {
        return semiTonesFromFq(fq, 440.0);
    }

    double MusicFrequency::centsFromFq(double fq, double referenceFq) {
        return 1200.0 * octavesFromFq(fq, referenceFq);
    }

    double MusicFrequency::centsFrom440(double fq) {
        return 1200.0 * octavesFrom440(fq);
    }

    double MusicFrequency::octavesFrom440(double fq) {
        return octavesFromFq(fq, 440.0);
    }

    double MusicFrequency::octavesFromFq(double fq, double referenceFq) {
        return std::log2(fq / referenceFq);
    }

    double MusicFrequency::midiNumberFromFq(double fq) {
        return 12.0 * std::log2(fq / 440.0) +
                double(69);
               //double(Pitch::A5.midiPitchNumber());
    }

} // namespace gdmusickit