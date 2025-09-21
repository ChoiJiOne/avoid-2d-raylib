#include <raylib.h>

#include "Enemy.h"
#include "Player.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Avoid");
    SetTargetFPS(60);
    
    std::unique_ptr<Player> player = std::make_unique<Player>();
    player->OnCreate();

    std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>();
    enemy->OnCreate();

    while (!WindowShouldClose())
    {
        float deltaSeconds = GetFrameTime();

        player->OnUpdate(deltaSeconds);
        enemy->OnUpdate(deltaSeconds);

        BeginDrawing();
        {
            ClearBackground(RAYWHITE);
            player->OnRender();
            enemy->OnRender();
        }
        EndDrawing();
    }

    enemy->OnDestroy();
    enemy.reset();

    player->OnDestroy();
    player.reset();

    CloseWindow();
    return 0;
}