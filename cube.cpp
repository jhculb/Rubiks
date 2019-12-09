#include "cube.hpp"
#include <cassert>
#include <iostream>
#include <cmath>
#include <array>
#include <string>

Cube::Cube(int dimension){
  //must be int, greater than 0
  //assert()
  mDimension = dimension; // set private mDimension
  int mCubeArraySize=pow(mDimension, 3)-pow(mDimension-2, 3);
  mCube = new int[mCubeArraySize];

  for(int i=0; i< mCubeArraySize; i++){
    mCube[i]= i+1; // could change this, such a minor efficiency though?
  }
}

void Cube::DisplayInTerminal(){
  // if odd
  // Calculation ==================
  int front[mDimension][mDimension];
  int col =0, row =0, colinc =1, rowinc =0, switchvar;
  //initialise front
  for(int i=0; i< mDimension; i++){
    for(int j=0; j< mDimension; j++){
      front[i][j]=0;
    }
  }
  for(int i= mDimension*mDimension-1; i>-1 ; i--){
    front[row][col] = mCube[i];
    if(col+colinc >= mDimension || row+rowinc >= mDimension ||
       row+rowinc < 0 || front[row+rowinc][col+colinc]!=0)    {
      switchvar = colinc;
      colinc    = -rowinc;
      rowinc    = switchvar;
    }
    row += rowinc;
    col += colinc;
  }

  std::cout << "Front:" << '\n';
  for(int i=0; i < mDimension; i++){
    for(int j=0; j < mDimension; j++){
      std::cout << front[i][j] << ", ";
    }
    std::cout << "\n";
  }
  // Display =====================
  int numberOfDigits = countDigits(mCube[mDimension*mDimension-1]);
  std::cout << "Front:" << '\n';
  std::string spaces;
  for(int i=0; i < mDimension; i++){
    for(int j=0; j < mDimension; j++){
      spaces = ", ";
      for(int ia=0; ia < numberOfDigits-countDigits(front[i][j]); ia++){
        spaces.append(" ");
      }
      std::cout << front[i][j] << spaces;
    }
    std::cout << "\n";
  }
}

// int* Cube::RotateCW(int* Face){
//   int length = pow(mDimension,2);
//   return &length;
// }

Cube::~Cube(){
  delete[] MidArray;
  delete[] FBArray;
}

Cube::countDigits(double number){
  int digits =0;
  while(number-0.99999999999 > 10e-12){ // bit of a hack
    number/=10;
    digits++;
  }
  return digits;
}
