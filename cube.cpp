#include "cube.hpp"
#include <cassert>
#include <iostream>
#include <cmath>
#include <array>
#include <string>

int countDigits(double number);
void sayRotation(std::string Side, bool direction);

Cube::Cube(const int dimension, const bool verbose, const bool autocheck){
  SetCube(dimension, verbose, autocheck);
}

Cube::Cube(){
  mSetup = false;
}

void Cube::SetCube(const int dimension, const bool verbose,const bool autocheck)
{
  if(!mSetup){

    //must be int, greater than 0
    //Max value 720
    //assert()
    //1D has an error!

    mDimension = dimension; // set private mDimension
    mVerbose = verbose;
    mAutoCheck = autocheck;

    mSquareSize = pow(mDimension,2);
    mCubeArraySize=pow(mDimension, 3)-pow(mDimension-2, 3);

    mCube = new int[mCubeArraySize];
    for(int i=0; i< mCubeArraySize; i++){
      mCube[i]= i+1;
    }

    mMaxDigits = countDigits(mCube[mCubeArraySize-1]);
    mFace = new int[mDimension*mDimension]{};
    mTempFace = new int[mDimension*mDimension]{};

    mSetup = true;
  }else{
    std::cerr << "Cube Already Set" << '\n';
  }
}

bool Cube::IsSolved(){
  bool IsSolved = true;
  for(int i=0; i< mCubeArraySize; i++){
    if (mCube[i]!=i+1){
        IsSolved=false;
    }
  }
  return IsSolved;
}

void Cube::Front(const bool Choice){

  //Makes a copy of the front
  for(int i=0;i<mDimension;i++){
    for(int j=0;j<mDimension;j++){
      mFace[i*mDimension+j]=mCube[i*mDimension+j];
    }
  }

  // Passes it to rotate
  Rotate(Choice);
  // Imposes over cube
  for(int i=0;i<mDimension;i++){
    for(int j=0;j<mDimension;j++){
      mCube[i*mDimension+j]=mFace[i*mDimension+j];
    }
  }
  ExecuteCubeDefinitions("Front",Choice);
}

void Cube::Back(const bool Choice){
  //Makes a copy of the front
  for(int i=0;i<mDimension;i++){
    for(int j=0;j<mDimension;j++){
      mFace[i*mDimension+j]=mCube[mCubeArraySize-(i*mDimension+j)-1];
    }
  }  // Passes it to rotate
  Rotate(Choice);
  for(int i=0;i<mDimension;i++){// Imposes over cube
    for(int j=0;j<mDimension;j++){
      mCube[mCubeArraySize-(i*mDimension+j)-1]=mFace[i*mDimension+j];
    }
  }
  ExecuteCubeDefinitions("Back",Choice);
}

void Cube::Top(const bool Choice){
  // Calculates the Top
  for(int i=mDimension*mDimension-1; i>=0; i--){
    if(i%mDimension!=0){
      if(i/mDimension==mDimension-1){
        mFace[i]=mCube[mDimension*mDimension-1-i%mDimension];
        //top row, first slice off by one
      }
      else{
        mFace[i]=mCube[mDimension*mDimension+
        (mDimension-1-i/mDimension)*4*(mDimension-1)
        -i%mDimension];
      }
      //right (n-1) sequence
    }else if(i==mDimension*(mDimension-1)){
      mFace[i]=mCube[mDimension*mDimension-1];
    }else{
      //left hand column - seems to be correct
      mFace[i]=mCube[mDimension*mDimension+
      (mDimension-2-i/mDimension)*4*(mDimension-1)];
    }
  }  // Passes it to rotate

  Despiral(mFace);
  Rotate(Choice);
  Spiral(mFace);

  for(int i=mDimension*mDimension-1; i>=0; i--){// Imposes over cube
    if(i%mDimension!=0){
      if(i/mDimension==mDimension-1){
        mCube[mDimension*mDimension-1-i%mDimension] = mFace[i];
      }
      else{
        mCube[mDimension*mDimension+
        (mDimension-1-i/mDimension)*4*(mDimension-1)-i%mDimension] = mFace[i];
      }
    }else if(i==mDimension*(mDimension-1)){
        mCube[mDimension*mDimension-1]=mFace[i];
    }else{
        mCube[mDimension*mDimension+
        (mDimension-2-i/mDimension)*4*(mDimension-1)] = mFace[i];
    }
  }
  ExecuteCubeDefinitions("Top",Choice);
}

