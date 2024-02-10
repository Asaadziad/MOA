#include "raylib.h"


int main() {
  const int screenWidth  = 800;
  const int screenHeight = 600;

  InitWindow(screenWidth, screenHeight, "Mystery of Asaad");

  SetTargetFPS(60);

  while(!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(RED);
    DrawText("Hello",0,0,25, RAYWHITE);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
