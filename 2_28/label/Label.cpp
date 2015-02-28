
#include "Label.h"
#include "../lib/utils.hpp"
#include <iostream>


cLabel::cLabel() :
m_text("res/MeiryoConsolas.ttf") {
  m_text.size(FONT_SIZE);

  {
    ObjectData l_obj;
    const float OFFSET_X = TEX_DRAWSIZE / 2;
    const float OFFSET_Y = 12.0f;
    const float SPACE = TEX_DRAWSIZE / 5 + OFFSET_Y;
    for (int i = 0; i < BOX_MAX; ++i){
      l_obj.x = -WIDTH / 2 + TEX_DRAWSIZE + OFFSET_X;

      //l_obj.y = HEIGHT / 2 - (TEX_DRAWSIZE + SPACE) * (i + 1);
      l_obj.y = HEIGHT / 2 - TEX_DRAWSIZE / 5 * 6 * i - TEX_DRAWSIZE;

      l_obj.color = Color(1, 1, 1);
      m_obj.push_back(l_obj);

      //m_obj[i].x = -WIDTH / 2 + TEX_DRAWSIZE / 5 * 7;
      //m_obj[i].y = HEIGHT / 2 - TEX_DRAWSIZE / 5 * 6 * i - TEX_DRAWSIZE + 12;
      //m_obj[i].color = Color(1, 1, 1);
    }
  }
}

void cLabel::MoveObj(float y){
  for (int i = 0; i < m_obj.size(); ++i){
    m_obj[i].y += y;
  }

  if (m_obj[0].y < HEIGHT / 2 - TEX_DRAWSIZE){
    for (int i = 0; i < m_obj.size(); ++i){
      m_obj[i].y -= y;
    }
  }
  if (m_obj[m_obj.size() - 1].y > -HEIGHT / 2 + 12*2){
    for (int i = 0; i < m_obj.size(); ++i){
      m_obj[i].y -= y;
    }
  }
}

void cLabel::Draw(){
  std::ifstream fstr("res/saveData.txt");
  std::string str_temp;
  int num_temp;
  fstr >> num_temp;
  for (int i = 0; i < m_obj.size(); ++i){
    fstr >> num_temp;
    fstr >> str_temp;
    m_label.push_back(str_temp);
  }

  /*const std::string label[] = {
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
  };*/

  for (unsigned int i = 0; i < m_obj.size(); ++i){
    m_text.draw(m_label[i], Vec2f(m_obj[i].x, m_obj[i].y), m_obj[i].color);
  }
}