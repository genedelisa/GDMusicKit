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
RUN apt-get update && apt-get -y install --fix-missing \
	git \
	wget \
	procps \
	make \
	build-essential \
	cppcheck \
	valgrind \
	vim \
	curl

# Install C++ tools
# RUN apt-get -y install build-essential cppcheck valgrind
# this takes a loooong time
# RUN cd /usr/local/src \
#     && wget https://cmake.org/files/LatestRelease/cmake-3.14.5.tar.gz \
#     && tar xvf cmake-3.14.5.tar.gz \
#     && cd cmake-3.14.5 \
#     && ./bootstrap \
#     && make \
#     && make install \
#     && cd .. \
#     && rm -rf cmake*

# just get the binaries instead
RUN wget https://github.com/Kitware/CMake/releases/download/v3.14.5/cmake-3.14.5-Linux-x86_64.tar.gz \
	&& tar xfv cmake-3.14.5-Linux-x86_64.tar.gz \
	&& rm -f cmake-3.14.5-Linux-x86_64.tar.gz \
	&& cd cmake-3.14.5-Linux-x86_64 \
	&& mv bin/* /usr/local/bin \
	&& mv doc/* /usr/local/doc \
	&& mv man/* /usr/local/man \
	&& mv share/* /usr/local/share


RUN cd /usr/local/src \
	&& wget https://dl.bintray.com/boostorg/release/1.70.0/source/boost_1_70_0.tar.gz \
	&& tar xfz boost_1_70_0.tar.gz \
	&& rm boost_1_70_0.tar.gz \
	&& cd boost_1_70_0 \
	&& ./bootstrap.sh --prefix=/usr/local  --with-libraries=system\
#	&& ./bootstrap.sh --prefix=/usr/local --with-libraries=program_options \
	&& ./b2 install \
	&& cd /usr/local/src \
	&& rm -rf boost_1_70_0


# Clean up
RUN apt-get autoremove -y \
	&& apt-get clean -y \
	&& rm -rf /var/lib/apt/lists/*

# Set the default shell to bash instead of sh
ENV SHELL /bin/bash
