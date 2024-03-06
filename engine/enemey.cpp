#include "enemey.h"

void Enemey::update(MissileSystem& missileSystem){ 
  frame_ticks++;
  if(frame_ticks >= 60) {
    missileSystem.shootMissile(getPosX(), getPosY() + getHeight() + 10, SOUTH);
    frame_ticks = 0;
  } 
  
}

HPComponent& Enemey::getHPComponent() {
  return hp;
}

void Enemey::draw(MissileSystem& missileSystem){
  hp.draw(getPosX(), getPosY() - 20, getWidth() , 10);
  DrawRectangle(getPosX(),getPosY(), getWidth(), getHeight() ,RED); 
}

void Enemey::loseHP(unsigned int hp) {
  unsigned int new_hp = this->hp.getHP();
  int res = new_hp - hp;
  if(res < 0) {
    res = 0;
  }
  this->hp.setHP(res);
}

