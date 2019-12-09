#ifndef CUBEHEADERDEF
#define CUBEHEADERDEF

#include <array>

class Cube
{
  public:
    //To write default and specialist constructor - default private?
    Cube(int dimension);
    void Top();
    void Bottom();
    void Front();
    void Back();
    void Left();
    void Right();

    void DisplayInTerminal();

    ~Cube();

  private:
    int mDimension;
    int* FBArray;
    int* MidArray;
    int* mCube;
    int mDimCounter;
    int* RotateCW(int* Face);
    int* RotateACW(int* Face);
    // std::array<std::array<int>> mCube;

    Cube();

};
#endif
