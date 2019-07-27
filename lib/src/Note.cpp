/**π
 * @file Note.cpp
 * @author Gene De Lisa (gene@rockhoppertech.com)
 * @brief 
 * @version 0.1.0
 * @date 2019-07-18
 * 
 * @copyright Copyright (c) 2019 Rockhopper Technologies, Inc.
 * 
 * 2019-07-18 Gene De Lisa gene@rockhoppertech.com
 * empty
 * * ## Usage:
 * *
 * *  @code
 * *  @endcode
 */

//#include "gdmusickit/gdmusickit.h"

#include "gdmusickit/Note.hpp"
#include "gdmusickit/Pitch.hpp"
#include "gdmusickit/PitchFactory.hpp"
#include "gdmusickit/PitchStringFormat.hpp"
#include <iomanip>

namespace gdmusickit {
    // class NoteImpl {

    // };
    // Note::Note(): impl_(new NoteImpl) {}

    /**
     * @brief Destroy the Note:: Note object
     * 
     */
    Note::~Note() = default;

    Pitch& findPitch(const std::string& s) {
        return PitchFactory::getSharedInstance().getPitch(s);
    }

    /**
     * @brief Construct a new Note:: Note object
     * 
     * @param pitch 
     * @param startBeat 
     * @param duration 
     */
    Note::Note(Pitch& pitch, double startBeat, double duration)
        : pitch(pitch), startBeat(startBeat), duration(duration) {
        LOG_INFO << "calling note ctor with pitch '" << pitch << "'\n";

        // this->pitch = pitch;
        // this->startBeat = startBeat;
        // this->duration = duration;
    }

    
    Note::Note(std::string pitchString, double startBeat, double duration) 
    : pitch(findPitch(pitchString)), startBeat(startBeat), duration(duration){
        LOG_INFO << "calling note ctor with string '" << pitchString << "'\n";

        //this->pitch = *p;
        this->pitch = findPitch(pitchString);
        this->startBeat = startBeat;
        this->duration = duration;
    }

   
    /**
     * @brief nice printing format. Uses the Note's spelling.
     * 
     * @param os 
     * @param note 
     * @return std::ostream& 
     */
    std::ostream& operator<<(std::ostream& os, Note const& note) {

        std::string ps =
            PitchStringFormat::getSharedInstance().stringFromMIDINumber(
                note.pitch.midiPitchNumber(),
                // PitchStringFormat::Spelling::flat,
                note.spelling, PitchStringFormat::Justification::left, true);

        return os << "Pitch: " << std::setw(3) << note.pitch << " " << ps
                  << " Start " << std::fixed << std::setprecision(2)
                  << note.startBeat << " Duration " << note.duration;
    }
    // Pitch::Pitch(int midiNumber) { this->midiNumber = midiNumber; }

} // namespace gdmusickit
