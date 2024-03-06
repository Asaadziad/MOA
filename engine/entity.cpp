#include "entity.h"

Entity::Entity(Entity& e) {
  pos_x = e.getPosX();
  pos_y = e.getPosY(); 
  width = e.getWidth();
  height = e.getHeight();
  setBoundings(e.getBoundings());
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
MOA_Rect Entity::getBoundings() {
  return bounding_rect; 
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
void Entity::setBoundings(MOA_Rect rect) {
  bounding_rect.x = rect.x;
  bounding_rect.y = rect.y;
  bounding_rect.h = rect.h;
  bounding_rect.w = rect.w;
}

