cmake_minimum_required(VERSION 3.31.6)
project(Sequence)

set(CMAKE_CXX_STANDARD 20)

# while implementing Sequence, use this executable to run your own tests
add_executable(SequenceDebug
        SequenceDebug.cpp
        Sequence.cpp
        Sequence.h
        img/SequenceNode.cpp
)

# once you have everything in Sequence implemented, you can run SequenceTestHarness
# do not run this executable until you have implemented all of Sequence
add_executable(SequenceTestHarness
        SequenceTestHarness.cpp
        Sequence.cpp
        Sequence.h
)

# Make SequenceDebug the default startup target
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT SequenceDebug)
