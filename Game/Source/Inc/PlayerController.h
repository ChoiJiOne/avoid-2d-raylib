#pragma once

#include <map>

#include <glm/glm.hpp>

#include "IController.h"

class PlayerController : public IController
{
public:
	enum class EDirection
	{
		RIGHT = 262,
		LEFT = 263,
		DOWN = 264,
		UP = 265,
	};

public:
	PlayerController();
	virtual ~PlayerController() = default;

	virtual void PreUpdate(IModel& model, float deltaSeconds) override;
	virtual void Update(IModel& model, float deltaSeconds) override;
	virtual void PostUpdate(IModel& model, float deltaSeconds) override;

private:
	std::map<EDirection, glm::vec2> _directionMap;
};