#pragma once

namespace gdmusickit {

    class MusicFrequency {
      public:
        double midiEqualTemperamentFrequency(int midiNumber);

        static double semiTonesFromFq(double fq, double referenceFq);
        static double semiTonesFrom440(double fq);
        static double centsFromFq(double fq, double referenceFq);
        static double centsFrom440(double fq);
        static double octavesFrom440(double fq);
        static double octavesFromFq(double fq, double referenceFq);
        static double midiNumberFromFq(double fq);

      protected:
      private:
        int octaveForMiddleC{5};
    };

} // namespace gdmusickit