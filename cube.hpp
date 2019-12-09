#ifndef CUBEHEADERDEF
#define CUBEHEADERDEF

#include <array>

class Cube
{
  public:
    //To write default and specialist constructor - default private?
    Cube(int dimension);
    void Top(int Choice);
    void Bottom(int Choice);
    void Front(int Choice);
    void Back(int Choice);
    void Left(int Choice);
    void Right(int Choice);

    void DisplayInTerminal();

    ~Cube();

  private:
    int* mCube;
    int mDimension;
    int mCubeArraySize;
    int* Rotate(int Direction, int* Face);
    int* RotateCW(int* Face);
    int* RotateACW(int* Face);
    int* mRotated;
    int* mFace;
    // std::array<std::array<int>> mCube;

    Cube();

    int countDigits(double number);

};
#endif
