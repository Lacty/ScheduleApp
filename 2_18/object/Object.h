
#pragma once
#include "../common.h"


class cObject{
protected:
  enum{
    BOX_MAX = 22,     // �`�F�b�N�{�b�N�X�̐�
    TEX_DRAWSIZE = 50,     // �摜�`��T�C�Y
    TEX_CUTSIZE = 100     // �摜�؂���T�C�Y
  };

  struct ObjectData{
    float x;
    float y;
    Color color;
  };

public:
  cObject();

};