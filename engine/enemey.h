#ifndef ENEMEY_H
#define ENEMEY_H

#include <vector>
#include "missile.h"
#include "missileSystem.h"
#include "entity.h"
#include "HPComponent.h"
class Enemey: public Entity {
  public:
    Enemey(unsigned int x, unsigned int y): Entity(x, y, 50 ,50), frame_ticks(0) {};
  void update(MissileSystem& missileSystem);
  void draw(MissileSystem& missileSystem);

  void loseHP(unsigned int hp);  
  private:
    unsigned int frame_ticks; 
    HPComponent hp;
};

#endif
