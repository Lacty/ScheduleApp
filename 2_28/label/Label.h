
#pragma once
#include "../common.h"
#include "../object/Object.h"
#include "../lib/font.hpp"
#include <vector>
#include <string>


class cLabel : public cObject{
private:
  //ObjectData m_obj[BOX_MAX];
  std::vector<ObjectData> m_obj;
  std::vector<std::string> m_label;

  enum {
    FONT_SIZE = 45
  };
  Font m_text;

public:
  cLabel();

  void Draw();
  void MoveObj(float y);
};