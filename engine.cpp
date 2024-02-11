#include <iostream>
#include <raylib.h>


extern "C" {
   void engine_update() {
    BeginDrawing();
    ClearBackground(RED);
    DrawText("Hello loser",0,0,25,RAYWHITE); 
    EndDrawing(); 
  }
}
