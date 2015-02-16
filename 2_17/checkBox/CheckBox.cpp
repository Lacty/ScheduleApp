
#include "CheckBox.h"
#include "../collision/collision.h"


cCheckBox::cCheckBox(){
  m_obj.x = -WIDTH / 2 + TEX_DRAWSIZE / 5;
  m_obj.y = HEIGHT / 2 - TEX_DRAWSIZE;
  m_obj.width = TEX_DRAWSIZE;
  m_obj.height = TEX_DRAWSIZE;
  m_obj.image = Texture("res/checkBox.png");
  for (int i = 0; i < BOX_MAX; ++i){
    m_isCheck[i] = EMPTY;
  }
  m_mousePos = Vec2f(0, 0);
}

void cCheckBox::BoxCheck(AppEnv& env){
  m_mousePos = env.mousePosition();

  for (int i = 0; i < BOX_MAX; ++i){
    if (PointToRectCollision(Vec2f(m_mousePos.x(), m_mousePos.y()),
                             Vec2f(m_obj.x, m_obj.y),
                             Vec2f(m_obj.width, m_obj.height)))
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

void cCheckBox::Update(AppEnv& env){
  BoxCheck(env);
}

void cCheckBox::Draw(){
  for (int i = 0; i < BOX_MAX; ++i){
    drawTextureBox(m_obj.x, m_obj.y, m_obj.width, m_obj.height,
      (TEX_CUTSIZE*2) * m_isCheck[i], 0,
      TEX_CUTSIZE, TEX_CUTSIZE,
      m_obj.image,
      m_obj.color);
  }
}