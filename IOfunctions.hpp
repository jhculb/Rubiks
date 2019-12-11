#ifndef IOHEADERDEF
#define IOHEADERDEF

#include "cube.hpp"
#include <array>
#include <string>

// Enumeration
enum commands{};

Cube initialIO();

commands hashit(std::string const& inString);

void interactionLoop(Cube myCube);

#endif
