cmake_minimum_required(VERSION 3.6)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Generator.cpp Generator.h Buffer.cpp Buffer.h Transfer.cpp Transfer.h Line.cpp Line.h ThresholdLine.cpp ThresholdLine.h ThresholdBuffer.cpp ThresholdBuffer.h Randomizer.cpp Randomizer.h Report.cpp Report.h)
add_executable(untitled ${SOURCE_FILES} Generator.cpp Generator.h Buffer.cpp Buffer.h Transfer.cpp Transfer.h Line.cpp Line.h ThresholdLine.cpp ThresholdLine.h ThresholdBuffer.cpp ThresholdBuffer.h Randomizer.cpp Randomizer.h Report.cpp Report.h)