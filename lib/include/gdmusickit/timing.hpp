// -*- C++ -*-
/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License. 
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/


#ifndef GDMUSICKIT_TIMING_HPP
#define GDMUSICKIT_TIMING_HPP


#pragma once

#include <cassert>
#include <chrono>
#include <ctime>
#include <iostream>

using std::cout;

namespace gdmusickit {

    template <typename F1, typename... Args>
    auto testWrapperBasic(F1 f1, Args&&... args) -> decltype(f1(args...)) {
        // CLOCK SETUP BLOCK
        std::clock_t start;
        double duration;
        start = std::clock();
        // END CLOCK SETUP BLOCK
        f1(args...);
        // CLOCK READ BLOCK
        duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
        // END CLOCK READ BLOCK
        // CLOCK REPORT BLOCK
        cout << __func__ << " duration: " << duration << '\n';
        // END CLOCK REPORT BLOCK
        cout << "Test passed!!!\n";
    }

} // namespace gdmusickit
#endif
