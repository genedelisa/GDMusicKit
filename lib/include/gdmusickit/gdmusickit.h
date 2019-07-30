#ifndef GDMUSICKIT_GDMUSICKIT_H
#define GDMUSICKIT_GDMUSICKIT_H

#pragma once

#include <string>

#include "MIDISequence.hpp"
#include "MIDITrack.hpp"
#include "MusicFrequency.hpp"
#include "Note.hpp"
#include "NoteSequence.hpp"
#include "Pitch.hpp"
#include "PitchFactory.hpp"
#include "PitchStringFormat.hpp"
#include "PitchStringParser.hpp"
#include "TimedMetaMessage.hpp"

// private
//#include "Logging.hpp"
//#include "MacMIDI.hpp"


/**
 * @brief A namespace containing Gene's frobs.
 *
 * Right now it contains just the **Pitch** class.
 *
 * @author Gene De Lisa <gene@rockhoppertech.com>
 */



/**
    @mainpage GDMusicKit - A library for music frobs.
    @anchor mainpage
    @brief __GDMusicKit__ is a cross-platform C++ library for music.

    The following frobs are currently implemented:
    - Pitch
    - Note
    
    @par Contact
    Gene De Lisa: <gene@rockhoppertech.com>
    
    @author
    This code has been authored by <a href="http://rockhoppertech.com">Gene De Lisa</a>

    @copyright
    Copyright (C) 2019 Rockhopper Technologies, Inc.
    
    @par Licence
    This project is released under the <a href="http://www.gnu.org/licenses/gpl-3.0.en.html">GPLv3</a> license.
    @n@n
    This project is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version. @n@n
    this project is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details. @n@n
    You should have received a copy of the GNU General Public License
    along with this project.  If not, see <http://www.gnu.org/licenses/>.
    
    @par Dependencies & Compatibiliy
    The library uses c++17.
    It depends on 
    <a href="http://www.boost.org/">Boost</a> mostly for logging, and
    <a href="">Google Test</a> for unit-testing.
    
    @section download Download
    
    The source code is available on __Github__: https://github.com/genedelisa/GDMusicKit
 
    @section toc Table of Contents
 
    1. @subpage Compilation @n
    3. @subpage Examples @n
 
    @page Compilation
    @section compile-lib Compiling the library
    @tableofcontents

    @subsection dependencies Dependencies

    To compile the library, you should install the following dependencies:
    - Boost: <a href="http://www.boost.org/">http://www.boost.org/</a>

    Google Test is downloaded via CMake. Boost is far too large to do this.

    @subsection compiling Compiling as a static/dynamic library
    @par XCode

    See the xcode project in "ide/xcode/"

    @par CMake

    The library can be built using <a href="http://www.cmake.org/">CMake</a>.
    In the root directory, type the following command to generate the Makefiles:
    ```
    cmake . -G"Unix Makefiles"
    ```
    The following commands can be used to build the static library and run the unit tests, and generate the documentation:
    ```
    make
    make tests
    ```

    The following commands can be used to generate the developer documentation and the api documentation:
    ```
    make doc
    ```
    @par Usage

    The header file "gdmusickit.h" includes the public headers of the library.


 
    <center>Prev: \ref mainpage "Home" | Next: \ref Examples.</center>
 
    @page Examples

    @section cppex C++ Example

    @code{.cpp}
    #include <gdmusickit/gdmusickit.h>

    int main() {

        return EXIT_SUCCESS;

    }
    @endcode

    
    <center>Prev: \ref Compilation | Up: \ref mainpage "Home".</center>
 */
#endif
