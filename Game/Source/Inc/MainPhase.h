#pragma once

#include <vector>

#include "Actor.h"
#include "IPhase.h"

class MainPhase : public IPhase
{
public:
	MainPhase() = default;
	virtual ~MainPhase() = default;

	DISALLOW_COPY_AND_ASSIGN(MainPhase);

	virtual void OnUpdate(float deltaSeconds) override;
	virtual void OnRender() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;

	virtual bool ShouldTransition() override;
	virtual IPhase* GetTransitionPhase() override;

private:
	std::vector<Actor*> _actors;
};