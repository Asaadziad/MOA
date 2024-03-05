#ifndef MISSILE_SYSTEM_H
#define MISSILE_SYSTEM_H

#include <memory>
#include <list>
#include "missile.h"

class MissileSystem {
  public:
  MissileSystem(){};

  void shootMissile(unsigned int start_x, unsigned int start_y, Direction d);
  std::list<std::unique_ptr<Missile>>& getMissiles();
  private:
    std::list<std::unique_ptr<Missile>> missiles;
};

#endif
