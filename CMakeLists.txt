cmake_minimum_required(VERSION 3.6)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Advance.cpp Advance.h Randomizer.cpp Randomizer.h Generator.h Queue.h Barber.h Generator.cpp Queue.cpp Barber.cpp Transfer.cpp Transfer.h)
add_executable(untitled ${SOURCE_FILES} Advance.cpp Advance.h Randomizer.cpp Randomizer.h Generator.h Queue.h Barber.h Generator.cpp Queue.cpp Barber.cpp Transfer.cpp Transfer.h)