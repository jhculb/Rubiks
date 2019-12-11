#ifndef CUBEHEADERDEF
#define CUBEHEADERDEF

#include <array>

class Cube
{
  public:
    //To write default and specialist constructor - default private?
    Cube(int dimension);
    void Front(int Choice);//
    void Back(int Choice);//
    void Top(int Choice);//
    void Bottom(int Choice);
    void Left(int Choice);
    void Right(int Choice);

    bool IsSolved();

    void DisplayInTerminal();

    ~Cube();

  private:
    int* mCube;

    int mDimension;
    int mSquareSize;
    int mCubeArraySize;
    int mMaxDigits;

    int* mFace;
    int* mTempFace;

    void Spiral(int* Face);
    void CWspiral(int* Face);
    void Despiral(int* Face);

    int* Rotate(int Direction, int* Face);
    int* RotateCW(int* Face);
    int* RotateACW(int* Face);

    // Cube();

    int countDigits(double number);

};
#endif
