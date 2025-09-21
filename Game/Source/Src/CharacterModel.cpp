#include "CharacterModel.h"

void CharacterModel::ApplyMovement(const glm::vec2& direction, float deltaSeconds)
{
	_direction = direction;
	_center += deltaSeconds * _speed * direction;
}