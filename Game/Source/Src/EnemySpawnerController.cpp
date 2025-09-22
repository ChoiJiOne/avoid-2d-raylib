#include "EnemySpawnerController.h"
#include "EnemySpawnerModel.h"

void EnemySpawnerController::PreUpdate(IModel& model, float deltaSeconds)
{
}

void EnemySpawnerController::Update(IModel& model, float deltaSeconds)
{
	EnemySpawnerModel& enemySpawnerModel = static_cast<EnemySpawnerModel&>(model);
	enemySpawnerModel.TickSpawnTimer(deltaSeconds);
}

void EnemySpawnerController::PostUpdate(IModel& model, float deltaSeconds)
{
}
