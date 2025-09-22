#include "ActorManager.h"
#include "CharacterModel.h"
#include "CharacterView.h"
#include "Player.h"
#include "PlayerController.h"

Player::~Player()
{
}

void Player::OnCreate()
{
	std::unique_ptr<CharacterModel> model = std::make_unique<CharacterModel>(
		glm::vec2(400.0f, 300.0f),
		glm::vec2(0.0f, 0.0f),
		glm::vec4(1.0f, 0.5f, 0.2f, 1.0f),
		20.0f,
		400.0f
	);
	ApplyModel(std::move(model));

	std::unique_ptr<PlayerController> controller = std::make_unique<PlayerController>();
	ApplyController(std::move(controller));

	std::unique_ptr<CharacterView> view = std::make_unique<CharacterView>();
	ApplyView(std::move(view));
}

void Player::OnDestroy()
{
}