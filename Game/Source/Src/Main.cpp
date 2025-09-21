#include <vector>

#include <raylib.h>
#include <glm/glm.hpp>

#include "ActorManager.h"
#include "MainPhase.h"
#include "PhaseManager.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Avoid");
    SetTargetFPS(60);

    ActorManager::Get().Startup();
    PhaseManager::Get().Startup();

    MainPhase* mainPhase = PhaseManager::Get().Create<MainPhase>();

    IPhase* currentPhase = mainPhase;
    currentPhase->OnEnter();
    while (!WindowShouldClose())
    {
        float deltaSeconds = GetFrameTime();

        currentPhase->OnUpdate(deltaSeconds);
        currentPhase->OnRender();

        if (currentPhase->ShouldTransition())
        {
            currentPhase->OnExit();
            currentPhase = currentPhase->GetTransitionPhase();
            currentPhase->OnEnter();
        }
    }
    currentPhase->OnExit();

    ActorManager::Get().Shutdown();
    PhaseManager::Get().Shutdown();

    CloseWindow();
    return 0;
}