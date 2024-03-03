#include "missile.h"

void Missile::update() {
 switch(direction) {
  case NORTH:
    pos_y -= speed;
    break;
  case EAST:
    pos_x -= speed;
    break;
  case WEST:
    pos_x += speed;
    break;
  case SOUTH:
    pos_y += speed;
    break;
 };
}

void Missile::draw() {
  DrawRectangle(pos_x, pos_y, 10, 10, RED);
}

unsigned int Missile::getPosX(){return pos_x;}
unsigned int Missile::getPosY(){return pos_y;}
