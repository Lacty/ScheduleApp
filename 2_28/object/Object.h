
#pragma once
#include "../common.h"
#include <fstream>

class cObject{
protected:
  enum{
    TEX_DRAWSIZE = 50,    // 画像描画サイズ
    TEX_CUTSIZE = 100     // 画像切り取りサイズ
  };

  int BOX_MAX;            // チェックボックスの数

  struct ObjectData{
    float x;
    float y;
    Color color;
  };

public:
  cObject();

};