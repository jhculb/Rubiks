# Rubiks Cube project
## Goals

This project aims to create website with a Rubiks cube application, with solvers
based on traditional methods and some AI solvers as well.  

### The Project Roadmap

1. Develop an API for the cube
2. Develop a website with python webapp
3. Develop Python code to interface between a user and the Cube, including graphical representations,
4. Develop Python/C++ based traditional solvers (i.e. algorithmic)
5. Develop AI solvers (Keras/Tensorflow)
6. Upload to Website (inc. autoupdate, etc.)

## Post break goals
1. update the readme with this section's Goals
2. focus on solvers
  1. develop one elementary solver
  2. focus on ML approaches
    1. Keras / Tensorflow probably
    2. possibly pytorch
3. If time, web frontend
5. Personal - Try VScode & explore Gitlab
6. Meanwile check out AWS hosting 

## Current Progress

1. Cube development [/Cube]:
  1. Representation established [constructor/destructor]
  2. Printing to terminal [DisplayInTerminal]
  3. Front rotation (CW) implemented [Front]
  4. Front/Back established [Front, Back]
  5. Top/Bottom established [Top, Bottom]
  6. Interface for development established [IOfunctions.cpp]
  7. Check if solved code [IsSolved]
  8. Left/Right established [Left, Right]
  1. Established Middle Vertical and Horizontal rotations
  1. Dockerised
    1. Alpine distro (builder) makes file
    2. Passes it to another distro (app) which runs a bash script, starting driver
2. Website development [/Website]
  1. Website docker initalised
  2. Basic webpage setup

## To-Do list:

1. Cube development [Cube.cpp]:
  1. (Low priority, implement check if broken in ExecuteCubeDefinitions)
  1. Develop API
  3. Visualisation code for the cube - python?
2. Website development
  2. Docker environment
  2. Website development

## Inefficiency list
1. Rotate only acts on mFace, could change it to work on any face like Spiral,
so that it can act on mMiddleFace in MiddleVertical & MiddleHorizontal
2. Possible: Instead of iterating through a face, could load values into row
vector and iterate through these (i.e. in the MiddleVertical replacement steps)?
3. Spiral &c, may have isNotInmTempFace removed?
4. RowCalcFormatting do you need break after return?
5. MiddleVertical & MiddleHorizontal swap mMiddleFace & mFace roles in early
lines to remove need to switch?
6. MiddleVertical & MiddleHorizontal replacement replace only row not face?
7. Possible (with major efficiency gains & major recoding): Store mCube,
prespiraled. I.e. in constructor spiral it.
8. Rotating Horizontal only needs to initialise centre negative values once?
0. Do I need mMiddleFace?
0. Terminal Display store each line in string and print?

## Possible bug list
1. MiddleVertical & MiddleHorizontal use integers above mCube max size, possible
 integer overflow - soln negative mcube face instead?


## Known bug list
1. entering 2 into dimension input {IOfunctions} loops infinitely
2. Sim above: Input handling is off. dim=mh3 gives infinite loop
2. 1x1 cubes render incorrectly & probably need an edge case for this
