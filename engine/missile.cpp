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
 switch(direction) {
  case NORTH:
    
    setPosY(y_res);
    break;
  case EAST:
    setPosX(x_res); 
    break;
  case WEST: 
    setPosX(getPosX() + speed); 
    break;
  case SOUTH:
    setPosY(getPosY() + speed);
    break;
 };
}

void Missile::draw() {
  DrawRectangle(getPosX(), getPosY(), getWidth(), getHeight(), RED);
}
