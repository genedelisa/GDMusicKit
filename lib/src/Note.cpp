
//#include "gdmusickit/gdmusickit.h"

#include "gdmusickit/Note.hpp"
#include "gdmusickit/Pitch.hpp"

namespace gdmusickit {

      Note::Note(Pitch pitch, double startTime, double duration) {
          this->pitch = pitch;
          this->startTime = startTime;
          this->duration = duration;
      }

    //Pitch::Pitch(int midiNumber) { this->midiNumber = midiNumber; }

}
