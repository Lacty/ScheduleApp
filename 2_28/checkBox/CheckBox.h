
#pragma once
#include "../common.h"
#include "../object/Object.h"
#include <vector>
#include <string>


class cCheckBox : public cObject{
private:
  enum{
    EMPTY,     // 0
    CHECKED    // 1
  };
  std::vector<short> m_isCheck;
  std::vector<std::string> m_label;

  std::vector<ObjectData> m_obj;
  Texture m_box_image;
  Vec2f m_mousePos;
  void BoxCheck(AppEnv& env);

public:
  cCheckBox();

  void Update(AppEnv& env);
  void Draw();

  void MoveObj(float y);
  void LoadData();
  void SaveData();

};