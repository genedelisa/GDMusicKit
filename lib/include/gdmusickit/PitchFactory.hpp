#ifndef GDMUSICKIT_PITCHFACTORY_HPP
#define GDMUSICKIT_PITCHFACTORY_HPP

#pragma once

#include "Pitch.hpp"
// class Pitch;
#include "Logging.hpp"
#include <iostream>
#include <map>
#include <memory>

//#include <algorithm>

namespace gdmusickit {

    /**
     * @brief The GoF Flyweight pattern for Pitches

     * @details PitchFactory is a Singleton that
     * creates Pitches lazily and stores them in a std::map.
     * The getPitch functions returna pointer to the values in the map.
     *
     * @see gdmusickit::Pitch
     */

    /**
@startuml
participant Client
participant PitchFactory
participant Pitch

Client -> PitchFactory: getPitch
PitchFactory -> map: at
map -> Pitch: new
PitchFactory <-- map:  pitch
Client <-- PitchFactory:  pitch
@enduml
     */

    class PitchFactory final {
      public:
        static PitchFactory& getSharedInstance() {
            // Thread safety since C++11 - Magic Statics
            static PitchFactory instance;
            return instance;
        }
        // see below
        // PitchFactory(PitchFactory const&) = delete;
        // PitchFactory& operator=(PitchFactory const&) = delete;
        // PitchFactory(PitchFactory&&) = delete;
        // PitchFactory& operator=(PitchFactory&&) = delete;

        /**
         * @brief Get the Pitch object.
         *
         * @param midiNumber 0-127
         * @return Pitch* a pointer to the single cached Pitch instance
         */
        Pitch* getPitch(const int midiNumber);

        /**
         * @brief Get the Pitch object
         *
         * @details
         * The given string is parsed into a midiNumber, then the associated
         * Pitch is either created or returned from the cache.
         * 
         * @param pitchString a Pitch description. e.g. "Bb5"
         * @return Pitch* a pointer to the single cached Pitch instance
         */
        Pitch* getPitch(std::string pitchString);

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

        static inline void showPitchMap() {
            // structured binding and decomposition c++17
            for (const auto& [key, value] : pitchMap) {
                std::cout << key << " => " << value << '\n';
            }
            std::cout << std::endl;
        }

        using PitchMapT = std::map<const int, Pitch*>;
        // c++17 allows static member definition here with inline
        /**
         * @brief The reusable Pitch objects.
         *
         * @details This is lazily populated from getPitch.
         */
        inline static PitchMapT pitchMap;

      public:
        // Delete the copy and move constructors.
        // These should be public as it results in clearer error messages.
        PitchFactory(const PitchFactory&) = delete;
        PitchFactory& operator=(const PitchFactory&) = delete;
        PitchFactory(PitchFactory&&) = delete;
        PitchFactory& operator=(PitchFactory&&) = delete;
    };

} // namespace gdmusickit
#endif
