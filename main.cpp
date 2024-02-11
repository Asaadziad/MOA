#include <iostream>
#include <raylib.h>
#include <dlfcn.h>
#include "engine.h"

engine_update_t engine_update = NULL;
const char* libengine_file = "libengine.so";
void* libengine = NULL;

bool reload_engine() {
  if(libengine != NULL) dlclose(libengine);

  libengine = dlopen(libengine_file, RTLD_NOW);

  if(libengine == NULL) {
      std::cout << "error"<< std::endl;
      return false;
    }

    engine_update = (engine_update_t)dlsym(libengine, "engine_update");
    if(engine_update == NULL) {
      std::cout << "couldnt find symbol"<< std::endl;
      return false;
    }
  return true;
}

int main() {
  if(!reload_engine()) return 1;

  const int screenWidth  = 800;
  const int screenHeight = 600;
    
  InitWindow(screenWidth, screenHeight, "Mystery of Asaad");

  SetTargetFPS(60);
      
  
  while(!WindowShouldClose()){
    if(IsKeyPressed(KEY_R)) {
      if(!reload_engine()) return 1;    
      std::cout << "hey" << std::endl;

    } 
    engine_update();
   
  }

  CloseWindow();
  return 0;
}
