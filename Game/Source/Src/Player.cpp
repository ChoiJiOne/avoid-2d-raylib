#include "Player.h"
#include "PlayerController.h"
#include "PlayerModel.h"
#include "PlayerView.h"

Player::~Player()
{
}

void Player::OnCreate()
{
	std::unique_ptr<PlayerModel> model = std::make_unique<PlayerModel>();
	ApplyModel(std::move(model));

	std::unique_ptr<PlayerController> controller = std::make_unique<PlayerController>();
	ApplyController(std::move(controller));

	std::unique_ptr<PlayerView> view = std::make_unique<PlayerView>();
	ApplyView(std::move(view));
}

void Player::OnDestroy()
{
}