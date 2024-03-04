#ifndef ENEMEY_H
#define ENEMEY_H

#include <vector>
#include "missile.h"
#include "missileSystem.h"
#include "entity.h"

class Enemey: public Entity {
  public:
    Enemey(unsigned int x, unsigned int y): Entity(x, y, 50 ,50), frame_ticks(0) {};
  void update(MissileSystem& missileSystem);
  void draw(MissileSystem& missileSystem);
   
  private:
    unsigned int frame_ticks; 
};

#endif
