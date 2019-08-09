// -*- C++ -*-
/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License. 
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/



#include <algorithm>
#include <charconv> // from_char, to_char
#include <exception>
#include <iostream>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>

#include "Logging.hpp"
#include "gdmusickit/Pitch.hpp"
#include "gdmusickit/PitchFactory.hpp"
#include "gdmusickit/PitchStringParser.hpp"


namespace gdmusickit {

class Pitch;
    // class Except: virtual public std::runtime_error {

    //    struct ParsePitchInputException: public std::exception {
    struct ParsePitchInputException: public std::invalid_argument {
        [[nodiscard]] const char* what() const noexcept override { return "Invalid input Exception"; }
    };

    class MyException: public std::exception {
        const char* file;
        int line;
        const char* func;
        const char* info;
        const char* msg;

      public:
        MyException(const char* msg, const char* file, int line,
                    const char* func, const char* info = "")
            :  file(file), line(line), func(func), info(info), msg(msg) {}

        [[nodiscard]] const char* getFile() const { return file; }
        [[nodiscard]] int getLine() const { return line; }
        [[nodiscard]] const char* getFunc() const { return func; }
        [[nodiscard]] const char* getInfo() const { return info; }
        [[nodiscard]] const char* what() const noexcept override { return msg; }
    };

    /**
     * @brief Parse a pitch string into a MIDI number.
     *
     * Not all bad input strings fail.
     * "badinput" would succeed! B is a pitch class.
     * "junk" will fail
     *
     * @code
     int midiNumber{0};
     try {
         midiNumber = PitchStringParser::stringToMidiNumber("C5");
     } catch (std::invalid_argument& e) {
         std::cerr << e.what() << std::endl;
         return -1;
     }
     * @endcode
     * @param pitchString A string specifying a Pitch.
     * @return int The MIDI number for the Pitch.
     */
    int PitchStringParser::stringToMidiNumber(std::string pitchString) {
        //std::cout << std::endl;

        // std::cout << "input string: '" << pitchString << "'" << std::endl;
        std::transform(pitchString.begin(), pitchString.end(),
                       pitchString.begin(), ::toupper);
        // std::cout << "input string uc: '" << pitchString << "'" << std::endl;

        if (!PitchStringParser::isValid(pitchString)) {
            std::ostringstream stringStream;
            stringStream << "Invalid input pitch string. ";
            stringStream << pitchString;

            throw std::invalid_argument(stringStream.str());
        }

        // std::regex r("([a-gA-G]{1}[S|F|B|#]?)([0-9]*)");
        std::regex r(PitchStringParser::pitchPattern);
        std::smatch m;
        if (std::regex_search(pitchString, m, r)) {
            // std::cout << "matches: " << m.size() << std::endl;

            auto pitch = m.str(1);
            auto pitchClass = PitchFactory::pitchClassNames.at(pitch);
            // std::cout << "pitch: " << pitch << std::endl;
            // std::cout << "pitch class: " << pitchClass << std::endl;

            // auto pc = PitchFactory::pitchClassNames[pitch];

            // std::cout << "s1 " << m.str(1) << std::endl;
            // std::cout << "s2 " << m.str(2) << std::endl;
            // for (auto v : m) {
            //     std::cout << v << std::endl;
            // }

            auto octave = m.str(2);
            int oct{0};
            if (octave.empty()) {
                LOG_INFO << "no octave" << std::endl;
            } else {
                // parse the octave string into an int. This is the most
                // efficient way.
                const auto [ptr, ec] = std::from_chars(
                    octave.data(), octave.data() + octave.size(), oct);

                // posix error codes
                if (ec == std::errc()) {
                    LOG_INFO << "octave value: " << oct
                              << ", distance: " << ptr - octave.data() << '\n';

                } else if (ec == std::errc::invalid_argument) {
                    LOG_ERROR << "invalid argument!\n";
                    throw std::invalid_argument("Invalid input octave.");
                }
            }

            if (pitch == "CB" || pitch == "CF") {
                oct -= 1;
            }
            int midiNumber = pitchClass + (oct * 12);
            // std::cout << "midi number returned: " << midiNumber << std::endl;
            // std::cout << std::endl;

            // @todo: return a tuple instead?
            // std::tuple<int, int, int> ret;
            // ret = std::make_tuple(midiNumber, pitchClass, oct);
            // int mn = std::get<0>(ret);

            return midiNumber;
        }

        throw std::invalid_argument("Invalid input.");
        // return 0;
    }

    bool PitchStringParser::hasOctave(std::string pitchString) {

        std::transform(pitchString.begin(), pitchString.end(),
                       pitchString.begin(), ::toupper);

        //"([a-gA-G]{1}[S|F|B|#]?)([0-9]*)"

        std::string octaveRegex = "[A-Ga-g]{1}[-bf#sx]{0,1}[0-9]{1,2}$";
        std::regex regexp(octaveRegex);

        std::smatch matches;
        if (std::regex_search(pitchString, matches, regexp)) {
            if (matches.empty()) {
                return false;
            } else {
                return true;
            }
        }

        return false;
    }

    bool PitchStringParser::isValid(std::string pitchString) {

        std::transform(pitchString.begin(), pitchString.end(),
                       pitchString.begin(), ::toupper);
        //"([a-gA-G]{1}[S|F|B|#]?)([0-9]*)"

        // std::string octaveRegex = "[A-Ga-g]{1}[-bf#sx]{0,1}[0-9]{1,2}$";

        std::string isValidRegex = "[A-Ga-g]{1}[-bf#sxSF]{0,1}([0-9]{0,2}$)";
        std::regex regexp(isValidRegex);
        std::smatch matches;
        if (std::regex_search(pitchString, matches, regexp)) {
            LOG_INFO << "n matches " << matches.size() << std::endl;
            auto octave = matches.str(1);
            if (octave.empty()) {
                LOG_INFO << "no octave" << std::endl;
            } else {
                int oct = stringToInt(octave);
                LOG_INFO << "octave " << octave << std::endl;
                if (oct < 0 || oct > 11) {
                    return false;
                }
            }

            return true;
        }

        return false;
    }

    int PitchStringParser::stringToInt(std::string input) {
        // parse the octave string into an int. This is the most
        // efficient way.
        int result{0};

        const auto [ptr, ec] =
            std::from_chars(input.data(), input.data() + input.size(), result);

        // posix error codes
        if (ec == std::errc()) {
            LOG_ERROR << "int value: " << result
                      << ", distance: " << ptr - input.data() << '\n';

        } else if (ec == std::errc::invalid_argument) {
            LOG_ERROR << "invalid argument!"
                      << "'" << input << "'\n";
            throw std::invalid_argument("Invalid int input.");
        }
        return result;
    }

} // namespace gdmusickit