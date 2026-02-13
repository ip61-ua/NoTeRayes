#include <raylib.h>

#define MAX_GESTURE_STRINGS 20

int
main (void)
{
  const int screenHeight = 450, screenWidth = 800;
  InitWindow (screenWidth, screenHeight, "Hola desde raylib");

  SetTargetFPS (60);
  Rectangle testArea = { 220, 10, screenWidth - 10 - 220, screenHeight - 20 },
            detectedArea = { 10, 30, 220 - 20, screenHeight - 50 };

  Vector2 pointerPosition;

  while (!WindowShouldClose ())
    {
      if (IsMouseButtonDown (MOUSE_LEFT_BUTTON))
        {
          DrawCircleV (GetMousePosition (), 20, MAROON);
        }

      BeginDrawing ();
      ClearBackground (RAYWHITE);
      DrawRectangleLinesEx (testArea, 5.0f, GRAY);
      DrawRectangleLinesEx (detectedArea, 1.0f, GRAY);
      DrawText ("GESTURES TEST AREA", screenWidth - 270, screenHeight - 40, 20,
                Fade (GRAY, 0.5f));
      DrawText ("DETECTED GESTURES", 50, 15, 10, GRAY);

      EndDrawing ();
    }

  CloseWindow ();
  return 0;
}
