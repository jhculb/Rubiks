#include "cube.hpp"
#include "IOfunctions.hpp"
#include <iostream>

int main(){

  Cube Jcube;
  initialIO(&Jcube);
  interactionLoop(Jcube);

  return 0;
}
