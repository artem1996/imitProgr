cmake_minimum_required(VERSION 3.6)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Advance.cpp Advance.h Randomizer.cpp Randomizer.h Generator.h Buffer.h Line.h ThresholdLine.h  ThresholdBuffer.h Generator.cpp Buffer.cpp Line.cpp ThresholdLine.cpp ThresholdBuffer.cpp)
add_executable(untitled ${SOURCE_FILES} Advance.cpp Advance.h Randomizer.cpp Randomizer.h Generator.h Buffer.h Line.h ThresholdLine.h  ThresholdBuffer.h Generator.cpp Buffer.cpp Line.cpp ThresholdLine.cpp ThresholdBuffer.cpp)