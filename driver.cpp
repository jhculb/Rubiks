#include "cube.hpp"
#include <iostream>

int main()
{
  //Max value 720 --- to include in constructor
  int cubeDim = 20;
  Cube myCube(cubeDim,true);
  myCube.DisplayInTerminal();
  // myCube.Top(1);
  // myCube.Top(0);
  myCube.Bottom(1);
  // myCube.Bottom(0);
  // myCube.Front(1);
  // myCube.Front(0);
  // myCube.Back(1);
  myCube.Back(0);
  // myCube.Left(1);
  // myCube.Left(0);
  // myCube.Right(1);
  // myCube.Right(0);

  // bool y = myCube.IsSolved();

  // int Counter=0;
  // myCube.Front(1);
  // while(myCube.IsSolved()==false){
  //   if(Counter!=0){
  //     myCube.Front(1);
  //   }
  //   myCube.Top(1);
  //   myCube.Bottom(1);
  //   myCube.Front(1);
  //   myCube.Back(1);
  //   myCube.Left(1);
  //   myCube.Right(1);
  //   Counter++;
  // }
  // std::cout << Counter << '\n';
  myCube.DisplayInTerminal();
  return 0;
}
