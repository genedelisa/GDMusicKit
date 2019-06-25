
//#include "gdmusickit/gdmusickit.h"

#include "gdmusickit/Note.hpp"
#include "gdmusickit/Pitch.hpp"
#include "gdmusickit/PitchFactory.hpp"
#include "gdmusickit/PitchStringFormat.hpp"

namespace gdmusickit {

    Pitch findPitch(std::string s) {
        return PitchFactory::getSharedInstance().getPitch(s);
    }

    Note::Note(Pitch pitch, double startBeat, double duration) {
        this->pitch = pitch;
        this->startBeat = startBeat;
        this->duration = duration;
    }
    Note::Note(std::string pitchString, double startBeat, double duration) {
        this->pitch = findPitch(pitchString);
        this->startBeat = startBeat;
        this->duration = duration;
    }
    std::ostream& operator<<(std::ostream& os, Note const& note) {

        std::string ps =
            PitchStringFormat::getSharedInstance().stringFromMIDINumber(
                note.pitch.midiPitchNumber(), PitchStringFormat::Spelling::flat,
                PitchStringFormat::Justification::left, true);

        return os << "Pitch: " << note.pitch << " " << ps << " Start "
                  << note.startBeat << " Duration " << note.duration;
    }
    // Pitch::Pitch(int midiNumber) { this->midiNumber = midiNumber; }

} // namespace gdmusickit
