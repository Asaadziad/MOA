#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include <string>

class Player : public Entity {
  public:
    Player();
    Player(std::string name, int x, int y);
    void update();
    void render();
  private:
    std::string name;
};

#endif
