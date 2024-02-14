#include "player.h"
#include "raylib.h"

Player::Player(): Entity() {}

Player::Player(std::string name, int x, int y):Entity(x,y) { 
  this->name = name;
}

void Player::render() { 
  DrawCircle(getPosition().getX(),  getPosition().getY(), 50 ,RAYWHITE);  
}

static bool CollisionWithBorders(int x, int y) {
  if (x + 50 >= 800 || x - 50 <= 0) return true;
  if (y + 50 >= 600 || y - 50 <= 0) return true;
  return false;
}

void Player::update() {
  // do player update stuff here
  if(!CollisionWithBorders(getPosition().getX(), getPosition().getY())) {
   getPosition().setY(getPosition().getY() + 10);   
  } 
}
