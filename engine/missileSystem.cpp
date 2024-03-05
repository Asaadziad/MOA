#include "missileSystem.h"

std::list<std::unique_ptr<Missile>>& MissileSystem::getMissiles() {
  return missiles;
}

void MissileSystem::shootMissile(unsigned int start_x
   ,unsigned int start_y, Direction d) {
  
  missiles.push_front(std::make_unique<Missile>(start_x,start_y, d));
}
