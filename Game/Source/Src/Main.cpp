#include <vector>

#include <raylib.h>
#include <glm/glm.hpp>

#include "ActorManager.h"
#include "Enemy.h"
#include "Player.h"
#include "PhaseManager.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Avoid");
    SetTargetFPS(60);

    ActorManager::Get().Startup();
    PhaseManager::Get().Startup();

    std::vector<Actor*> actors =
    {
        ActorManager::Get().Create<Player>(),
        ActorManager::Get().Create<Enemy>(glm::vec2(  0.0f,   0.0f), glm::vec2(+1.0f, +1.0f)),
        ActorManager::Get().Create<Enemy>(glm::vec2(800.0f,   0.0f), glm::vec2(-1.0f, +1.0f)),
        ActorManager::Get().Create<Enemy>(glm::vec2(800.0f, 600.0f), glm::vec2(-1.0f, -1.0f)),
        ActorManager::Get().Create<Enemy>(glm::vec2(  0.0f, 600.0f), glm::vec2(+1.0f, -1.0f))
    };

    while (!WindowShouldClose())
    {
        float deltaSeconds = GetFrameTime();

        for (auto& actor : actors)
        {
            actor->OnUpdate(deltaSeconds);
        }
        
        BeginDrawing();
        {
            ClearBackground(RAYWHITE);
            for (const auto& actor : actors)
            {
                actor->OnRender();
            }
        }
        EndDrawing();
    }

    ActorManager::Get().Shutdown();
    PhaseManager::Get().Shutdown();

    CloseWindow();
    return 0;
}