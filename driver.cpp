#include "cube.hpp"
#include <iostream>

int main()
{
  //Max value 720
  int FirstCubeDim = 4;
  Cube myCube(FirstCubeDim);
  // myCube.DisplayInTerminal();
  // myCube.Top(1);
  // myCube.DisplayInTerminal();
  // myCube.Top(-1);
  // myCube.DisplayInTerminal();
  // myCube.Front(-1);
  // myCube.DisplayInTerminal();
  // myCube.Back(-1);
  // myCube.DisplayInTerminal();
  // myCube.Front(1);
  // myCube.DisplayInTerminal();
  // myCube.Back(1);
  // myCube.DisplayInTerminal();
  // myCube.Back(-1);
  // myCube.DisplayInTerminal();
  int Counter=1;
  myCube.DisplayInTerminal();
  myCube.Front(1);
  while(myCube.IsSolved()==false){
    myCube.Front(1);
    Counter++;
  }
  std::cout << Counter << '\n';
  myCube.DisplayInTerminal();
  return 0;
}
