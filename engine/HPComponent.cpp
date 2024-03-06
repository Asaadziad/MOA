#include "HPComponent.h"
#include "raylib.h"

void HPComponent::draw(int bottom_left_x,int bottom_left_y,int width ,int height) {
  unsigned int green_width = ((double)hp/100) * width; 
  DrawRectangle(bottom_left_x, bottom_left_y, width, height, RED);
  DrawRectangle(bottom_left_x, bottom_left_y,green_width,height, GREEN);
}

unsigned int HPComponent::getHP() {
  return hp;
}

void HPComponent::setHP(unsigned int new_hp) {
  hp = new_hp;
}
