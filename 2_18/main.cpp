
#include "common.h"
#include "checkBox/CheckBox.h"
#include "label/Label.h"

int main() {
  AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);
  
  cCheckBox checkbox;
  cLabel label;
  while (env.isOpen()) {
    checkbox.Update(env);

    env.setupDraw();
    checkbox.Draw();
    label.Draw();

    env.update();
  }
}
