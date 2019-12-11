#include "cube.hpp"
#include "IOfunctions.hpp"
// #include <iostream>

int main(){

  Cube cube = initialIO();

  interactionLoop(cube);

  return 0;
}
