#include "Enemy.h"
#include "EnemySpawner.h"
#include "EnemySpawnerController.h"
#include "EnemySpawnerModel.h"

EnemySpawner::~EnemySpawner()
{
}

void EnemySpawner::OnCreate()
{
	std::unique_ptr<EnemySpawnerModel> model = std::make_unique<EnemySpawnerModel>();
	ApplyModel(std::move(model));

	std::unique_ptr<EnemySpawnerController> controller = std::make_unique<EnemySpawnerController>();
	ApplyController(std::move(controller));
}

void EnemySpawner::OnDestroy()
{
}
