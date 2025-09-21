#pragma once

#include "Actor.h"
#include "GameMacro.h"

class Enemy : public Actor
{
public:
	Enemy(const glm::vec2& startPosition, const glm::vec2& startDirection)
		: _startPosition(startPosition)
		, _startDirection(startDirection) {}
	virtual ~Enemy();

	DISALLOW_COPY_AND_ASSIGN(Enemy);

	virtual void OnCreate() override;
	virtual void OnDestroy() override;

private:
	glm::vec2 _startPosition;
	glm::vec2 _startDirection;
};