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
    mCube[i]= i+1; // could change this to zero based
    // such a minor efficiency though?
  }

  mRotated = new int [mDimension];
  mFace = new int[mDimension*mDimension]{};
}

void Cube::Front(int Choice){
  //Makes a copy of the front
  for(int i=0;i<mDimension;i++){
    for(int j=0;j<mDimension;j++){
      mFace[i*mDimension+j]=mCube[i*mDimension+j];
      std::cout << mFace[i*mDimension+j] << '\n';
    }
  }

  // Passes it to rotate
  mFace = Rotate(Choice, mFace);
  // Imposes over cube
  for(int i=0;i<mDimension;i++){
    for(int j=0;j<mDimension;j++){
      mCube[i*mDimension+j]=mFace[i*mDimension+j];
    }
  }
}

void Cube::Top(int Choice){
  //Makes a copy of the front
  for(int i=0;i<mDimension;i++){
    for(int j=0;j<mDimension;j++){
      mFace[i*mDimension+j]=mCube[i*mDimension+j];
    }
  }
  // Passes it to rotate
  mFace = Rotate(Choice, mFace);
  // Imposes over cube
  for(int i=0;i<mDimension;i++){
    for(int j=0;j<mDimension;j++){
      mCube[i*mDimension+j]=mFace[i*mDimension+j];
    }
  }
}

void Cube::Back(int Choice){
  //Makes a copy of the front
  for(int i=0;i<mDimension;i++){
    for(int j=0;j<mDimension;j++){
      mFace[i*mDimension+j]=mCube[mCubeArraySize-(i*mDimension+j)-1];
    }
  }
  // Passes it to rotate
  mFace = Rotate(-Choice, mFace);
  // Imposes over cube
  for(int i=0;i<mDimension;i++){
    for(int j=0;j<mDimension;j++){
      mCube[mCubeArraySize-(i*mDimension+j)-1]=mFace[i*mDimension+j];
    }
  }
}

int* Cube::Rotate(int Direction, int* Face){
  if(Direction==1){
    mFace = RotateCW(mFace);
  }else if(Direction==-1){
    mFace = RotateACW(mFace);
  }else
  {
    std::cerr << "Not -1 / 1, error handle" << '\n';
  }
  return mFace;
}

int* Cube::RotateCW(int* Face){
  int switchvar;
  if(mDimension%2==1){
    // for odd
    for(int i=3;i<=mDimension;i+=2){
      for(int j=0;j<i-1;j++){
        switchvar              = Face[i*i-j-(i-1)*3-1]; // Store 3
        Face[i*i-j-(i-1)*3-1]  = Face[i*i-j-(i-1)*2-1]; // 5 overwriting 3
        Face[i*i-j-(i-1)*2-1]  = Face[i*i-j-(i-1)-1] ;  // 7 overwriting 5
        Face[i*i-j-(i-1)-1]    = Face[i*i-j-1];         // 9 overwriting 7
        Face[i*i-j-1]          = switchvar;             // 3 overwriting 9
      }
    }
  }else{
    // for even
    std::cout << "Haven't implemented even yet" << '\n';
  }
  return Face;
}

int* Cube::RotateACW(int* Face){
  int switchvar;
  // for odd
  if(mDimension%2==1){
    for(int i=3;i<=mDimension;i+=2){
      for(int j=0;j<i-1;j++){
        switchvar              = Face[i*i-j-(i-1)*3-1]; // Store 3
        Face[i*i-j-(i-1)*3-1]  = Face[i*i-j-1];         // 9 overwriting 3
        Face[i*i-j-1]          = Face[i*i-j-(i-1)-1];   // 7 overwriting 9
        Face[i*i-j-(i-1)-1]    = Face[i*i-j-(i-1)*2-1]; // 5 overwriting 7
        Face[i*i-j-(i-1)*2-1]  = switchvar;             // 3 overwriting 5
      }
    }
  }else{
    // for even
    std::cout << "Haven't implemented even yet" << '\n';
  }
  return Face;
}

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
  std::cout << '\n' << '\n';
}

Cube::~Cube(){
  delete[] mCube;
  delete[] mFace;
  delete[] mRotated;
}
