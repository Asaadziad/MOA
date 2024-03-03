#include "enemey.h"


void Enemey::update(){ 
  frame_ticks++;
  if(frame_ticks >= 60) {
    shoot();
    frame_ticks = 0;
  }

  for( auto missile: missiles_shooted) {
    missile->update();
  }
}
void Enemey::draw(){
  DrawRectangle(pos_x,pos_y,50,50,RED);
  for( auto missile: missiles_shooted) {
    missile->draw();
  }

}
void Enemey::shoot(){
  missiles_shooted.push_back(new Missile(pos_x + 20,pos_y + 50, SOUTH));
}
