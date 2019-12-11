#include "cube.hpp"
#include <iostream>

int main()
{
  //Max value 720 --- to include in constructor
  int FirstCubeDim =5;
  Cube myCube(FirstCubeDim);
  // myCube.Top(1);
  // myCube.Front(1);
  // myCube.Back(1);
  // myCube.Top(-1);
  // myCube.Front(-1);
  // myCube.Back(-1);
  // bool y = myCube.IsSolved();

  myCube.Left(1);
  
  // myCube.DisplayInTerminal();
  // myCube.Front(1);
  // while(myCube.IsSolved()==false){
  //   myCube.Front(1);
  //   Counter++;
  // }
  // std::cout << Counter << '\n';
  // myCube.DisplayInTerminal();
  return 0;
}
