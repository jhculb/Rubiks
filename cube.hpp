#ifndef CUBEHEADERDEF
#define CUBEHEADERDEF

#include <array>
#include <string>

class Cube
{
  public:
    //To write default constructor - default private?
    Cube(const int dimension,const  bool verbose,const bool autocheck);
    Cube();

    void SetCube(const int dimension, const bool verbose, const bool autocheck);

    void Front(const bool Choice); // 1 == CW, 0 == ACW
    void Back(const bool Choice);
    void Top(const bool Choice);
    void Bottom(const bool Choice);
    void Left(const bool Choice);
    void Right(const bool Choice);

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
    bool mAutoCheck;
    bool mSetup;


    int* mFace;
    int* mTempFace;

    int* Spiral(const int* Face);
    int* SpiralBack(const int* Face);
    int* Despiral(const int* Face);

    void Rotate(const bool Direction);
    void RotateCW();
    void RotateACW();

    void ExecuteCubeDefinitions(std::string Action, bool Choice);


};
#endif
