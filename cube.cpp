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

  mMaxDigits = countDigits(mCube[mCubeArraySize-1]);
  mRotated = new int [mDimension];
  mFace = new int[mDimension*mDimension]{};
  mTempFace = new int[mDimension*mDimension]{};
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

void Cube::Top(int Choice){
  // Calculates the Top
  for(int i=mDimension*mDimension-1; i>=0; i--){
    if(i%mDimension!=0){
      if(i/mDimension==mDimension-1){
        mFace[i]=mCube[mDimension*mDimension-1-i%mDimension];
        //bottom row, off by one
      }
      else{
        // mFace[i]=mCube[mDimension*(mDimension-1)+(mDimension-1-i/mDimension)*4*(mDimension-1)-(i%mDimension-mDimension)];
        mFace[i]=mCube[mDimension*mDimension+(mDimension-1-i/mDimension)*4*(mDimension-1)-i%mDimension];
      }
      //right (n-1) sequence
    }else if(i==mDimension*(mDimension-1)){
      mFace[i]=mCube[mDimension*mDimension-1];
    }else{
      //left hand column - seems to be correct
      mFace[i]=mCube[mDimension*mDimension+(mDimension-2-i/mDimension)*4*(mDimension-1)];
    }
  }

  for(int i=0;i<mDimension;i++){
    for(int j=0;j<mDimension;j++){
      std::cout << mFace[i*mDimension+j] << ", ";
    }
    std::cout << '\n';
  }
  std::cout << '\n';
  // Passes it to rotate
  mFace = Rotate(Choice, mFace);
  // Imposes over cube

  for(int i=0;i<mDimension;i++){
    for(int j=0;j<mDimension;j++){
      std::cout << mFace[i*mDimension+j] << ", ";
    }
    std::cout << '\n';
  }
  std::cout << '\n';

  for(int i=mDimension*mDimension-1; i>=0; i--){
    if(i%mDimension!=0){
      if(i/mDimension==mDimension-1){
        mCube[mDimension*mDimension-1-i%mDimension] = mFace[i];
      }
      else{
        mCube[mDimension*mDimension+(mDimension-1-i/mDimension)*4*(mDimension-1)-i%mDimension] = mFace[i];
      }
    }else if(i==mDimension*(mDimension-1)){
        mCube[mDimension*mDimension-1]=mFace[i];
    }else{
        mCube[mDimension*mDimension+(mDimension-2-i/mDimension)*4*(mDimension-1)] = mFace[i];
    }
  }
}

int* Despiral(int* Face){
  //despiral if even: check bottom left or top right
  if(mDimension%2=1)
  {
    
  }
  else{
    std::cout << "Even dim Despiral: Not implemented yet" << "\n";
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
  int col =0, row =0, colinc =1, rowinc =0, switchvar;
  //initialise front
  for(int i=0; i< mDimension; i++){
    for(int j=0; j< mDimension; j++){
      mFace[i*mDimension+j] =0;
    }
  }
  for(int i= mDimension*mDimension-1; i>-1 ; i--){
    mFace[row*mDimension+col] = mCube[i];
    if(col+colinc >= mDimension || row+rowinc >= mDimension ||
       row+rowinc < 0 || mFace[(row+rowinc)*mDimension+col+colinc]!=0){
      switchvar = colinc;
      colinc    = -rowinc;
      rowinc    = switchvar;
    }
    row += rowinc;
    col += colinc;
  }


  // Display =====================
  // Front -----------------------
  std::cout << "Front:" << '\n';
  std::string spaces;
  for(int i=0; i < mDimension; i++){
    for(int j=0; j < mDimension; j++){
      spaces = ", ";
      for(int ia=0; ia < mMaxDigits-countDigits(mFace[i*mDimension+j]); ia++){
        spaces.append(" ");
      }
      std::cout << mFace[i*mDimension+j] << spaces;
    }
    std::cout << "\n";
  }
  std::cout << '\n';

  // Middle ---------------------
  int maxIndex;
  std::string stringRow;
  for(int slice =1; slice <= mDimension-2; slice++){
    std::cout << "Slice " << slice << ":" << '\n'; // Preamble
    maxIndex = mDimension*mDimension+4*(mDimension-1)*slice-1;

    for(int i=0; i < mDimension; i++){
      stringRow =std::to_string(
                    mCube[mDimension*mDimension+4*(mDimension-1)*(slice-1)+i]);
      stringRow.append(", ");
      for(int ia=0;ia<mMaxDigits-countDigits(
        mCube[mDimension*mDimension+4*(mDimension-1)*(slice-1)+i]);ia++){
        stringRow.append(" ");
      }
      if(i==0){// First Row
        for(int j=0; j < mDimension-1; j++){
          stringRow.append(std::to_string(mCube[maxIndex-j]));
          stringRow.append(", ");
          for(int ia=0;ia<mMaxDigits-countDigits(mCube[maxIndex-j]);ia++){
            stringRow.append(" ");
          }
        }
      }else if(i==mDimension-1){// Last row
        int baseIndex = mDimension*mDimension+4*(mDimension-1)*(slice-1)+i;
        for(int j=1;j<=mDimension-1;j++){
          stringRow.append(std::to_string(mCube[baseIndex+j]));
          for(int ia=0;ia<mMaxDigits-countDigits(mCube[baseIndex+j]);ia++){
            stringRow.append(" ");
          }
          stringRow.append(", ");
        }
      }else{// Middle rows
        for(int j=0; j < mDimension-2; j++){
          stringRow.append("  "); // Comma spaces
          for(int ia=0; ia < mMaxDigits; ia++){
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
      mFace[i*mDimension+j] =0;
    }
  }

  col =0, row =0, colinc =0, rowinc =1;
  for(int i= mCubeArraySize-mDimension*mDimension; i<mCubeArraySize ; i++){
    mFace[row*mDimension+col] = mCube[i];
    if(col+colinc >= mDimension || row+rowinc >= mDimension ||
       row+rowinc < 0 || mFace[(row+rowinc)*mDimension+col+colinc]!=0){
      switchvar = rowinc;
      rowinc    = -colinc;
      colinc    = switchvar;
    }
    row += rowinc;
    col += colinc;
  }
  // Back -----------------------
  std::cout << "Back:" << '\n';
  // Front -----------------------
  for(int i=0; i < mDimension; i++){
    for(int j=0; j < mDimension; j++){
      spaces = ", ";
      for(int ia=0; ia < mMaxDigits-countDigits(mFace[i*mDimension+j]); ia++){
        spaces.append(" ");
      }
      std::cout << mFace[i*mDimension+j] << spaces;
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
