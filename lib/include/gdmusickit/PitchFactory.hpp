#pragma once

#include <iostream>
using namespace std;

namespace gdmusickit {

    class PitchFactory {
      public:
        static PitchFactory& getInstance() {
            static PitchFactory instance;
            return instance;
        }

        void print() { cout << "test" << endl; }

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