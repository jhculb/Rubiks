#ifndef CUBEHEADERDEF
#define CUBEHEADERDEF

#include <array>
#include <string>

class Cube
{
  public:
    //To write default constructor - default private?
    Cube(int dimension, bool verbose);
    void Front(bool Choice); // 1 == CW, 0 == ACW
    void Back(bool Choice);//
    void Top(bool Choice);//
    void Bottom(bool Choice);
    void Left(bool Choice);
    void Right(bool Choice);

    bool IsSolved();

    void DisplayInTerminal();

    ~Cube();

  private:
    int* mCube;

    int mDimension;
    int mSquareSize;
    int mCubeArraySize;
    int mMaxDigits;
    bool mVerbose;

    int* mFace;
    int* mTempFace;

    void Spiral(int* Face);
    void SpiralBack(int* Face);
    void Despiral(int* Face);

    int* Rotate(bool Direction, int* Face);
    int* RotateCW(int* Face);
    int* RotateACW(int* Face);

    // Cube();


};
#endif
