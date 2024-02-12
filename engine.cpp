#include <iostream>
#include <raylib.h>
#include <string>

extern "C" {
   void engine_update() {
    BeginDrawing();
    ClearBackground(RED);
    
    const char* fps = ("FPS: "+ std::to_string(GetFPS())).c_str();
    DrawText(fps, 0, 0, 25, RAYWHITE); 
    DrawText("hello world", 250,250,25,RAYWHITE); 
    EndDrawing(); 
  }
}
