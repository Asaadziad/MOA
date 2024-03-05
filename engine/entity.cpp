#include "entity.h"

Entity::Entity(Entity& e) {
  pos_x = e.getPosX();
  pos_y = e.getPosY(); 
  width = e.getWidth();
  height = e.getHeight();
}


unsigned int Entity::getPosX() {
  return pos_x;
}
unsigned int Entity::getPosY() {
  return pos_y;
}
unsigned int Entity::getWidth() {
  return width;
}
unsigned int Entity::getHeight() {
  return height;
}


void Entity::setPosX(unsigned int new_x) {
  pos_x = new_x;
}
void Entity::setPosY(unsigned int new_y){
  pos_y = new_y;   
}
void Entity::setWidth(unsigned int width) {
  width = width;
}
void Entity::setHeight(unsigned int height) {
  height = height;
}
