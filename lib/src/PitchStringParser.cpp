
#include "gdmusickit/PitchStringParser.hpp"
#include "gdmusickit/Pitch.hpp"
#include "gdmusickit/PitchFactory.hpp"

#include <algorithm>
#include <charconv> // from_char, to_char
#include <exception>
#include <iostream>
#include <regex>
#include <string>

namespace gdmusickit {

    // class Except: virtual public std::runtime_error {

    //    struct ParsePitchInputException: public std::exception {
    struct ParsePitchInputException: public std::invalid_argument {
        const char* what() const throw() { return "Invalid input Exception"; }
    };

    class MyException: public std::exception {
        const char* file;
        int line;
        const char* func;
        const char* info;
        const char* msg;

      public:
        MyException(const char* msg, const char* file_, int line_,
                    const char* func_, const char* info_ = "")
            : msg(msg), file(file_), line(line_), func(func_), info(info_) {}

        const char* get_file() const { return file; }
        int get_line() const { return line; }
        const char* get_func() const { return func; }
        const char* get_info() const { return info; }
        const char* what() const throw() { return msg; }
    };

    /**
     * @brief
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
        std::cout << std::endl;

        std::cout << "input string: '" << pitchString << "'" << std::endl;
        std::transform(pitchString.begin(), pitchString.end(),
                       pitchString.begin(), ::toupper);
        std::cout << "input string uc: '" << pitchString << "'" << std::endl;

        // std::regex r("([a-gA-G]{1}[S|F|B|#]?)([0-9]*)");
        std::regex r(PitchStringParser::pitchPattern);
        std::smatch m;
        if (std::regex_search(pitchString, m, r)) {

            auto pitch = m.str(1);
            auto pitchClass = PitchFactory::pitchClassNames.at(pitch);
            std::cout << "pitch: " << pitch << std::endl;
            std::cout << "pitch class: " << pitchClass << std::endl;
            // auto pc = PitchFactory::pitchClassNames[pitch];

            auto octave = m.str(2);
            if (octave.empty()) {
                std::cout << "no octave" << std::endl;
            }

            // std::cout << "s1 " << m.str(1) << std::endl;
            // std::cout << "s2 " << m.str(2) << std::endl;
            // for (auto v : m) {
            //     std::cout << v << std::endl;
            // }

            int oct = 0;
            const auto res = std::from_chars(
                octave.data(), octave.data() + octave.size(), oct);

            if (pitch == "CB" || pitch == "CF") {
                oct -= 1;
            }
            int midiNumber = pitchClass + (oct * 12);
            std::cout << "midi number returned: " << midiNumber << std::endl;
            std::cout << std::endl;

            // @todo: return a tuple instead?
            // std::tuple<int, int, int> ret;
            // ret = std::make_tuple(midiNumber, pitchClass, oct);
            // int mn = std::get<0>(ret);

            return midiNumber;
        }

        throw std::invalid_argument("Invalid input.");
        // return 0;
    }

} // namespace gdmusickit