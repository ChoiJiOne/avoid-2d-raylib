#pragma once

#include "IController.h"
#include "PlayerModel.h"

class PlayerController : public IController
{
public:
	virtual ~PlayerController() = default;
	virtual void Update(IModel& model, float deltaSeconds) override;
};