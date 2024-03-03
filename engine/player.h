#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "missile.h"
#include <queue>

class Player {
 public:
  Player(unsigned int x, unsigned int y): pos_x(x), pos_y(y), speed_x(2), speed_y(2), hp(100) {};
  
  void update();
  void draw();
  void shoot();



  /** GETTERS & SETTERS **/
  unsigned int getPosX();
  unsigned int getPosY();
  int getSpeedX();
  int getSpeedY();

  void setSpeedX(int new_speedx);
  void setSpeedY(int new_speedy);
  /** END OF GETTERS & SETTERS **/
 
 private:
   unsigned int pos_x;
   unsigned int pos_y;
   unsigned int hp;
   unsigned int score;
   int speed_x;
   int speed_y;
   std::vector<Missile*> missiles_shooted;
};

#endif
