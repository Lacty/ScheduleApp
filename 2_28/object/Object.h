
#pragma once
#include "../common.h"
#include <fstream>

class cObject{
protected:
  enum{
    TEX_DRAWSIZE = 50,    // �摜�`��T�C�Y
    TEX_CUTSIZE = 100     // �摜�؂���T�C�Y
  };

  int BOX_MAX;            // �`�F�b�N�{�b�N�X�̐�

  struct ObjectData{
    float x;
    float y;
    Color color;
  };

public:
  cObject();

};