#include "CharacterModel.h"
#include "CharacterView.h"
#include "Enemy.h"
#include "EnemyController.h"

Enemy::~Enemy()
{
}

void Enemy::OnCreate()
{
	std::unique_ptr<CharacterModel> model = std::make_unique<CharacterModel>();
	ApplyModel(std::move(model));

	std::unique_ptr<EnemyController> controller = std::make_unique<EnemyController>();
	ApplyController(std::move(controller));

	std::unique_ptr<CharacterView> view = std::make_unique<CharacterView>();
	ApplyView(std::move(view));
}

void Enemy::OnDestroy()
{
}
