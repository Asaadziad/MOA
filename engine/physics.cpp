#include "physics.h"

bool Physics::IsCollision(Entity e1, Entity e2){
  unsigned int x1 = e1.getPosX();
  unsigned int y1 = e1.getPosY();
  unsigned int x2 = e2.getPosX();
  unsigned int y2 = e2.getPosY();
  unsigned int h1 = e1.getHeight();
  unsigned int h2 = e2.getHeight();
  unsigned int w1 = e1.getWidth();
  unsigned int w2 = e2.getWidth();
  

  if( x2 >= x1 && x2 <= x1 + w1 ||
      x1 >= x2 && x1 <= x2 + w2 || 
      y2 >= y1 && y2 <= y1 + h1 ||
      y1 >= y2 && y1 <= y2 + h2) {
    return true;
  } 

  return false;
}
