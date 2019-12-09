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
  mCubeArraySize=pow(mDimension, 3)-pow(mDimension-2, 3);
  mCube = new int[mCubeArraySize];

  for(int i=0; i< mCubeArraySize; i++){
    mCube[i]= i+1; // could change this, such a minor efficiency though?
  }
}


// int* Cube::RotateCW(int* Face){
//   int length = pow(mDimension,2);
//   return &length;
// }
Cube::countDigits(double number){
  int digits =0;
  while(number-0.99999999999 > 10e-12){ // bit of a hack
    number/=10;
    digits++;
  }
  return digits;
}

void Cube::DisplayInTerminal(){
  // if odd!!!!
  // Front Calculation ==================
  int face[mDimension][mDimension];
  int col =0, row =0, colinc =1, rowinc =0, switchvar;
  //initialise front
  for(int i=0; i< mDimension; i++){
    for(int j=0; j< mDimension; j++){
      face[i][j] =0;
    }
  }
  for(int i= mDimension*mDimension-1; i>-1 ; i--){
    face[row][col] = mCube[i];
    if(col+colinc >= mDimension || row+rowinc >= mDimension ||
       row+rowinc < 0 || face[row+rowinc][col+colinc]!=0)    {
      switchvar = colinc;
      colinc    = -rowinc;
      rowinc    = switchvar;
    }
    row += rowinc;
    col += colinc;
  }
  // Display =====================
  // Front -----------------------
  int numberOfDigits = countDigits(mCube[mDimension*mDimension-1]);
  std::cout << "Front:" << '\n';
  std::string spaces;
  for(int i=0; i < mDimension; i++){
    for(int j=0; j < mDimension; j++){
      spaces = ", ";
      for(int ia=0; ia < numberOfDigits-countDigits(face[i][j]); ia++){
        spaces.append(" ");
      }
      std::cout << face[i][j] << spaces;
    }
    std::cout << "\n";
  }
  std::cout << '\n';

  // Middle ---------------------
  int maxInSlice, maxIndex;
  std::string stringRow;
  for(int slice =1; slice <= mDimension-2; slice++){
    std::cout << "Slice " << slice << ":" << '\n'; // Preamble
    maxIndex = mDimension*mDimension+4*(mDimension-1)*slice-1;
    maxInSlice = mCube[maxIndex];
    numberOfDigits = countDigits(maxInSlice);

    for(int i=0; i < mDimension; i++){
      stringRow =std::to_string(
                    mCube[mDimension*mDimension+4*(mDimension-1)*(slice-1)+i]);
      stringRow.append(", ");
      for(int ia=0;ia<numberOfDigits-countDigits(
        mCube[mDimension*mDimension+4*(mDimension-1)*(slice-1)+i]);ia++){
        stringRow.append(" ");
      }
      if(i==0){// First Row
        for(int j=0; j < mDimension-1; j++){
          stringRow.append(std::to_string(mCube[maxIndex-j]));
          stringRow.append(", ");
        }
      }else if(i==mDimension-1){// Last row
        int baseIndex = mDimension*mDimension+4*(mDimension-1)*(slice-1)+i;
        for(int j=1;j<=mDimension-1;j++){
          stringRow.append(std::to_string(mCube[baseIndex+j]));
          for(int ia=0;ia<numberOfDigits-countDigits(mCube[baseIndex+j]);ia++){
            stringRow.append(" ");
          }
          stringRow.append(", ");
        }
      }else{// Middle rows
        for(int j=0; j < mDimension-2; j++){
          stringRow.append("  "); // Comma spaces
          for(int ia=0; ia < numberOfDigits; ia++){
            stringRow.append(" "); // Digit spaces
          }
        }
        stringRow.append(std::to_string(mCube[maxIndex-(mDimension-2)-i]));
        stringRow.append(",");
      }
      std::cout << stringRow << "\n";
    }
    std::cout << '\n';
  }
  // Back Calculation ==================
  //initialise face
  for(int i=0; i< mDimension; i++){
    for(int j=0; j< mDimension; j++){
      face[i][j] =0;
    }
  }

  col =0, row =0, colinc =0, rowinc =1;
  for(int i= mCubeArraySize-mDimension*mDimension; i<mCubeArraySize ; i++){
    face[row][col] = mCube[i];
    if(col+colinc >= mDimension || row+rowinc >= mDimension ||
       row+rowinc < 0 || face[row+rowinc][col+colinc]!=0)    {
      switchvar = rowinc;
      rowinc    = -colinc;
      colinc    = switchvar;
    }
    row += rowinc;
    col += colinc;
  }
  // Back -----------------------
  numberOfDigits = countDigits(mCube[mCubeArraySize-1]);
  std::cout << "Back:" << '\n';
  // Front -----------------------
  for(int i=0; i < mDimension; i++){
    for(int j=0; j < mDimension; j++){
      spaces = ", ";
      for(int ia=0; ia < numberOfDigits-countDigits(face[i][j]); ia++){
        spaces.append(" ");
      }
      std::cout << face[i][j] << spaces;
    }
    std::cout << "\n";
  }
}

Cube::~Cube(){
  delete[] mCube;
}
