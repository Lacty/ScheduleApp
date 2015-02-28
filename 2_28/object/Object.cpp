
#include "Object.h"


cObject::cObject(){
  std::ifstream fstr("res/saveData.txt");
  fstr >> BOX_MAX;
}
