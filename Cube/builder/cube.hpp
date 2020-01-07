#ifndef CUBEHEADERDEF
#define CUBEHEADERDEF

#include <array>
#include <string>

class Cube
{
  public:
    // Specialised constructor: initialises cube
    Cube(const int dimension,const  bool verbose,const bool autocheck);

    // Default constructor: creates empty cube
    Cube(); 
    // Takes empty cube and initialises
    void SetCube(const int dimension, const bool verbose, const bool autocheck);
    
    // To do: Copy constructor?
    // Cube(Cube inputCube);
    

    // Cube Rotation functions, Choice determines rotation direction, 1 is clockwise, 0 is anticlockwise
    void Front(const bool Choice);
    void Back(const bool Choice);
    void Top(const bool Choice);
    void Bottom(const bool Choice);
    void Left(const bool Choice);
    void Right(const bool Choice);
    void MiddleVertical(int Slice);   // Right side Bias in rotation, count from front (left column), to the back (right column)
    void MiddleHorizontal(int Slice); // Top side bias, top row of cube is the right column

    // Cube Output Functions
    bool IsSolved();
    void DisplayInTerminal();

    // Destructor
    ~Cube();

  private:
    
    int* mCube;         // Array with cube positioning

    int* mFace;         // Temporary variable used for rotations: square used for representing a face
    int* mTempFace;     // Temporary variable used for rotations, acted on by rotate
    int* mMiddleFace;   // Temporary variable used for rotations, was required for middle rotations to fix bug (may be extraneous now)

    int mDimension;     // Dimension of Cube
    int mSquareSize;    // Number of positions in a face
    int mCubeArraySize; // Number of positions in the whole cube
    int mMaxDigits;     // Largest digit in the cube (to check: this is the case)
    bool mVerbose;      // Should a function display to terminal the state of the cube after a rotation
    bool mAutoCheck;    // Should the cube report if it is solved after a rotation
    bool mSetup;        // Variable to check whether the cube has been initialised
   
    void Spiral(int* Face);       // Takes mCube positioned faces and wraps them into spacially positioned faces in CW orientation
    void SpiralBack(int* Face);   // Takes mCube positioned faces and wraps them into spacially positioned faces in ACW orientation (for back face)
    void Despiral(int* Face);     // Takes spacially positioned faces and wraps them into mCube positioned faces in CW orientation
    void DespiralBack(int* Face); // Takes spacially positioned faces and wraps them into mCube positioned faces in ACW orientation

    void Rotate(const bool Direction);  // Wrapper function for rotation
    void RotateCW();                    // Rotates mTempface CW
    void RotateACW();                   // Rotates mTempface ACW

    void ExecuteCubeDefinitions(std::string Action, bool Choice); // Wrapper function to execute verbose actions and autochecking

    void debugmFace();        // Displays mFace
    void debugmTempFace();    // Displays mTempFace
    void debugmMiddleFace();  // Displays mMiddleFace

};
#endif
