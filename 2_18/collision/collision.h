
#pragma once
#include "../common.h"


// �_�Ƌ�`�̂����蔻��
bool PointToRectCollision(Vec2f point_pos,
                   Vec2f object_pos, Vec2f object_size);


// ��`�Ƌ�`�̂����蔻��
bool RectToRectCollision(Vec2f obj1_pos, Vec2f obj1_size,
                  Vec2f obj2_pos, Vec2f obj2_size);