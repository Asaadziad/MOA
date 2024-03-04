#include "missile.h"

void Missile::update() {
 switch(direction) {
  case NORTH:
    setPosY(getPosY() - speed);
    break;
  case EAST:
    setPosX(getPosX() - speed); 
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
