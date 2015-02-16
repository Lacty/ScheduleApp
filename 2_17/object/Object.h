
#pragma once
#include "../common.h"


struct ObjectData{
  float x;
  float y;
  float width;
  float height;
  Color color;
  Texture image;
};

class cObject{
protected:
  ObjectData m_obj;

public:
  cObject();

};