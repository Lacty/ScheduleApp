
#pragma once
#include "../common.h"
#include "../object/Object.h"


class cCheckBox : public cObject{
private:
  enum{
    BOX_MAX      = 27,     // �`�F�b�N�{�b�N�X�̐�
    TEX_DRAWSIZE = 50,     // �摜�`��T�C�Y
    TEX_CUTSIZE  = 100     // �摜�؂���T�C�Y
  };

  enum{
    EMPTY,     // 0
    CHECKED    // 1
  };
  short m_isCheck[BOX_MAX];

  Vec2f m_mousePos;
  void BoxCheck(AppEnv& env);

public:
  cCheckBox();

  void Update(AppEnv& env);
  void Draw();

};