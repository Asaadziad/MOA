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
  int frame_i = 0;
  while(!WindowShouldClose()) {
    ClearBackground(BLACK);
    
    p.update(missile_system);
    e.update(missile_system);
    for(auto& missile: missile_system.getMissiles()) {
      missile->update();
    } 

    

    
    if(missile_system.getMissiles().size() > 0) {
      
      if(physics.IsCollision(p, *missile_system.getMissiles().back())) {
        p.loseHP(1);
        missile_system.getMissiles().pop_back();
      }
     if(physics.IsCollision(e, *missile_system.getMissiles().back())) {
        e.loseHP(5);
        missile_system.getMissiles().pop_back(); 
     }
    } 
   
    p.draw(missile_system); 
    e.draw(missile_system);
    
    for(auto& missile : missile_system.getMissiles()) {
      missile->draw();
    }

    frame_i++;
    EndDrawing();
  }

  

  CloseWindow();  

  return 0;

}
