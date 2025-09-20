#pragma once

#include "Actor.h"
#include "GameMacro.h"

class Player : public Actor
{
public:
	Player() = default;
	virtual ~Player();

	DISALLOW_COPY_AND_ASSIGN(Player);

	virtual void OnCreate() override;
	virtual void OnDestroy() override;
};