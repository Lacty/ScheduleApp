
#pragma once
#include "../common.h"
#include "../object/Object.h"
#include "../lib/font.hpp"


class cLabel : public cObject{
private:
  ObjectData m_obj[BOX_MAX];

  enum {
    FONT_SIZE = 45
  };
  Font m_text;

public:
  cLabel();

  void Draw();
};