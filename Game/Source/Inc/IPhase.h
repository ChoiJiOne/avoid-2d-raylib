#pragma once

#include "GameMacro.h"

class IPhase
{
public:
	IPhase() = default;
	virtual ~IPhase() = default;

	DISALLOW_COPY_AND_ASSIGN(IPhase);

	virtual void OnUpdate(float deltaSeconds) = 0;
	virtual void OnRender() = 0;
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;

	virtual bool ShouldTransition() = 0;
	virtual IPhase* GetTransitionPhase() = 0;
};