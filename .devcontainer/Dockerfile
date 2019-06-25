#-------------------------------------------------------------------------------------------------------------
# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License. See https://go.microsoft.com/fwlink/?linkid=2090316 for license information.
#-------------------------------------------------------------------------------------------------------------

FROM debian:9

# some packages require timezone, which will launch
# in interactive mode and freeze the build. This says
# "don't do that."
ARG DEBIAN_FRONTEND=noninteractive

# Install git, process tools
RUN apt-get update && apt-get -y install git procps

# Install C++ tools
RUN apt-get -y install build-essential cppcheck valgrind
# RUN apt-get install -y cmake_3.13.4-1_i386.deb

RUN cd /usr/local/src \
    && wget https://cmake.org/files/LatestRelease/cmake-3.14.5.tar.gz \
    && tar xvf cmake-3.14.5.tar.gz \
    && cd cmake-3.14.5 \
    && ./bootstrap \
    && make \
    && make install \
    && cd .. \
    && rm -rf cmake*

# Clean up
RUN apt-get autoremove -y \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*

# Set the default shell to bash instead of sh
ENV SHELL /bin/bash
