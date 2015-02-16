
#pragma once
#include "../common.h"
#include "../object/Object.h"


class cCheckBox : public cObject{
private:
  enum{
    BOX_MAX      = 27,     // チェックボックスの数
    TEX_DRAWSIZE = 50,     // 画像描画サイズ
    TEX_CUTSIZE  = 100     // 画像切り取りサイズ
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