void Cube::Bottom(const bool Choice){

  for(int i=mDimension*mDimension-1; i>=0; i--){
    if(i/mDimension==mDimension-1){// Bottom row, first slice off by one
      mFace[i]=mCube[mDimension*mDimension-1-3*(mDimension-1)+i%mDimension];
    }else{
      mFace[i]=mCube[mDimension*mDimension+
      (mDimension-1-i/mDimension)*4*(mDimension-1)-
      3*(mDimension-1)+
      i%mDimension];
    }
  }

  Despiral(mFace);
  Rotate(Choice);
  Spiral(mFace);

  for(int i=mDimension*mDimension-1; i>=0; i--){
      if(i/mDimension==mDimension-1){// Bottom row, first slice off by one
        mCube[mDimension*mDimension-1-3*(mDimension-1)+i%mDimension]=mFace[i];
      }else{
        mCube[mDimension*mDimension+
        (mDimension-1-i/mDimension)*4*(mDimension-1)-
        3*(mDimension-1)+
        i%mDimension]=mFace[i];
      }
  }
  ExecuteCubeDefinitions("Bottom",Choice);
}

void Cube::Left(const bool Choice){

  for(int i=0; i<mDimension;i++){
    for(int j=0; j<mDimension;j++){
      if(j==mDimension-1){// Front Slice (Rightmost Column)
        if(i==0){// Top row
          mFace[i*mDimension+j]=mCube[mDimension*mDimension - 1];
        }else{// Not Top row
          mFace[i*mDimension+j]=mCube[(mDimension-2)*(mDimension-2)+i-1];
        }
      }else{// Other Slices
        mFace[i*mDimension+j]
        =mCube[(mDimension)*(mDimension)+i+(mDimension-j-2)*4*(mDimension-1)];
      }
    }
  }

  Despiral(mFace);
  Rotate(Choice);
  Spiral(mFace);

  for(int i=0; i<mDimension;i++){
    for(int j=0; j<mDimension;j++){
      if(j==mDimension-1){// Front Slice (Rightmost Column)
        if(i==0){// Top row
          mCube[mDimension*mDimension - 1]=mFace[i*mDimension+j];
        }else{// Not Top row
          mCube[(mDimension-2)*(mDimension-2)+i-1]=mFace[i*mDimension+j];
        }
      }else{// Other Slices
        mCube[(mDimension)*(mDimension)+i+(mDimension-j-2)*4*(mDimension-1)]
        =mFace[i*mDimension+j];
      }
    }
  }
  ExecuteCubeDefinitions("Left",Choice);
}

void Cube::Right(const bool Choice){

  for(int i=0; i<mDimension;i++){
    for(int j=0; j<mDimension;j++){
      if(j==mDimension-1){// Front Slice (Rightmost column)
        mFace[i*mDimension+j]=mCube[mCubeArraySize
        -(mDimension-2)*(mDimension-1)-2-i-j*4*(mDimension-1)];
      }else{// Other Slices
        mFace[i*mDimension+j]=mCube[mCubeArraySize
        -(mDimension-2)*(mDimension-1)-1-i-j*4*(mDimension-1)];
      }
    }
  }

  Despiral(mFace);
  Rotate(Choice);
  Spiral(mFace);

  for(int i=0; i<mDimension;i++){
    for(int j=0; j<mDimension;j++){
      if(j==mDimension-1){// Front Slice (Rightmost column)
        mCube[mCubeArraySize-(mDimension-2)*(mDimension-1)-2
        -i-j*4*(mDimension-1)]
        =mFace[i*mDimension+j];
      }else{// Other Slices
        mCube[mCubeArraySize-(mDimension-2)*(mDimension-1)-1
        -i-j*4*(mDimension-1)]
        =mFace[i*mDimension+j];
      }
    }
  }
  ExecuteCubeDefinitions("Right",Choice);
}

