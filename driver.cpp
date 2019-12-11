#include "cube.hpp"
#include <iostream>

int main()
{
  //Max value 720
  int FirstCubeDim = 3;
  Cube myCube(FirstCubeDim);
  myCube.DisplayInTerminal();
  myCube.Top(1);
  myCube.DisplayInTerminal();
  myCube.Top(-1);
  myCube.DisplayInTerminal();
  myCube.Front(-1);
  myCube.DisplayInTerminal();
  myCube.Back(-1);
  myCube.DisplayInTerminal();
  myCube.Front(1);
  myCube.DisplayInTerminal();
  myCube.Back(1);
  myCube.DisplayInTerminal();
  // myCube.Back(-1);
  // myCube.DisplayInTerminal();


  return 0;
}
