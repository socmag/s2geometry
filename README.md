# S2 Geometry Library

THIS IS A FORK WHOSE ONLY PURPOSE IS TO REMOVE THE DEPENDENCIES
UPON THE GOOGLE LOGGING (GLOG) AND GOOGLE FLAGS (GFLAGS) LIBRARIES

IT IS INTENDED FOR USE IN STATIC LINK USE CASES

## Overview

This is a package for manipulating geometric shapes. Unlike many geometry
libraries, S2 is primarily designed to work with _spherical geometry_, i.e.,
shapes drawn on a sphere rather than on a planar 2D map. This makes it
especially suitable for working with geographic data.

If you want to learn more about the library, start by reading the
[overview](http://s2geometry.io/about/overview) and [quick start
document](http://s2geometry.io/devguide/cpp/quickstart), then read the
introduction to the [basic types](http://s2geometry.io/devguide/basic_types).

S2 documentation can be found on [s2geometry.io](http://s2geometry.io).

## Requirements for End Users

* A POSIX system (for getrusage).
* [CMake](http://www.cmake.org/)
* A C++ compiler with C++11 support, such as [g++](https://gcc.gnu.org/)
  \>= 4.7.
* [gflags command line flags](https://github.com/gflags/gflags)
* [glog logging module](https://github.com/google/glog)
* [OpenSSL](https://github.com/openssl/openssl) (for its bignum library)
* [googletest testing framework](https://github.com/google/googletest)
  (to build tests and example programs, optional)

On Ubuntu, all of these can be installed via apt-get:

```
sudo apt-get install cmake libgflags-dev libgoogle-glog-dev libgtest-dev openssl
```

Otherwise, you may need to install some from source.

On macOS, use [MacPorts](http://www.macports.org/) or
[Homebrew](http://brew.sh/).  For MacPorts:

```
sudo port install cmake gflags google-glog openssl
```

Do not install `gtest` from MacPorts; instead download [release
1.8.0](https://github.com/google/googletest/releases/tag/release-1.8.0), unpack,
and substitute

```
cmake -DGTEST_ROOT=/...absolute path to.../googletest-release-1.8.0/googletest ..
```

in the build instructions below.

Thorough testing has only been done on Ubuntu 14.04.3 and macOS 10.12.

## Build and Install

You may either download the source as a ZIP archive, or [clone the git
repository](https://help.github.com/articles/cloning-a-repository/).

### Via ZIP archive

Download [ZIP file](https://github.com/google/s2geometry/archive/master.zip)

```
cd [parent of directory where you want to put S2]
unzip [path to ZIP file]/s2geometry-master.zip
cd s2geometry-master
```

### Via `git clone`

```
cd [parent of directory where you want to put S2]
git clone https://github.com/google/s2geometry.git
cd s2geometry
```

### Building

From the appropriate directory depending on how you got the source:

```
mkdir build
cd build
# You can omit -DGTEST_ROOT to skip tests; see above for macOS.
cmake -DGTEST_ROOT=/usr/src/gtest ..
make
make test  # If GTEST_ROOT specified above.
sudo make install
```

## Python

If you want the Python interface, you will also need:

* [SWIG](https://github.com/swig/swig) (for Python support, optional)

which can be installed via

```
sudo apt-get install swig
```

or on macOS:

```
sudo port install swig
```
Expect to see some warnings if you build with swig 2.0.

## Disclaimer

This is not an official Google product.
