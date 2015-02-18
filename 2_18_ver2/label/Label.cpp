
#include "Label.h"
#include "../lib/utils.hpp"


cLabel::cLabel() :
m_text("res/MeiryoConsolas.ttf") {
  m_text.size(FONT_SIZE);

  for (int i = 0; i < BOX_MAX; ++i){
    m_obj[i].x = -WIDTH / 2 + TEX_DRAWSIZE / 5 * 7;
    m_obj[i].y = HEIGHT / 2 - TEX_DRAWSIZE / 5 * 6 * i - TEX_DRAWSIZE + 12;
    m_obj[i].color = Color(1, 1, 1);
  }
}

void cLabel::MoveObj(float y){
  for (int i = 0; i < BOX_MAX; ++i){
    m_obj[i].y += y;
  }

  if (m_obj[0].y < HEIGHT / 2 - TEX_DRAWSIZE + 12){
    for (int i = 0; i < BOX_MAX; ++i){
      //m_obj[i].y = HEIGHT / 2 - TEX_DRAWSIZE / 5 * 6 * i - TEX_DRAWSIZE + 12;
      m_obj[i].y -= y;
    }
  }
  if (m_obj[BOX_MAX -1].y > -HEIGHT / 2 + 12){
    for (int i = 0; i < BOX_MAX; ++i){
      m_obj[i].y -= y;
    }
  }
}

void cLabel::Draw(){
  const std::string label[] = {
    "Ball",
    "Balls",
    "Ball_array",
    "Ball_container",
    "Camera_Sample",
    "Copy_Texture",
    "Easing",
    "Haetataki",
    "Jump",
    "LeftOrRight",
    "LineScroll",
    "MikuAnime",
    "Pendulum",
    "RankingSample",
    "Rolling",
    "SceneSample",
    "Shot",
    "Text_Read",
    "Eigin_Sample",
    "MapChipFromFile",
    "MapParts",
    "WindowDisp‡W",
  };

  for (unsigned int i = 0; i < elemsof(label); ++i){
    m_text.draw(label[i], Vec2f(m_obj[i].x, m_obj[i].y), m_obj[i].color);
  }
}