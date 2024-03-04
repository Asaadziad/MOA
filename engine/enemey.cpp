#include "enemey.h"

void Enemey::update(MissileSystem& missileSystem){ 
  frame_ticks++;
  if(frame_ticks >= 60) {
    missileSystem.shootMissile(getPosX(), getPosY() + getHeight() + 10, SOUTH);
    frame_ticks = 0;
  }
   for(auto& missile: missileSystem.getMissiles()) {
      missile->update();
   }
  
}
void Enemey::draw(MissileSystem& missileSystem){
  DrawRectangle(getPosX(),getPosY(), getWidth(), getHeight() ,RED);
  
  for(auto& missile: missileSystem.getMissiles()) {
    missile->draw();
  }
}

