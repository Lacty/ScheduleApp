
#include "CheckBox.h"
#include "../collision/collision.h"
#include <fstream>


cCheckBox::cCheckBox(){
  for (int i = 0; i < BOX_MAX; ++i){
    m_obj[i].x = -WIDTH / 2 + TEX_DRAWSIZE / 5;
    m_obj[i].y = HEIGHT / 2 - TEX_DRAWSIZE / 5 * 6 * i - TEX_DRAWSIZE;
    m_obj[i].color = Color(1, 1, 1);
    m_isCheck[i] = EMPTY;
  }
  m_box_image = Texture("res/checkBox.png");
  m_mousePos = Vec2f(0, 0);
}

void cCheckBox::MoveObj(float y){
  for (int i = 0; i < BOX_MAX; ++i){
    m_obj[i].y += y;
  }

  if (m_obj[0].y < HEIGHT / 2 - TEX_DRAWSIZE){
    for (int i = 0; i < BOX_MAX; ++i){
      m_obj[i].y -= y;
    }
  }
  if (m_obj[BOX_MAX - 1].y > -HEIGHT / 2){
    for (int i = 0; i < BOX_MAX; ++i){
      m_obj[i].y -= y;
    }
  }
}

void cCheckBox::BoxCheck(AppEnv& env){
  m_mousePos = env.mousePosition();

  for (int i = 0; i < BOX_MAX; ++i){
    if (PointToRectCollision(Vec2f(m_mousePos.x(), m_mousePos.y()),
      Vec2f(m_obj[i].x, m_obj[i].y),
      Vec2f(TEX_DRAWSIZE, TEX_DRAWSIZE)))
    {
      if (env.isPushButton(LEFT)){
        if (m_isCheck[i] == EMPTY){
          m_isCheck[i] = CHECKED;
        }
        else{
          m_isCheck[i] = EMPTY;
        }
      }
    }
  }
}

void cCheckBox::LoadData(){
  std::ifstream fstr("res/saveData.txt");
  if (fstr){
    for (int i = 0; i < BOX_MAX; ++i){
      fstr >> m_isCheck[i];
    }
  }
}

void cCheckBox::SaveData(){
  std::ofstream fstr("res/saveData.txt");
  if (fstr){
    for (int i = 0; i < BOX_MAX; ++i){
      fstr << m_isCheck[i] << std::endl;
    }
  }
}

void cCheckBox::Update(AppEnv& env){
  BoxCheck(env);
}

void cCheckBox::Draw(){
  for (int i = 0; i < BOX_MAX; ++i){
    drawTextureBox(m_obj[i].x, m_obj[i].y, TEX_DRAWSIZE, TEX_DRAWSIZE,
      (TEX_CUTSIZE * 2) * m_isCheck[i], 0,
      TEX_CUTSIZE, TEX_CUTSIZE,
      m_box_image,
      m_obj[i].color);
  }
}