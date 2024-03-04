#ifndef ENTITY_H
#define ENTITY_H



class Entity {
  public:
    Entity(){};
    Entity(unsigned int x, unsigned int y): pos_x(x), pos_y(y) {}; 
    Entity(unsigned int x, unsigned int y, unsigned int height, unsigned int width): pos_x(x),pos_y(y), height(height), width(width) {}; 
    Entity(Entity& e);

    /** GETTERS & SETTERS  **/
    unsigned int getPosX();
    unsigned int getPosY(); 
    unsigned int getHeight();
    unsigned int getWidth();


    void setPosX(unsigned int new_x);
    void setPosY(unsigned int new_y);
    void setHeight(unsigned int new_height);
    void setWidth(unsigned int new_width);
  private:
    unsigned int pos_x;
    unsigned int pos_y;
    unsigned int height;
    unsigned int width;
};

#endif
