
//#include "gdmusickit/gdmusickit.h"

#include "gdmusickit/Note.hpp"
#include "gdmusickit/Pitch.hpp"
#include "gdmusickit/PitchFactory.hpp"

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
        return os << "Pitch: " << note.pitch << " Start " << note.startBeat
                  << " Duration " << note.duration;
    }
    // Pitch::Pitch(int midiNumber) { this->midiNumber = midiNumber; }

} // namespace gdmusickit
