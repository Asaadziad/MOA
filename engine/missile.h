#ifndef MISSILE_H
#define MISSILE_H

#include "raylib.h"

#define MISSILE_SPEED_CONST 4

typedef enum {
  NORTH,
  EAST,
  WEST,
  SOUTH,
} Direction;

class Missile {
  public:
    Missile(unsigned int start_x, unsigned int start_y, Direction d) : pos_x(start_x), pos_y(start_y), speed(MISSILE_SPEED_CONST), direction(d) {};
    Missile(unsigned int start_x, unsigned int start_y): pos_x(start_x), pos_y(start_y), speed(MISSILE_SPEED_CONST), direction(NORTH)  {};
    void update();
    void draw();
    
    unsigned int getPosX();
    unsigned int getPosY();  
  private:
    unsigned int pos_x;
    unsigned int pos_y;
    int          speed;
    Direction    direction;
};

#endif
