#include <iostream>
#include <raylib.h>
#include "player.h"
#include "enemey.h"


int main() {
  InitWindow(800, 600, "MOA");
 

  SetTargetFPS(60);
  Player p(375, 375);
  Enemey e(375, 100);
  while(!WindowShouldClose()) {
    ClearBackground(BLACK);
    
    p.update();
    e.update();
    
    p.draw(); 
    e.draw();
    EndDrawing();
  }

  CloseWindow();  

  return 0;

}
