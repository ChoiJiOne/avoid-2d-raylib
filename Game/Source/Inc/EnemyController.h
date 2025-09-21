#pragma once

#include "IController.h"

class EnemyController : public IController
{
public:
	EnemyController() = default;
	virtual ~EnemyController() = default;
	
	virtual void PreUpdate(IModel& model, float deltaSeconds) override;
	virtual void Update(IModel& model, float deltaSeconds) override;
	virtual void PostUpdate(IModel& model, float deltaSeconds) override;
};