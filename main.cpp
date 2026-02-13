#include <raylib.h>

int
main (void)
{
  const int screenHeight = 600, screenWidth = 800;
  InitWindow (screenWidth, screenHeight, "Hola desde raylib");

  SetTargetFPS (60);

  float squareSide = 70.0f;
  Vector2 squarePositionCenter
      = { (float)screenWidth / 2 - (float)squareSide / 2,
          (float)screenHeight / 2 - (float)squareSide / 2 };
  float factorSpeed = 5.0f;

  while (!WindowShouldClose ())
    {
      squarePositionCenter.y += GetMouseWheelMove () * factorSpeed;

      BeginDrawing ();
      ClearBackground (RAYWHITE);
      DrawRectangleV (squarePositionCenter, { squareSide, squareSide },
                      MAROON);
      DrawText ("Use mouse wheel to move the cube up and down!", 5, 5, 20,
                GRAY);
      DrawText (
          TextFormat ("Box position Y: %03d", (int)squarePositionCenter.y), 5,
          30, 20, LIGHTGRAY);
      EndDrawing ();
    }

  CloseWindow ();
  return 0;
}
