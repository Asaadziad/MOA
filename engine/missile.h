#ifndef MISSILE_H
#define MISSILE_H

#include "raylib.h"
#include "entity.h"

#define MISSILE_SPEED_CONST 4

typedef enum {
  NORTH,
  EAST,
  WEST,
  SOUTH,
} Direction;

class Missile: public Entity {
  public:
    Missile(unsigned int start_x, unsigned int start_y, Direction d) : Entity(start_x,start_y, 10, 10), speed(MISSILE_SPEED_CONST), direction(d) {};
    Missile(unsigned int start_x, unsigned int start_y): Entity(start_x,start_y, 10, 10), speed(MISSILE_SPEED_CONST), direction(NORTH)  {};
    void update();
    void draw();
      
  private:
    int          speed;
    Direction    direction;
};

#endif
