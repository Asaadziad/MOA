#include "physics.h"
#include <iostream>

static void printEntityStats(Entity e) {
  std::cout << "STATS:" <<std::endl;
  std::cout << "CoordX: " << e.getPosX() << ", CoordY" << e.getPosY() << std::endl;
  std::cout << "Width: " << e.getWidth() << ", Height: " << e.getHeight() << std::endl;
    
}
bool Physics::IsCollision(Entity e1, Entity e2){
  unsigned int x1 = e1.getPosX();
  unsigned int y1 = e1.getPosY();
  unsigned int x2 = e2.getPosX();
  unsigned int y2 = e2.getPosY();
  unsigned int h1 = e1.getHeight();
  unsigned int h2 = e2.getHeight();
  unsigned int w1 = e1.getWidth();
  unsigned int w2 = e2.getWidth();
 
  printEntityStats(e1);
  printEntityStats(e2);
   
  if(x1 + w1 >= 800 || x2 + w2 >= 800 || x1 <= 0 || x2 <= 0 ||
     y1 + h1 >= 600 || y2 + h2 >= 600 || y1 <= 0 || y2 <= 0){
     
    return true; 
  }
   
  if((x1 + w1 >= x2 &&
     x1 + w1 < x2 + w2 &&
     y1 + h1 < y2 + h2 &&
     y1 + h1 > y2) ||
     (y2 <= y1 + h1 &&
      y2 + h2 > y1 + h1 &&
      x1 < x2 + w2 &&
      x1 + w1 > x2 + w2) ) {
     
    return true;
  } 

  return false;
}
