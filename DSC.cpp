#include "cube.hpp"
#include <iostream>

int main()
{
  int CubeDim;
  for(int i=1; i<8;i++){
    CubeDim = i;
    Cube myCube(CubeDim);
    myCube.DisplayInTerminal();
    std::cout  << '\n';
  }
  return 0;
}
