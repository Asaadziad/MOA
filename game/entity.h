#ifndef ENTITY_H
#define ENTITY_H

#include "../math/vec3.h"

class Entity {
  public:
    Entity();
    Entity(int x, int y);
    Entity(int x, int y, int z);
    Vec3 getPosition();
  private:
    Vec3 position; 
};

#endif
