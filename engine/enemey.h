#ifndef ENEMEY_H
#define ENEMEY_H

#include <vector>
#include "missile.h"

class Enemey {
  public:
    Enemey(unsigned int x, unsigned int y): pos_x(x),pos_y(y), hp(100), frame_ticks(0) {};
  void update();
  void draw();
  void shoot();
  
  private:
    unsigned int pos_x;
    unsigned int pos_y;
    unsigned int hp;
    unsigned int frame_ticks;

    std::vector<Missile*> missiles_shooted;
};

#endif
