
#include "CheckBox.h"
#include "../collision/collision.h"
#include <fstream>


cCheckBox::cCheckBox(){
  ObjectData l_obj;
  const float SPACE = TEX_DRAWSIZE / 5;

  for (int i = 0; i < BOX_MAX; ++i){
    l_obj.x = -WIDTH / 2 + TEX_DRAWSIZE / 5;
    l_obj.y = HEIGHT / 2 - (TEX_DRAWSIZE + SPACE) * (i + 1);
    l_obj.color = Color(1, 1, 1);
    m_obj.push_back(l_obj);
    m_isCheck.push_back(EMPTY);
  }
  m_box_image = Texture("res/checkBox.png");
  m_mousePos = Vec2f(0, 0);
}

void cCheckBox::MoveObj(float y){
  for (int i = 0; i < m_obj.size(); ++i){
    m_obj[i].y += y;
  }
  
  if (m_obj[0].y < HEIGHT / 2 - TEX_DRAWSIZE - 12){
    for (int i = 0; i < m_obj.size(); ++i){
      m_obj[i].y -= y;
    }
  }
  if (m_obj[m_obj.size() - 1].y > -HEIGHT / 2 + 12){
    for (int i = 0; i < m_obj.size(); ++i){
      m_obj[i].y -= y;
    }
  }
}

void cCheckBox::BoxCheck(AppEnv& env){
  m_mousePos = env.mousePosition();

  for (int i = 0; i < m_obj.size(); ++i){
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
  std::string str_temp;
  int num_temp;
  if (fstr){
    fstr >> num_temp;
    for (int i = 0; i < m_obj.size(); ++i){
      fstr >> m_isCheck[i];
      fstr >> str_temp;
      m_label.push_back(str_temp);
    }
  }
}

void cCheckBox::SaveData(){
  std::ofstream fstr("res/saveData.txt");
  if (fstr){
    fstr << m_obj.size() << std::endl;
    for (int i = 0; i < m_obj.size(); ++i){
      fstr << m_isCheck[i];
      fstr << " " << m_label[i] << std::endl;
    }
  }
}

void cCheckBox::Update(AppEnv& env){
  BoxCheck(env);
}

void cCheckBox::Draw(){
  for (int i = 0; i < m_obj.size(); ++i){
    drawTextureBox(m_obj[i].x, m_obj[i].y, TEX_DRAWSIZE, TEX_DRAWSIZE,
      (TEX_CUTSIZE * 2) * m_isCheck[i], 0,
      TEX_CUTSIZE, TEX_CUTSIZE,
      m_box_image,
      m_obj[i].color);
  }
}