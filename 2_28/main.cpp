
#include "common.h"
#include "checkBox/CheckBox.h"
#include "label/Label.h"

int main() {
  AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);
  
  cCheckBox checkbox;
  cLabel label;
  enum{
    OBJECT_MOVE_SPEED = 6
  };

  checkbox.LoadData();
  while (env.isOpen()) {
    checkbox.Update(env);

    if (env.isPressKey(GLFW_KEY_UP)){
      checkbox.MoveObj(-OBJECT_MOVE_SPEED);
      label.MoveObj(-OBJECT_MOVE_SPEED);
    }
    if (env.isPressKey(GLFW_KEY_DOWN)){
      checkbox.MoveObj(OBJECT_MOVE_SPEED);
      label.MoveObj(OBJECT_MOVE_SPEED);
    }


    env.setupDraw();
    {
      checkbox.Draw();
      label.Draw();
    }
    env.update();
  }
  checkbox.SaveData();

}
