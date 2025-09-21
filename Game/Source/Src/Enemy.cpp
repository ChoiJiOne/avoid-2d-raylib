#include "CharacterModel.h"
#include "CharacterView.h"
#include "Enemy.h"
#include "EnemyController.h"

Enemy::~Enemy()
{
}

void Enemy::OnCreate()
{
	std::unique_ptr<CharacterModel> model = std::make_unique<CharacterModel>(
		glm::vec2(0.0f, 0.0f),
		glm::vec2(1.0f, 1.0f),
		glm::vec4(1.0f, 0.5f, 0.5f, 1.0f),
		20.0f,
		100.0f
	);
	ApplyModel(std::move(model));

	std::unique_ptr<EnemyController> controller = std::make_unique<EnemyController>();
	ApplyController(std::move(controller));

	std::unique_ptr<CharacterView> view = std::make_unique<CharacterView>();
	ApplyView(std::move(view));
}

void Enemy::OnDestroy()
{
}
