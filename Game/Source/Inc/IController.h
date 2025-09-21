#pragma once

class IModel;

class IController
{
public:
	virtual ~IController() = default;

	virtual void PreUpdate(IModel& model, float deltaSeconds) = 0;
	virtual void Update(IModel& model, float deltaSeconds) = 0;
	virtual void PostUpdate(IModel& model, float deltaSeconds) = 0;
};