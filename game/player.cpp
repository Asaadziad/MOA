#include "player.h"
#include "raylib.h"

Player::Player() {
  Entity();
}

Player::Player(std::string name, int x, int y) {
  Entity(x,y);
  this->name = name;
}

void Player::render() {
  DrawRectangle(getPosition().getX(),  getPosition().getY(), 50,50 , RAYWHITE);  
}

void Player::update() {
  // do player update stuff here
}
