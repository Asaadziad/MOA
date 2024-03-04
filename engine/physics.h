#ifndef PHYSICS_H
#define PHYSICS_H

#include "entity.h"

class Physics {
  public:
    Physics(){};

    bool IsCollision(Entity e1, Entity e2);
};

#endif
