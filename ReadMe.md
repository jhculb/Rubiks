# Rubiks Cube project
## Goals

This project aims to create website with a Rubiks cube application, with solvers
based on traditional methods and some AI solvers as well.  

### The Project Roadmap

1. Develop a C++ Rubiks cube, of NxN 'dimension', which has all of the required
manipulations, has an API, etc.
2. Create Docker website
3. Develop Python code to interface between a user and the Cube, including
graphical representations.
4. Develop Python/C++ based traditional solvers (i.e. algorithmic)
5. Develop AI solvers (Keras/Tensorflow)

## Current Progress

1. Cube development [Cube.cpp]:
  1. Representation established [constructor/destructor]
  2. Printing to terminal [DisplayInTerminal]
  3. Front rotation (CW) implemented [Front]
  4. Front/Back established [Front, Back]
  5. Top/Bottom established [Top, Bottom]
  6. Interface for development established [IOfunctions.cpp]
  7. Check if solved code [IsSolved]
  8. Left/Right established [Left, Right]

## Current To-Do list:

1. Cube development [Cube.cpp]:
  1. Establish Middle Vertical and Horizontal rotations
    1. Identify slice {Done}
    2. Rotate slice {Done MV not MH}
    3. Replace slice in cube
  2. Develop API
