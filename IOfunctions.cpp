#include "cube.hpp"

#include <iostream>
#include <string>

enum commands{
  eFront,  eFrontN,  eBack,  eBackN,  eTop,  eTopN,  eBottom,  eBottomN,  eLeft,
  eLeftN,  eRight,  eRightN,  eExit,  eHelp, eShow, eCheck
};

Cube initialIO(){

  int cubeDim;
  bool unallowableInput =true, inputBool, autoInputBool;
  std::string inputString;

  while(unallowableInput){
    std::cout << "Input dimension: ";
    std::cin >> cubeDim;
    if(cubeDim<1){
      std::cout << "Please input an integer between 2 and 720, Your input was: "
      << cubeDim << '\n';
    }else if(cubeDim>720){
      std::cout << "Please input an integer between 2 and 720, Your input was: "
      << cubeDim << '\n';
    }else{
      unallowableInput = false;
    }
  }

  unallowableInput = true;
  while(unallowableInput){
    std::cout<< '\n' << "Action feedback? (y/n): " << '\n';
    std::cin >> inputString;

    if(inputString == "y"|| inputString == "Y"){
      inputBool = true;
      unallowableInput = false;
    }else if(inputString == "n"|| inputString == "N"){
      inputBool = false;
      unallowableInput = false;
    }else{
      std::cout << "Unrecognised input, please try again." << '\n';
    }
  }

  unallowableInput = true;
  while(unallowableInput){
    std::cout<< '\n' << "Auto-respond when solved? (y/n): " << '\n';
    std::cin >> inputString;

    if(inputString == "y"|| inputString == "Y"){
      autoInputBool = true;
      unallowableInput = false;
    }else if(inputString == "n"|| inputString == "N"){
      autoInputBool = false;
      unallowableInput = false;
    }else{
      std::cout << "Unrecognised input, please try again." << '\n';
    }
  }

  std::cout << "Creating " << cubeDim<<" by "<< cubeDim << " Cube" << '\n';
  if(inputBool){std::cout << "Verbose output" << '\n';}

  Cube myCube(cubeDim,inputBool,autoInputBool);
  return(myCube);
}

commands hashit(std::string const& inString){

  if(inString == "f"){
    return(eFront);
  }else if(inString == "fn"){
    return(eFrontN);
  }else if(inString == "b"){
    return(eBack);
  }else if(inString == "bn"){
    return(eBackN);
  }else if(inString == "u"){
    return(eTop);
  }else if(inString == "un"){
    return(eTopN);
  }else if(inString == "d"){
    return(eBottom);
  }else if(inString == "dn"){
    return(eBottomN);
  }else if(inString == "l"){
    return(eLeft);
  }else if(inString == "ln"){
    return(eLeftN);
  }else if(inString == "r"){
    return(eRight);
  }else if(inString == "rn"){
    return(eRightN);
  }else if(inString == "exit"){
    return(eExit);
  }else if(inString == "s"){
    return(eShow);
  }else if(inString == "c"){
    return(eCheck);
  }else if(inString == "help"){
    return(eHelp);
  }else {
    return(eHelp);
  }
}

void interactionLoop(Cube myCube){
  bool inputBool = true;
  std::string inputString;
  while (inputBool) {
    std::cout << "Input: ";
    std::cin >> inputString;
    switch (hashit(inputString)) {
      case eFront:
        myCube.Front(1);
        break;
      case eFrontN:
        myCube.Front(0);
        break;
      case eBack:
        myCube.Back(1);
        break;
      case eBackN:
        myCube.Back(0);
        break;
      case eTop:
        myCube.Top(1);
        break;
      case eTopN:
        myCube.Top(0);
        break;
      case eBottom:
        myCube.Bottom(1);
        break;
      case eBottomN:
        myCube.Bottom(0);
        break;
      case eLeft:
        myCube.Left(1);
        break;
      case eLeftN:
        myCube.Left(0);
        break;
      case eRight:
        myCube.Right(1);
        break;
      case eRightN:
        myCube.Right(0);
        break;
      case eExit:
        inputBool=false;
        break;
      case eShow:
        myCube.DisplayInTerminal();
        break;
      case eCheck:
        myCube.IsSolved();
        break;
      default:
      case eHelp:
      std::cout
        << "Possible Commands:"<< '\n'
        << "f,    Rotate front of cube clockwise"<< '\n'
        << "fn,   Rotate front of cube anticlockwise"<< '\n'
        << "b,    Rotate back of cube clockwise"<< '\n'
        << "bn,   Rotate back of cube anticlockwise"<< '\n'
        << "u,    Rotate top of cube clockwise"<< '\n'
        << "un,   Rotate top of cube anticlockwise"<< '\n'
        << "d,    Rotate bottom of cube clockwise"<< '\n'
        << "dn,   Rotate bottom of cube anticlockwise"<< '\n'
        << "l,    Rotate left of cube clockwise"<< '\n'
        << "ln,   Rotate left of cube anticlockwise"<< '\n'
        << "r,    Rotate right of cube clockwise"<< '\n'
        << "rn,   Rotate right of cube anticlockwise"<< '\n'
        << "help, exit"<< '\n';
        break;
    }
  }
}
