#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <vector>

typedef struct game_state_t* GameState;

class Game {
  public:
    Game();
    void init(); // shall give it state later 
    void updateAndRender(); 

    std::vector<Player> getPlayers();
  private:
    GameState state;
};


#endif // GAME_H
