#include "game.h"
#include "raylib.h"
#include "player.h"
#include <vector>

struct game_state_t {
  int time;
  std::vector<Player> players;
};

Game::Game() {
  GameState newState = new game_state_t;
  newState->time = 0;
  this->state = newState;
}

void Game::init() {
  this->state->players.push_back(Player("asaad",250,250));
}

std::vector<Player> Game::getPlayers() {
  return this->state->players;
}

void Game::updateAndRender() {
    BeginDrawing();
    ClearBackground(RED);
    
    for(auto &player : this->state->players) {
      player.update();
      player.render();
    }
     
    EndDrawing(); 

}
