#ifndef ENTITY_H
#define ENTITY_H

#include "MOARect.h"

struct MOA_Rect{
  int x;
  int y;
  int h;
  int w;    
  MOA_Rect(){};
  MOA_Rect(int x, int y,int width, int height): x(x),y(y),h(height),w(width){};
};

class Entity {
  public:
    Entity(){};
    Entity(unsigned int x, unsigned int y): pos_x(x), pos_y(y) {}; 
    Entity(unsigned int x, unsigned int y, unsigned int height, unsigned int width): pos_x(x),pos_y(y), height(height), width(width), bounding_rect(x,y,width,height) {}; 
    Entity(Entity& e);

    /** GETTERS & SETTERS  **/
    unsigned int getPosX();
    unsigned int getPosY(); 
    unsigned int getHeight();
    unsigned int getWidth();
    MOA_Rect getBoundings();
    
    void setPosX(unsigned int new_x);
    void setPosY(unsigned int new_y);
    void setHeight(unsigned int new_height);
    void setWidth(unsigned int new_width);
    void setBoundings(MOA_Rect rect);
    
  private:
    unsigned int pos_x;
    unsigned int pos_y;
    unsigned int height;
    unsigned int width;


    MOA_Rect     bounding_rect;
};

#endif
