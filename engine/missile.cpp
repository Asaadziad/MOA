#include "missile.h"

void Missile::update() {
 unsigned int x = getPosX();
 unsigned int y = getPosY();
 int y_res = y - speed;
 int x_res = x - speed;
 if(y_res < 0) {
  y_res = 0;
 }
 if(x_res < 0) {
  x_res = 0;
 }
 MOA_Rect current_rect = getBoundings();
 switch(direction) {
  case NORTH:
    
    setPosY(y_res);
    current_rect.y = y_res;
    break;
  case EAST:
    setPosX(x_res); 
    current_rect.x = x_res;
    break;
  case WEST: 
    setPosX(getPosX() + speed);
    current_rect.x = getPosX() + speed; 
    break;
  case SOUTH:
    setPosY(getPosY() + speed);
    current_rect.y = getPosY() + speed;
    break;
 };
 setBoundings(current_rect);
}

void Missile::draw() {
  DrawRectangle(getPosX(), getPosY(), getWidth(), getHeight(), RED);
}
