#ifndef HP_COMPONENT_H
#define HP_COMPONENT_H

class HPComponent {
  public:
    HPComponent(unsigned int hp): hp(hp) {};
    HPComponent(): hp(100) {};
    void draw(int bottom_left_x, int bottom_left_y, int height);
    
    unsigned int getHP();
    void setHP(unsigned int new_hp);

  private:
    unsigned int hp;
};

#endif
