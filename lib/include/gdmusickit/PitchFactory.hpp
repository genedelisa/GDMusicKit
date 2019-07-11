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

        Pitch getPitch(std::string pitchString);

        

        // the input is uppercased when this is accessed
        static inline const std::map<std::string, int> pitchClassNames = {
            std::pair<std::string, int>("C", 0),
            std::pair<std::string, int>("CF", 11),
            std::pair<std::string, int>("C-", 11),
            std::pair<std::string, int>("CB", 11),
            std::pair<std::string, int>("CS", 1),
            std::pair<std::string, int>("C#", 1),

            std::pair<std::string, int>("D", 2),
            std::pair<std::string, int>("DF", 1),
            std::pair<std::string, int>("D-", 1),
            std::pair<std::string, int>("DB", 1),
            std::pair<std::string, int>("DS", 3),
            std::pair<std::string, int>("D#", 3),

            std::pair<std::string, int>("E", 4),
            std::pair<std::string, int>("EF", 3),
            std::pair<std::string, int>("E-", 3),
            std::pair<std::string, int>("EB", 3),
            std::pair<std::string, int>("ES", 5),
            std::pair<std::string, int>("E#", 5),

            std::pair<std::string, int>("F", 5),
            std::pair<std::string, int>("FF", 4),
            std::pair<std::string, int>("F-", 4),
            std::pair<std::string, int>("FB", 4),
            std::pair<std::string, int>("FS", 6),
            std::pair<std::string, int>("F#", 6),

            std::pair<std::string, int>("G", 7),
            std::pair<std::string, int>("GF", 6),
            std::pair<std::string, int>("G-", 6),
            std::pair<std::string, int>("GB", 6),
            std::pair<std::string, int>("GS", 8),
            std::pair<std::string, int>("G#", 8),

            std::pair<std::string, int>("A", 9),
            std::pair<std::string, int>("AF", 8),
            std::pair<std::string, int>("A-", 8),
            std::pair<std::string, int>("AB", 8),
            std::pair<std::string, int>("AS", 10),
            std::pair<std::string, int>("A#", 10),

            std::pair<std::string, int>("B", 11),
            std::pair<std::string, int>("BF", 10),
            std::pair<std::string, int>("B-", 10),
            std::pair<std::string, int>("BB", 10),
            std::pair<std::string, int>("BS", 0),
            std::pair<std::string, int>("B#", 0)};

      private:
        PitchFactory() = default;
        ~PitchFactory() = default;

        static inline std::unique_ptr<std::map<int, Pitch>> initMap() {
            //LOG_INFO << "init map" << std::endl;
            //          pitchMap[0] = Pitch(0);

            typedef std::map<int, Pitch> MyMap;
            auto m = std::unique_ptr<MyMap>(new MyMap());

            // why I make the typedef
            // auto m2 = std::unique_ptr<std::map<int, Pitch>>(
            // new std::map<int, Pitch>());

            for (auto i{0}; i <= 127; ++i) {
                m->emplace(std::pair<int, Pitch>(i, Pitch(i)));
                // m->insert(std::pair<int, Pitch>(i, Pitch(i)));
            }

            // or
            // for (const auto& entry : *m) {
            //     std::cout << entry.first << " => " << entry.second << '\n';
            // }

            // or structured binding and decomposition c++17
            // for (const auto& [key, value] : *m) {
            //     std::cout << key << " => " << value << '\n';
            // }

            // for (auto it = m->begin(); it != m->end(); ++it) {
            //     std::cout << it->first << " => " << it->second << '\n';
            // }
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