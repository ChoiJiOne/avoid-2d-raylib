#pragma once

class IModel;

class IView
{
public:
	virtual ~IView() = default;
	virtual void Render(const IModel& model) = 0;
};