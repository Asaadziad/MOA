#include "player.h"
#include <iostream> 


  int Player::getSpeedX(){
    return speed_x;
  }
  int Player::getSpeedY(){
    return speed_y;
  }
  void Player::setSpeedX(int new_speedx){
    speed_x = new_speedx;
  }
  void Player::setSpeedY(int new_speedy){
    speed_y = new_speedy;
  }


static bool checkBoundariesX(unsigned int x) {
  if(x == 0 || x + 50 >= 800) return false;
 return true; 
}

static bool checkBoundariesY(unsigned int y) {
  if(y == 0 || y + 50 >= 600) return false;
 return true; 
}

void Player::update(MissileSystem& missileSystem) {
  
    if(IsKeyDown(KEY_RIGHT)) {
      if(checkBoundariesX(getPosX() + speed_x)) setPosX(getPosX() + speed_x);
    }
    if(IsKeyDown(KEY_LEFT)) {
      if(checkBoundariesX(getPosX() - speed_x)) setPosX(getPosX() - speed_x);
    }
  
    if(IsKeyDown(KEY_UP)) {
      if(checkBoundariesY(getPosY() - speed_y)) setPosY(getPosY() - speed_y);
    }
    if(IsKeyDown(KEY_DOWN)) {
      if(checkBoundariesY(getPosY() + speed_y)) setPosY(getPosY() + speed_y);
    } 
    
    if(IsKeyPressed(KEY_SPACE)) {
     missileSystem.shootMissile(getPosX(),getPosY() - 10, NORTH); 
    }
    if(IsKeyPressed(KEY_Z)) {
      std::cout << "COORDX: "<< getPosX()
        << " COORDY: " << getPosY() << std::endl;
    }   
   
    
}

void Player::draw(MissileSystem& missileSystem) {
  hp.draw(0, 550, 50);
  DrawRectangle(getPosX(), getPosY(), getWidth(), getHeight(), RED);
}


void Player::loseHP(unsigned int hp) {
  unsigned int new_hp = this->hp.getHP();
  int res = new_hp - hp;
  if(res < 0) {
    res = 0;
  }
  this->hp.setHP(res);
}

