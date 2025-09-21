#include "CharacterModel.h"
#include "PlayerController.h"

PlayerController::PlayerController()
{
    _directionMap =
    {
        { EDirection::RIGHT, glm::vec2{+1.0f, +0.0f} },
        { EDirection::LEFT,  glm::vec2{-1.0f, +0.0f} },
        { EDirection::DOWN,  glm::vec2{+0.0f, +1.0f} },
        { EDirection::UP,    glm::vec2{+0.0f, -1.0f} }
    };
}

void PlayerController::Update(IModel& model, float deltaSeconds)
{
	CharacterModel& character = static_cast<CharacterModel&>(model);

    glm::vec2 moveDirection = glm::vec2{ 0.0f, 0.0f };
    for (const auto& direction : _directionMap)
    {
        if (IsKeyDown(static_cast<int32_t>(direction.first)))
        {
            moveDirection += direction.second;
        }
    }
    character.ApplyMovement(moveDirection);
}
