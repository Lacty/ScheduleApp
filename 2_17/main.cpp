
#include "common.h"
#include "checkBox/CheckBox.h"

int main() {
  AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);
  
  cCheckBox checkbox;
  while (env.isOpen()) {
    checkbox.Update(env);

    env.setupDraw();
    checkbox.Draw();

    env.update();
  }
}
