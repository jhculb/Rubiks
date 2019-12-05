#include "cube.hpp"
#include <cassert>
#include <iostream>
#include <cmath>
Cube::Cube(int dimension){
  //must be int, greater than 0
  //assert()

  mDimension = dimension; // set private mDimension
  int MidArraySize = (mDimension-2)*(pow(mDimension,2)-1);
  int FBArraySize = 2*pow(mDimension,2);
  FBArray = new int[FBArraySize];
  MidArray = new int[MidArraySize];
  int j = pow(mDimension,2);

  //Check m>3
  int numberOuterCubes = pow(mDimension,3) - pow(mDimension-2,3);
  for(int i = 0; i < numberOuterCubes; i++){
    if(i < pow(mDimension,2)){
      std::cout << "FBArray["<<i<<"] = "<<i<<"\n" ;
      FBArray[i] = i;
    }
    else if((i>=mDimension)&&(i<numberOuterCubes - pow(mDimension,2))){
      std::cout << "MidArray[" <<i-mDimension<< "] = " <<i<< "\n" ;
      MidArray[i-mDimension] = i;
    }
    else{
      std::cout << "FBArray["<<j<<"] = "<<i<<"\n";
      FBArray[j] = i;
      j++;
    }
  }
}

Cube::~Cube(){
  delete[] MidArray;
  delete[] FBArray;
}
