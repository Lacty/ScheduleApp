
#pragma once
#include "../common.h"
#include "../object/Object.h"


class cCheckBox : public cObject{
private:
  enum{
    EMPTY,     // 0
    CHECKED    // 1
  };
  short m_isCheck[BOX_MAX];

  ObjectData m_obj[BOX_MAX];
  Texture m_box_image;
  Vec2f m_mousePos;
  void BoxCheck(AppEnv& env);

public:
  cCheckBox();

  void Update(AppEnv& env);
  void Draw();

  void MoveObj(float y);

};