#include "player.h"
#include <iostream> 


  int Player::getSpeedX(){
    return speed_x;
  }
  int Player::getSpeedY(){
    return speed_y;
  }

  unsigned int Player::getScore(){
    return score;
  }
  void Player::setSpeedX(int new_speedx){
    speed_x = new_speedx;
  }
  void Player::setSpeedY(int new_speedy){
    speed_y = new_speedy;
  }
  void Player::setScore(unsigned int new_score) {
    score = new_score;
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
  
    if(IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
      if(checkBoundariesX(getPosX() + speed_x)) setPosX(getPosX() + speed_x);
    }
    if(IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
      if(checkBoundariesX(getPosX() - speed_x)) setPosX(getPosX() - speed_x);
    }
  
    if(IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
      if(checkBoundariesY(getPosY() - speed_y)) setPosY(getPosY() - speed_y);
    }
    if(IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
      if(checkBoundariesY(getPosY() + speed_y)) setPosY(getPosY() + speed_y);
    } 
    
    if(IsKeyDown(KEY_SPACE) || IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
     missileSystem.shootMissile(getPosX(),getPosY() - 10, NORTH); 
    }
    if(IsKeyPressed(KEY_Z)) {
      std::cout << "COORDX: "<< getPosX()
        << " COORDY: " << getPosY() << std::endl;
    }   
   
    
}

void Player::draw(MissileSystem& missileSystem) {
  hp.draw(0, 550, 100, 50);
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

