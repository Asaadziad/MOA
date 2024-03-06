#include "physics.h"
#include <iostream>

static void printEntityStats(Entity e) {
  std::cout << "STATS:" <<std::endl;
  std::cout << "CoordX: " << e.getPosX() << ", CoordY" << e.getPosY() << std::endl;
  std::cout << "Width: " << e.getWidth() << ", Height: " << e.getHeight() << std::endl;
    
}

static bool checkPointAABBIntersection(int x, int y,MOA_Rect rect) {
  if(x > rect.x &&
     x < rect.x + rect.w &&
     y > rect.y &&
     y < rect.y + rect.h) {
    return true;
  }

  return false; 
} 

bool Physics::IsCollision(Entity e1, Entity e2){
  unsigned int x1 = e1.getPosX();
  unsigned int y1 = e1.getPosY();
  unsigned int h1 = e1.getHeight();
  unsigned int w1 = e1.getWidth(); 
  
  unsigned int x2 = e2.getPosX();
  unsigned int y2 = e2.getPosY();
  unsigned int h2 = e2.getHeight();
  unsigned int w2 = e2.getWidth();


  MOA_Rect rect1 = e1.getBoundings();
  MOA_Rect rect2 = e2.getBoundings();
  
  printEntityStats(e1);
  printEntityStats(e2);
      
  if(x1 < x2 + w2 && x2 < x1 + w1 && y1 < y2 + h2 && y2 < y1 + h1) {
     
    return true;
  } 

  return false;
}
