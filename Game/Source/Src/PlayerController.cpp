#include "PlayerController.h"
#include "PlayerModel.h"

PlayerController::PlayerController()
{
    _directionVectorMap =
    {
        { EDirection::RIGHT, glm::vec2{+1.0f, +0.0f} },
        { EDirection::LEFT,  glm::vec2{-1.0f, +0.0f} },
        { EDirection::DOWN,  glm::vec2{+0.0f, +1.0f} },
        { EDirection::UP,    glm::vec2{+0.0f, -1.0f} }
    };
}

void PlayerController::Update(IModel& model, float deltaSeconds)
{
	PlayerModel& playerModel = static_cast<PlayerModel&>(model);
    glm::vec2 center = playerModel.GetCenter();

    glm::vec2 moveVector = glm::vec2{ 0.0f, 0.0f };
    for (const auto& directionVector : _directionVectorMap)
    {
        if (IsKeyDown(static_cast<int32_t>(directionVector.first)))
        {
            moveVector += directionVector.second;
        }
    }

    center += deltaSeconds * playerModel.GetSpeed() * moveVector;
    playerModel.SetCenter(center);
}
