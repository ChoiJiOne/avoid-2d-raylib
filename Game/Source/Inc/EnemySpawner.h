#pragma once

#include "Actor.h"

class EnemySpawner : public Actor
{
public:
	EnemySpawner() = default;
	virtual ~EnemySpawner();

	DISALLOW_COPY_AND_ASSIGN(EnemySpawner);

	virtual void OnCreate() override;
	virtual void OnDestroy() override;
};