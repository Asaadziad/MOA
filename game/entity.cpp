#include "entity.h"

Entity::Entity() {
  position.setX(0);
  position.setY(0);
  position.setZ(0);
}

Entity::Entity(int x, int y) {
  position.setX(x);
  position.setY(y);
  position.setZ(0);
}

Vec3 Entity::getPosition() {
  return position;
}