void Cube::Spiral(int* Face){

  for(int i=0; i< mDimension; i++){
    for(int j=0; j< mDimension; j++){
      mTempFace[i*mDimension+j] =0;
    }
  }
  int col =0, row =0, colinc =1, rowinc =0, switchvar;
  for(int i= mDimension*mDimension-1; i>-1 ; i--){
    mTempFace[row*mDimension+col] = Face[i];
    if(col+colinc >= mDimension || row+rowinc >= mDimension ||
       row+rowinc < 0 || mTempFace[(row+rowinc)*mDimension+col+colinc]!=0){
      switchvar = colinc;
      colinc    = -rowinc;
      rowinc    = switchvar;
    }
    row += rowinc;
    col += colinc;
  }
  for(int i=0; i< mDimension; i++){
    for(int j=0; j< mDimension; j++){
       Face[i*mDimension+j]=mTempFace[i*mDimension+j];
    }
  }
}

void Cube::SpiralBack(int* Face){

  for(int i=0; i< mDimension; i++){
    for(int j=0; j< mDimension; j++){
      mTempFace[i*mDimension+j] =0;
    }
  }
  int col =0, row =0, colinc =0, rowinc =1, switchvar;
  for(int i= mDimension*mDimension-1; i>-1 ; i--){
    mTempFace[row*mDimension+col] = Face[i];
    if(col+colinc >= mDimension || row+rowinc >= mDimension ||
       row+rowinc < 0 || mTempFace[(row+rowinc)*mDimension+col+colinc]!=0){
      switchvar = rowinc;
      rowinc    = -colinc;
      colinc    = switchvar;
    }
    row += rowinc;
    col += colinc;
  }
  for(int i=0; i< mDimension; i++){
    for(int j=0; j< mDimension; j++){
       Face[i*mDimension+j]=mTempFace[i*mDimension+j];
    }
  }
}

void Cube::Despiral(int* Face){

  for(int i=0; i< mDimension; i++){// Initialise mTempFace
    for(int j=0; j< mDimension; j++){
      mTempFace[i*mDimension+j] =0;
    }
  }

  int centreIndex,row, col, colinc, rowinc, switchvar; //Initalise variables
  if(mDimension%2==1){// If odd dimension
    centreIndex = mDimension/2-1;
    // Don't need to adjust for odd division as integer divide
    std::cout << "centreIndex" << '\n';
    row     = centreIndex;// Starting position
    col     = centreIndex;
    colinc  = 0;// Direction
    rowinc  =-1;
  }else{// Is even (start from centre square, bottom left)
    centreIndex = mDimension/2;
    row     = centreIndex;// Starting position
    col     = centreIndex-1;
    colinc  = 0;// Direction
    rowinc  = 1;
  }

  bool isNotInmTempFace;
  for(int i = 0; i < mDimension*mDimension; i++){
    mTempFace[i] = Face[row*mDimension+col];
    // From col/row inc perspective, the left is not filled, turn left
    isNotInmTempFace=true;
    for(int j=0;j<i;j++){
      if(mTempFace[j]==Face[(row-colinc)*mDimension+col+rowinc]){
        isNotInmTempFace=false;
      }
    }
    if(isNotInmTempFace){
      switchvar = rowinc;
      rowinc = -colinc;
      colinc = switchvar;
    }
    row+=rowinc;
    col+=colinc;
  }
  for(int i=0; i< mDimension; i++){
    for(int j=0; j< mDimension; j++){
       Face[i*mDimension+j]=mTempFace[i*mDimension+j];
    }
  }
}

