#ifndef CUBEHEADERDEF
#define CUBEHEADERDEF

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

    ~Cube();

  private:
    int mDimension;
    int* FBArray;
    int* MidArray;
    int mDimCounter;

    Cube();

};
#endif
