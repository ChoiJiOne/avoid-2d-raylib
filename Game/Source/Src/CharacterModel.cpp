#include "CharacterModel.h"

void CharacterModel::Move(float deltaSeconds)
{
	_center += deltaSeconds * _speed * _direction;
}

void CharacterModel::ApplyMovement(const glm::vec2& direction, float deltaSeconds)
{
	_direction = direction;
	Move(deltaSeconds);
}