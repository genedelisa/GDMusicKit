# Gene's C++ Music Frobs

[![GitHub last commit](https://img.shields.io/github/last-commit/genedelisa/GDMusicKit.svg)](https://github.com/genedelisa/GDMusicKit/commits/master)

[![GitHub release](https://img.shields.io/github/release/genedelisa/GDMusicKit.svg)](https://github.com/genedelisa/GDMusicKit/releases/)
[![GitHub release date](https://img.shields.io/github/release-date/genedelisa/GDMusicKit.svg)](https://github.com/genedelisa/GDMusicKit/releases)

[![C++17](https://img.shields.io/badge/c++17-compatible-4BC51D.svg?style=flat")](https://www.iso.org/standard/68564.html)
[![Platforms macOS](https://img.shields.io/badge/Platforms-OS%20X-lightgray.svg?style=flat)](https://swift.org/)
[![license](https://img.shields.io/github/license/mashape/apistatus.svg)](https://en.wikipedia.org/wiki/MIT_License)

[![Sponsors](https://img.shields.io/badge/Sponsors-Rockhopper%20Technologies-orange.svg?style=flat)](http://www.rockhoppertech.com/)
[![Twitter @GeneDeLisaDev](https://img.shields.io/twitter/follow/GeneDeLisaDev.svg?style=social)](https://twitter.com/GeneDeLisaDev)
![GitHub followers](https://img.shields.io/github/followers/genedelisa.svg?label=Follow&style=social)

## What's this?

Gene's music frobs. Things like Pitch and Note etc.


This is a [CMake 3](https://cmake.org) configured C++ project.

A typical cmake tapdance is like this:

```shell
mkdir build
cd build
cmake ..
make
```

[Doxygen](http://www.doxygen.nl) is run to generate documentation if an option is set. You need to download and install it first. I suggest you run the app to reconfigure doc/Doxyfile.in

There are Visual Studio Code tasks defined.

There is a script to generate an Xcode project.

## Building

You run cmake from the build directory.

You might want to clean the build directory first.

```shell
rm -rf build/*
```

The normal build incantation is this:

``` shell
cd build && cmake -D USE_UNIT_TESTING=ON -D GENERATE_DOC=ON .. && make all
```

## Visual Studio Tasks defined

### make all

Runs make all in the build directory

### make doc

Runs make doc in the build directory

```shell
cd build && make doc
```

### cmake

You probably want to run cmake once. Then when your code is updated, run make.

This task cleans the build directory, goes into it, runs cmake, then runs make all.

```shell
rm -rf build/* && cd build && cmake -D USE_UNIT_TESTING=ON -D GENERATE_DOC=ON .. && make all
```

### clean build

Removes everything from the build directory.

```shell
rm -rf build/*
```

### cmake just docs

Skips downloading Google Test and building the C++ code. Instead it does just the Doxygen guff.

```shell
rm -rf build/* && cd build && cmake -D USE_UNIT_TESTING=OFF -D GENERATE_DOC=ON .. && make doc
```

## Blog post for this example

[Blog post coming coon](http://www.rockhoppertech.com/blog/)

### Buy my kitty Giacomo some cat food

If you find this useful, my kitty likes snacks.

[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donate_SM.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=F5KE9Z29MH8YQ&bnP-DonationsBF:btn_donate_SM.gif:NonHosted)

<img src="http://www.rockhoppertech.com/blog/wp-content/uploads/2016/07/momocoding-1024.png" alt="Giacomo Kitty" width="400" height="300">

## Licensing

[MIT](https://en.wikipedia.org/wiki/MIT_License)

Please read the [LICENSE](LICENSE) for details.

## Credits

* [Gene De Lisa's development blog](http://rockhoppertech.com/blog/)
* [Gene De Lisa's music blog](http://genedelisa.com/)
* Twitter: [@GeneDeLisaDev](http://twitter.com/genedelisadev)