void Cube::Rotate(const bool Direction){

  if(Direction==1){
    RotateCW();
  }else if(Direction==0){
    RotateACW();
  }else{
    std::cerr << "Not -1 / 1, error handle" << '\n';
  }
}

void Cube::RotateCW(){

  int switchvar;
  for(int i=2+mDimension%2;i<=mDimension;i+=2){
    for(int j=0;j<i-1;j++){
      switchvar              = mFace[i*i-j-(i-1)*3-1]; // Store 3
      mFace[i*i-j-(i-1)*3-1]  = mFace[i*i-j-(i-1)*2-1]; // 5 overwriting 3
      mFace[i*i-j-(i-1)*2-1]  = mFace[i*i-j-(i-1)-1] ;  // 7 overwriting 5
      mFace[i*i-j-(i-1)-1]    = mFace[i*i-j-1];         // 9 overwriting 7
      mFace[i*i-j-1]          = switchvar;             // 3 overwriting 9
    }
  }
}

void Cube::RotateACW(){

  int switchvar;
  for(int i=2+mDimension%2;i<=mDimension;i+=2){
    for(int j=0;j<i-1;j++){
      switchvar              = mFace[i*i-j-(i-1)*3-1]; // Store 3
      mFace[i*i-j-(i-1)*3-1]  = mFace[i*i-j-1];         // 9 overwriting 3
      mFace[i*i-j-1]          = mFace[i*i-j-(i-1)-1];   // 7 overwriting 9
      mFace[i*i-j-(i-1)-1]    = mFace[i*i-j-(i-1)*2-1]; // 5 overwriting 7
      mFace[i*i-j-(i-1)*2-1]  = switchvar;             // 3 overwriting 5
    }
  }
}

void Cube::DisplayInTerminal(){

  // Front Calculation ==================
  int col =0, row =0, colinc =1, rowinc =0, switchvar;

  for(int i=0; i< mDimension; i++){// Initialise Front
    for(int j=0; j< mDimension; j++){
      mFace[i*mDimension+j] = mCube[i*mDimension+j];
    }
  }
  Spiral(mFace);
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
  for(int slice =1; slice <= mDimension-2; slice++){ // Choose which slice
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
  // Initialise Back
  int CounterFor_mFace = mDimension*mDimension-1;
  for(int i= 0; i<mDimension*mDimension ; i++){
    mFace[mDimension*mDimension-1-i] = mCube[mCubeArraySize-mDimension*mDimension+i];
  }
  SpiralBack(mFace);

  // Back -----------------------
  std::cout << "Back:" << '\n';
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

void Cube::ExecuteCubeDefinitions(std::string Action, bool Choice){

  if(mVerbose){
    sayRotation(Action,Choice);
  }
  if(mAutoCheck){
    if(IsSolved()){
      std::cout << "Solved!" << '\n';
    }
  }
}

int countDigits(double number){
  int digits =0;
  while(number-0.99999999999 > 10e-12){ // bit of a hack
    number/=10;
    digits++;
  }
  return digits;
}

Cube::~Cube(){
  delete[] mCube;
  delete[] mFace;
  delete[] mTempFace;
}

void sayRotation(std::string Side, bool direction){

  std::string ChoiceOutputString;
  if(direction==1){
    ChoiceOutputString=" Clockwise";
  }else if(direction==0){
    ChoiceOutputString=" Anti-Clockwise";
  }else{
    ChoiceOutputString=" Null - bad input";
  }
  std::cout << "Rotated " << Side << ChoiceOutputString << '\n';
}

void Cube::debugmFace(){
  std::cout << "Debugging Mface:" << '\n';
  for(int i=0;i<mDimension;i++){
    for(int j=0;j<mDimension;j++){
      std::cout << mFace[i*mDimension+j] << ", ";
    }
    std::cout << '\n';
  }
}
