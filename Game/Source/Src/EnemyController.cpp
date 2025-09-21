#include "CharacterModel.h"
#include "EnemyController.h"

void EnemyController::PreUpdate(IModel& model, float deltaSeconds)
{
}

void EnemyController::Update(IModel& model, float deltaSeconds)
{
	CharacterModel& character = static_cast<CharacterModel&>(model);
	character.Move(deltaSeconds);
}

void EnemyController::PostUpdate(IModel& model, float deltaSeconds)
{
}
