#include <raylib.h>

#include "Player.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Avoid");
    SetTargetFPS(60);
    
    std::unique_ptr<Player> player = std::make_unique<Player>();
    player->OnCreate();

    while (!WindowShouldClose())
    {
        float deltaSeconds = GetFrameTime();

        player->OnUpdate(deltaSeconds);

        BeginDrawing();
        {
            ClearBackground(RAYWHITE);
            player->OnRender();
        }
        EndDrawing();
    }

    player->OnDestroy();
    player.reset();

    CloseWindow();
    return 0;
}