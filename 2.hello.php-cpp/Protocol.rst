2016 05 01

The Makefile
============

The Makefile part was difficult. I got a linker error I didn't understand
and it is difficult to find that unspecific stuff with search engines.

The extension did bild with g++ (OS X), c++ (OS X) but not g++-5 (Homebrew).
The solution was a flag **-undefined dynamic_lookup** for the linker.


OS X, Apple LLVM::

    * clang
    * cc
    * cpp
    * clang++
    * c++
    * g++
    * gcc

gcc, g++ configured with::

      --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/usr/include/c++/4.2.1

Homebrew/Cellar/gcc/5.3.x/bin/::

    * c++-5
    * cpp-5
    * g++-5
    * gcc-5
    * more ...


