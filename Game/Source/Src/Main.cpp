#include <raylib.h>
#include <glm/glm.hpp>

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

    // TODO: 테스트용... 수정 필요.
    std::unique_ptr<Enemy> enemy0 = std::make_unique<Enemy>(glm::vec2(0.0f, 0.0f), glm::vec2(1.0f, 1.0f));
    enemy0->OnCreate();

    std::unique_ptr<Enemy> enemy1 = std::make_unique<Enemy>(glm::vec2(800.0f, 0.0f), glm::vec2(-1.0f, 1.0f));
    enemy1->OnCreate();

    std::unique_ptr<Enemy> enemy2 = std::make_unique<Enemy>(glm::vec2(800.0f, 600.0f), glm::vec2(-1.0f, -1.0f));
    enemy2->OnCreate();

    std::unique_ptr<Enemy> enemy3 = std::make_unique<Enemy>(glm::vec2(0.0f, 600.0f), glm::vec2(1.0f, -1.0f));
    enemy3->OnCreate();

    while (!WindowShouldClose())
    {
        float deltaSeconds = GetFrameTime();

        player->OnUpdate(deltaSeconds);
        enemy0->OnUpdate(deltaSeconds);
        enemy1->OnUpdate(deltaSeconds);
        enemy2->OnUpdate(deltaSeconds);
        enemy3->OnUpdate(deltaSeconds);

        BeginDrawing();
        {
            ClearBackground(RAYWHITE);
            player->OnRender();
            enemy0->OnRender();
            enemy1->OnRender();
            enemy2->OnRender();
            enemy3->OnRender();
        }
        EndDrawing();
    }

    enemy3->OnDestroy();
    enemy3.reset();

    enemy2->OnDestroy();
    enemy2.reset();   
    
    enemy1->OnDestroy();
    enemy1.reset();

    enemy0->OnDestroy();
    enemy0.reset();

    player->OnDestroy();
    player.reset();

    CloseWindow();
    return 0;
}