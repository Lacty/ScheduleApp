
#include "collision.h"


bool PointToRectCollision(Vec2f point_pos,
                   Vec2f object_pos, Vec2f object_size)
{
  if ((point_pos.x() > object_pos.x()) &&
    (point_pos.x() < object_pos.x() + object_size.x())){
    if ((point_pos.y() > object_pos.y()) &&
      (point_pos.y() < object_pos.y() + object_size.y())){
      // 矩形に入っているのでtrueを返す
      return true;
    }
  }
  // 矩形に入っていないのでfalseを返す
  return false;
}


bool RectToRectCollision(Vec2f obj1_pos, Vec2f obj1_size,
                  Vec2f obj2_pos, Vec2f obj2_size)
{
  if ((obj1_pos.x() + obj1_size.x() > obj2_pos.x()) &&
    (obj1_pos.x() < obj2_pos.x() + obj2_size.x())){
    if ((obj1_pos.y() + obj2_size.y() > obj2_pos.y()) &&
      (obj2_pos.y() < obj2_pos.y() + obj2_size.y())){
      // 重なっているのでtrueを返す
      return true;
    }
  }
  // 重なっていないのでfalseを返す
  return false;
}