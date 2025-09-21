#include "CharacterModel.h"
#include "EnemyController.h"

void EnemyController::Update(IModel& model, float deltaSeconds)
{
	CharacterModel& character = static_cast<CharacterModel&>(model);
	character.Move(deltaSeconds);
}