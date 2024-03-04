#include <iostream>
#include <raylib.h>
#include "physics.h"
#include "player.h"
#include "enemey.h"
#include "missileSystem.h"

int main() {
  InitWindow(800, 600, "MOA");
  
  Physics physics;
  MissileSystem missile_system;
  
  SetTargetFPS(60);
  Player p(375, 375);
  Enemey e(375, 100);
  while(!WindowShouldClose()) {
    ClearBackground(BLACK);
    
    p.update(missile_system);
    e.update(missile_system);
    
    for(auto& missile: missile_system.getMissiles()) {
      if(physics.IsCollision(*missile, e) ||
          physics.IsCollision(*missile, p) ) {
        std::cout << "COLLIDED" << std::endl; 
      }
    }

    p.draw(missile_system); 
    e.draw(missile_system);
    EndDrawing();
  }

  CloseWindow();  

  return 0;

}
