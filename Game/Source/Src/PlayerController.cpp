#include "PlayerController.h"
#include "PlayerModel.h"

void PlayerController::Update(IModel& model, float deltaSeconds)
{
	PlayerModel& playerModel = static_cast<PlayerModel&>(model);
    Vector2 center = playerModel.GetCenter();
    
    if (IsKeyDown(KEY_RIGHT))
    {
        center.x += deltaSeconds * playerModel.GetSpeed();
    }

    if (IsKeyDown(KEY_LEFT))
    {
        center.x -= deltaSeconds * playerModel.GetSpeed();
    }

    if (IsKeyDown(KEY_UP))
    {
        center.y -= deltaSeconds * playerModel.GetSpeed();
    }

    if (IsKeyDown(KEY_DOWN))
    {
        center.y += deltaSeconds * playerModel.GetSpeed();
    }

    playerModel.SetCenter(center);
}
