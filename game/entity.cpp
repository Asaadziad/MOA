#include "entity.h"

Entity::Entity() {
  this->position.setX(0);
  this->position.setY(0);
  this->position.setZ(0);
}

Entity::Entity(int x, int y) {
  this->position.setX(x);
  this->position.setY(y);
  this->position.setZ(0);
}

Vec3& Entity::getPosition() {
  return position;

}

