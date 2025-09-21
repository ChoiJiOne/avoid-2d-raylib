#pragma once

#include "IController.h"

class EnemyController : public IController
{
public:
	EnemyController() = default;
	virtual ~EnemyController() = default;
	
	virtual void Update(IModel& model, float deltaSeconds) override;
};