
#pragma once
#include "../common.h"


class cObject{
protected:
  enum{
    BOX_MAX = 22,     // チェックボックスの数
    TEX_DRAWSIZE = 50,     // 画像描画サイズ
    TEX_CUTSIZE = 100     // 画像切り取りサイズ
  };

  struct ObjectData{
    float x;
    float y;
    Color color;
  };

public:
  cObject();

};