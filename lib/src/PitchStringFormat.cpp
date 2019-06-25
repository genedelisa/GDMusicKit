
#include "gdmusickit/PitchStringFormat.hpp"
#include "gdmusickit/Pitch.hpp"
#include "gdmusickit/PitchFactory.hpp"

#include <charconv> // from_char, to_char
#include <exception>
#include <iostream>
#include <sstream>
#include <string>

namespace gdmusickit {

    std::string PitchStringFormat::stringFromMIDINumber(
        int midiNumber, PitchStringFormat::Spelling spelling,
        PitchStringFormat::Justification justification,
        bool includeOctave) {

        int pc = midiNumber % 12;
        int offset = 5 - Pitch::octaveForMiddleC;
        int oct = (midiNumber / 12) - offset;

        std::ostringstream stringStream;
        switch (justification) {
        case Justification::left:
            break;
        case Justification::right:
            break;
        case Justification::center:
            break;
        };

        std::string ps;
        if (spelling == Spelling::flat) {
            ps = flatPitches.at(pc);
        } else {
            ps = sharpPitches.at(pc);
        }

        stringStream << ps;
        if (includeOctave) {
            stringStream << oct;
        }
        return stringStream.str();
    }

} // namespace gdmusickit

/*
    open func midiNumberToString(_ midiNumber: Int, includeOctave: Bool = true)
   -> String { if midiNumber == -1 { return "Non ET"
        }

        let pc = midiNumber % 12
        //let oct = midiNumber / 12
        //let oct = (midiNumber / 12) - middleC.rawValue

        let offset = 5 - Pitch.octaveForMiddleC
        let oct = (midiNumber / 12) - offset


        var dict: [Int: String]
        if self.pitchSpelling == .flat {
            dict = flatDict
        } else if self.pitchSpelling == .sharp {
            dict = sharpDict
        } else {
            dict = flatDict
        }

        let ps: String
        if includeOctave {
            ps = "\(dict[pc]!)\(oct)"
        } else {
            ps = "\(dict[pc]!)"
        }

        switch justification {
        case .left:
            return leftJustify(ps, width: width)
        case .right:
            return rightJustify(ps, width: width)
        case .center:
            return centerJustify(ps, width: width)
        }

    }

 */