#include <iostream>
#include <raylib.h>
#include "physics.h"
#include "player.h"
#include "enemey.h"
#include "missileSystem.h"
#include <vector>

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

struct GameData {
  std::vector<std::unique_ptr<Enemey>> enemies; 
  GameData(){};
};

int main() { 
  InitWindow(800, 600, "MOA");
  GameData data; 
  Physics physics;
  MissileSystem missile_system;
  
  SetTargetFPS(60);
  Player p(375, 375);
  Enemey e(375, 100);   
  
  data.enemies.push_back(std::make_unique<Enemey>(375,100)); 
  data.enemies.push_back(std::make_unique<Enemey>(200,100));
  data.enemies.push_back(std::make_unique<Enemey>(450,100));
  data.enemies.push_back(std::make_unique<Enemey>(300,100));

  int frame_i = 0;
  while(!WindowShouldClose()) {
    ClearBackground(BLACK);
    std::string score_string = "Score: " + std::to_string(p.getScore());
    DrawText(score_string.c_str(), 0, 0, 28, WHITE); 
    for(auto& enemey: data.enemies) {
      enemey->update(missile_system);
    } 
    p.update(missile_system);
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
      std::vector<std::unique_ptr<Enemey>>::iterator it;
      for(it = data.enemies.begin(); it != data.enemies.end();) {
      std::vector<std::unique_ptr<Enemey>>::iterator tmp_it;
      tmp_it = it;
      it++; 
      if(physics.IsCollision(**tmp_it, **tmp)) {
          (*tmp_it)->loseHP(5);
          if((*tmp_it)->getHPComponent().getHP() == 0 ) {
            data.enemies.erase(tmp_it);
            p.setScore(p.getScore() + 1);            
          }
          missile_system.getMissiles().erase(tmp);
          break; 
        }
      }
      if(*tmp == nullptr) continue;
      if(isOutOfBoundaries((**tmp).getBoundings())) {
          missile_system.getMissiles().erase(tmp);
      } 

    }

    p.draw(missile_system); 
    for(auto& enemey: data.enemies) {
      enemey->draw(missile_system);
    }
    for(auto& missile : missile_system.getMissiles()) {
      
      missile->draw();
    }

    frame_i++;
    EndDrawing();
  }

  

  CloseWindow();  

  return 0;

}
