
#include <iostream>

// gene's music kit
namespace gdmusickit {

    class Pitch {
      public:
        Pitch(int midiNumber);
        Pitch(std::wstring pitchString);        
        int midiPitchNumber();
        int pitchClass();
        int octave();
        
        static double midiEqualTemperamentFrequency(int midiNumber);
        inline static int octaveForMiddleC = 5;

        friend std::ostream& operator<<(std::ostream& out, const Pitch& pitch);

      protected:
      private:
        int midiNumber{0};
        double frequency{0};

        // pitchbend? cents? spelling?
    };

} // namespace gdmusickit
