#include <raylib.h>

typedef enum
{
  LOGO = 0,
  TITLE,
  GAMEPLAY,
  ENDING
} GameScreen;

GameScreen currentScreen = LOGO;

int framesCounter = 0;

int
main (void)
{
  const int screenHeight = 800, screenWidth = 600;
  InitWindow (screenWidth, screenHeight, "Hola desde raylib");

  SetTargetFPS (60);

  Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };
  Color ballColor = DARKBLUE;

  while (!WindowShouldClose ())
    {
      // if (IsKeyDown (KEY_RIGHT))
      //   ballPosition.x += 3.0f;
      // if (IsKeyDown (KEY_LEFT))
      //   ballPosition.x -= 3.0f;
      // if (IsKeyDown (KEY_UP))
      //   ballPosition.y -= 3.0f;
      // if (IsKeyDown (KEY_DOWN))
      //   ballPosition.y += 3.0f;

      // if (IsGamepadAvailable (0))
      //   {
      //     if (IsGamepadButtonDown (0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT))
      //       ballPosition.x += 3.0f;
      //     if (IsGamepadButtonDown (0, GAMEPAD_BUTTON_LEFT_FACE_LEFT))
      //       ballPosition.x -= 3.0f;
      //     if (IsGamepadButtonDown (0, GAMEPAD_BUTTON_LEFT_FACE_UP))
      //       ballPosition.y -= 3.0f;
      //     if (IsGamepadButtonDown (0, GAMEPAD_BUTTON_LEFT_FACE_DOWN))
      //       ballPosition.y += 3.0f;
      //   }

      ballPosition = GetMousePosition ();

      if (IsMouseButtonDown (MOUSE_BUTTON_LEFT))
        ballColor = YELLOW;
      else if (IsMouseButtonDown (MOUSE_BUTTON_MIDDLE))
        ballColor = LIME;
      else if (IsMouseButtonDown (MOUSE_BUTTON_RIGHT))
        ballColor = RED;

      switch (currentScreen)
        {
        case LOGO:
          framesCounter++;
          if (framesCounter > 300)
            currentScreen = TITLE;

          break;

        case TITLE:
          if (IsKeyPressed (KEY_ENTER))
            currentScreen = GAMEPLAY;
          break;

        case GAMEPLAY:
          if (IsKeyPressed (KEY_ENTER))
            currentScreen = ENDING;
          break;
        }

      BeginDrawing ();
      ClearBackground (RAYWHITE);

      switch (currentScreen)
        {
        case LOGO:
          DrawText ("THE SCAM COMPANY", 10, 10, 12, RED);
          DrawText (TextFormat ("TIEMPO TRANSCURRIDO: %i", (int)GetTime ()),
                    10, 22, 12, RED);
          break;

        case TITLE:
          DrawRectangle (0, 0, screenWidth, screenWidth, PURPLE);
          DrawText ("WELCOME 2D JUNGLE", 10, 10, 10, GOLD);
          DrawText ("THE FURY CITY", 10, 20, 10, GOLD);
          DrawText ("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220,
                    20, GOLD);
          break;

        case GAMEPLAY:
          DrawRectangle (0, 0, screenWidth, screenWidth, DARKGRAY);
          DrawText ("LETS GET READY", 10, 10, 10, WHITE);
          DrawText ("READY PLAYER ONE...", 10, 20, 10, WHITE);
          DrawText ("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 120, 220,
                    20, WHITE);
          DrawCircleV (ballPosition, 50, ballColor);
          break;

        case ENDING:
          DrawRectangle (0, 0, screenWidth, screenHeight, YELLOW);
          DrawText ("GAME OVER", 10, 10, 10, PINK);
          DrawText ("PRESS ESC TO EXIT THE GAME", 10, 20, 10, PINK);
          break;

          DrawText ("Hola!!!", 190, 200, 20, LIGHTGRAY);
        }
      EndDrawing ();
    }

  CloseWindow ();
  return 0;
}
