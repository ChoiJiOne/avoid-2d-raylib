#include <raylib.h>
#include <glm/glm.hpp>

#include "ActorManager.h"
#include "Enemy.h"
#include "MainPhase.h"
#include "Player.h"

void MainPhase::OnUpdate(float deltaSeconds)
{
    for (auto& actor : _actors)
    {
        actor->OnPreUpdate(deltaSeconds);
    }

    for (auto& actor : _actors)
    {
        actor->OnUpdate(deltaSeconds);
    }

    for (auto& actor : _actors)
    {
        actor->OnPostUpdate(deltaSeconds);
    }
}

void MainPhase::OnRender()
{
    BeginDrawing();
    {
        ClearBackground(RAYWHITE);
        for (const auto& actor : _actors)
        {
            actor->OnRender();
        }
    }
    EndDrawing();
}

void MainPhase::OnEnter()
{
    ActorManager& actorManager = ActorManager::Get();
    _actors =
    {
        actorManager.Create<Player>(),
        actorManager.Create<Enemy>(glm::vec2(  0.0f,   0.0f), glm::vec2(+1.0f, +1.0f)),
        actorManager.Create<Enemy>(glm::vec2(800.0f,   0.0f), glm::vec2(-1.0f, +1.0f)),
        actorManager.Create<Enemy>(glm::vec2(800.0f, 600.0f), glm::vec2(-1.0f, -1.0f)),
        actorManager.Create<Enemy>(glm::vec2(  0.0f, 600.0f), glm::vec2(+1.0f, -1.0f))
    };
}

void MainPhase::OnExit()
{
}

bool MainPhase::ShouldTransition()
{
	return false;
}

IPhase* MainPhase::GetTransitionPhase()
{
	return nullptr;
}
