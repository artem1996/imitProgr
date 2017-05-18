cmake_minimum_required(VERSION 3.6)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Generator.cpp Generator.h Queue.cpp Queue.h Advancer.cpp Advancer.h Randomizer.cpp Randomizer.h)
add_executable(untitled ${SOURCE_FILES} Generator.cpp Generator.h Queue.cpp Queue.h Advancer.cpp Advancer.h Randomizer.cpp Randomizer.h)