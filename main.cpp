#include <iostream>
#include <raylib.h>
#include <dlfcn.h>
#include "game/game.h"


int main() {
  Game game;
  const int screenWidth  = 800;
  const int screenHeight = 600;
    
  InitWindow(screenWidth, screenHeight, "Mystery of Asaad");

  SetTargetFPS(60);
  game.init();    
  while(!WindowShouldClose()){
    if(IsKeyPressed(KEY_S)) {
      std::cout << "Save state" << std::endl;
    } 
    game.updateAndRender(); 
  }

  CloseWindow();
  return 0;
}
