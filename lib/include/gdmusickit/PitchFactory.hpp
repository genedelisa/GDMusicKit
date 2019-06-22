#pragma once

namespace gdmusickit {

    class PitchFactory {
      public:
        static PitchFactory& getSharedInstance() {
            static PitchFactory instance;
            return instance;
        }

        Pitch getPitch(int midiNumber);

      private:
        PitchFactory() = default;
        ~PitchFactory() = default;

      public:
        // Delete the copy and move constructors.
        // These should be public as it results in clearer error messages.
        PitchFactory(const PitchFactory&) = delete;
        PitchFactory& operator=(const PitchFactory&) = delete;
        PitchFactory(PitchFactory&&) = delete;
        PitchFactory& operator=(PitchFactory&&) = delete;
    };

} // namespace gdmusickit