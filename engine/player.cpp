#include "player.h"
#include <iostream>
  unsigned int Player::getPosX(){
    return pos_x;

  }
  unsigned int Player::getPosY(){
    return pos_y;
  }


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

void Player::update() {
  
    if(IsKeyDown(KEY_RIGHT)) {
      pos_x += speed_x;
      if(!checkBoundariesX(getPosX())) pos_x -= speed_x;
    }
    if(IsKeyDown(KEY_LEFT)) {
      pos_x -= speed_x;
      if(!checkBoundariesX(getPosX())) pos_x += speed_x;
    }
  
    if(IsKeyDown(KEY_UP)) {
      pos_y -= speed_y;
      if(!checkBoundariesY(getPosY())) pos_y += speed_y;
    }
    if(IsKeyDown(KEY_DOWN)) {
      pos_y += speed_y;
      if(!checkBoundariesY(getPosY())) pos_y -= speed_y;
    } 
    
    if(IsKeyPressed(KEY_SPACE)) {
      shoot();
    }
    if(IsKeyPressed(KEY_Z)) {
      std::cout << "COORDX: "<< getPosX()
        << " COORDY: " << getPosY() << std::endl;
    } 
  std::vector<unsigned int> to_delete;
  unsigned int i = 0;
  for(auto missile: missiles_shooted) {
    missile->update();
    if(!checkBoundariesX(missile->getPosX()) ||
        !checkBoundariesY(missile->getPosY())) {
      delete missile;
      to_delete.push_back(i);
    }
    i++;
  }

  for(auto index: to_delete) {
    missiles_shooted.erase(missiles_shooted.begin() + index);
  }
  
}

void Player::draw() {
  DrawRectangle(pos_x, pos_y, 50, 50, RED);
  for(auto missile : missiles_shooted) {
    missile->draw();
  }
}

void Player::shoot() {
  missiles_shooted.push_back(new Missile(pos_x + 20, pos_y));
}
