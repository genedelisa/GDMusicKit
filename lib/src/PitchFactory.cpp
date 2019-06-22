#include "gdmusickit/Pitch.hpp"
#include "gdmusickit/PitchFactory.hpp"

#include <cmath>
#include <iostream>

// gene's music kit
namespace gdmusickit {

    Pitch PitchFactory::getPitch(int midiNumber) {
        return Pitch(midiNumber);
    }


} // namespace gdmusickit
