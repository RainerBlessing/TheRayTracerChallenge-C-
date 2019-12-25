ray-tracer-challenge
================

This repository contains a C++ implementation of code implemented for the book "The Ray Tracer Challenge"
from Pragmatic Programmers.

Status of implementation: Chapter 4.

The project structure is provided below:

```
.
├── bin/                                # Folder for built application binary
│   └── ray_tracer_challenge            # Built application executable (empty for now)
├── cmake/                              # CMake build folder
│   ├── shared/                         # CMake artifacts
│   └── test/                           # Compiled test folder
│       └── ray_tracer_challenge_unit_tests # Built unit tests executable
├── src/                                # Folder for all source files
│   ├── shared/                         # Shared classes
│   └── main.cpp                        # Main entry of the application
├── test/                               # Test folder for all unit tests
│   └── CMakeLists.txt                  # Compile script for unit tests
└── CMakeLists.txt                      # Main compile script
```

## Dependencies

This project was built and tested on the Linux platform with the
following dependencies:

* CMake >= 3.5
* Boost >= 1.61

## Instructions

Do as you would any CMake project to compile:

```
mkdir cmake
cd cmake
cmake ..
make
```

Run application:

```
cd bin
./ray_tracer_challenge
```

Run unit test suite:

```
cd cmake/test
ctest
```

## References

* [Pragmatic Programmers - The Ray Tracer Challenge](https://pragprog.com/book/jbtracer/the-ray-tracer-challenge)
* [CMake: An introduction](https://www.cs.swarthmore.edu/~adanner/tips/cmake.php)
* [CMake/Testing with CTest](https://cmake.org/Wiki/CMake/Testing_With_CTest)
* [Get to know the Boost unit test framework](http://www.ibm.com/developerworks/aix/library/au-ctools1_boost/index.html)
* [Project template](https://github.com/albertchan/cmake-boost-demo)
