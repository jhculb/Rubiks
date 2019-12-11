#ifndef IOHEADERDEF
#define IOHEADERDEF

#include "cube.hpp"
#include <array>
#include <string>

// Enumeration
enum commands{};

void initialIO(Cube* myCube);

commands hashit(std::string const& inString);

void interactionLoop(Cube &myCube);

#endif
