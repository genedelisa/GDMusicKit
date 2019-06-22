#pragma once

#include "Pitch.hpp"

#include <iostream>
#include <map>

//#include <algorithm>

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

        static inline std::unique_ptr<std::map<int, Pitch>> initMap() {
            std::cout << "init map" << std::endl;
            //          pitchMap[0] = Pitch(0);

            typedef std::map<int, Pitch> MyMap;
            auto m = std::unique_ptr<MyMap>(new MyMap());

            std::cout << "inserting" << std::endl;
            for (auto i{0}; i <= 127; ++i) {
                m->insert(std::pair<int, Pitch>(i, Pitch(i)));
            }

            // for (std::map<int, Pitch>::iterator it = m->begin();
            for (auto it = m->begin(); it != m->end(); ++it) {
                std::cout << it->first << " => " << it->second << '\n';
            }
            return m;
        }
        static inline std::unique_ptr<std::map<int, Pitch>> pitchMap =
            initMap();
        // static inline std::map<int, Pitch> pitchMap = initMap();

        //         //auto mapret = mymap.insert(std::pair('a', 100));
        // auto [itelem, success] = mymap.insert(std::pair(’a’, 100));
        // If (!success) {
        //     // Insert failure
        // }
      public:
        // Delete the copy and move constructors.
        // These should be public as it results in clearer error messages.
        PitchFactory(const PitchFactory&) = delete;
        PitchFactory& operator=(const PitchFactory&) = delete;
        PitchFactory(PitchFactory&&) = delete;
        PitchFactory& operator=(PitchFactory&&) = delete;
    };

} // namespace gdmusickit