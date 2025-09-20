#pragma once

class IModel;

class IController
{
public:
	virtual ~IController() = default;
	virtual void Update(IModel& model, float deltaSeconds) = 0;
};