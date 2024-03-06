#include <iostream>
#include <raylib.h>
#include "physics.h"
#include "player.h"
#include "enemey.h"
#include "missileSystem.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

static bool isOutOfBoundaries(MOA_Rect rect){
  std::cout << rect.y;
  
  if(rect.x + rect.w >= SCREEN_WIDTH ||
      rect.x <= 0 ||
      rect.y + rect.h >= SCREEN_HEIGHT ||
      rect.y <= 0) {
    return true;
  }
  return false;
}

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

    

    std::list<std::unique_ptr<Missile>>::iterator iter; 
    for(iter = missile_system.getMissiles().begin(); iter != missile_system.getMissiles().end(); ) {
      std::list<std::unique_ptr<Missile>>::iterator tmp;
      tmp = iter;
      ++iter;
      if(physics.IsCollision(p, **tmp)) { 
        p.loseHP(5);
        missile_system.getMissiles().erase(tmp);
         
      }
      if(*tmp == nullptr) continue; 
      if(physics.IsCollision(e, **tmp)) {
        e.loseHP(5);
        missile_system.getMissiles().erase(tmp);
      }
      if(*tmp == nullptr) continue;
      if(isOutOfBoundaries((**tmp).getBoundings())) {
          missile_system.getMissiles().erase(tmp);
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
