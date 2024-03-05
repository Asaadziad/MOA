#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "missile.h"
#include "missileSystem.h"
#include "entity.h"
#include "HPComponent.h"
#include <vector>


class Player: public Entity {
 public:
  Player(unsigned int x, unsigned int y):Entity(x,y,50,50) , speed_x(2), speed_y(2) {};
  
  void update(MissileSystem& missileSystem);
  void draw(MissileSystem& missileSystem);
  void shoot();

  /** GETTERS & SETTERS **/ 
  int getSpeedX();
  int getSpeedY();

  void setSpeedX(int new_speedx);
  void setSpeedY(int new_speedy); 
  /** END OF GETTERS & SETTERS **/
  
  void loseHP(unsigned int hit); 
 private: 
   unsigned int score;
   HPComponent hp; 
   int speed_x;
   int speed_y;
   std::vector<Missile*> missiles_shooted;
};

#endif
