#pragma once

#include "Actor.h"
#include "GameMacro.h"

class Enemy : public Actor
{
public:
	Enemy() = default;
	virtual ~Enemy();

	DISALLOW_COPY_AND_ASSIGN(Enemy);

	virtual void OnCreate() override;
	virtual void OnDestroy() override;
};