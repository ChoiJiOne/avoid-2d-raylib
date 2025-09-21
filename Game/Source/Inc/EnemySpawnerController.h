#pragma once

#include "IController.h"

class EnemySpawnerController : public IController
{
public:
	EnemySpawnerController() = default;
	virtual ~EnemySpawnerController() = default;

	virtual void PreUpdate(IModel& model, float deltaSeconds) override;
	virtual void Update(IModel& model, float deltaSeconds) override;
	virtual void PostUpdate(IModel& model, float deltaSeconds) override;
};