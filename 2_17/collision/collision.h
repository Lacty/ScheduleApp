
#pragma once
#include "../common.h"


// 点と矩形のあたり判定
bool PointToRectCollision(Vec2f point_pos,
                   Vec2f object_pos, Vec2f object_size);


// 矩形と矩形のあたり判定
bool RectToRectCollision(Vec2f obj1_pos, Vec2f obj1_size,
                  Vec2f obj2_pos, Vec2f obj2_size);