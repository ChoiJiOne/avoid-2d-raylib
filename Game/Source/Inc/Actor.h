#pragma once

#include <memory>

#include "GameMacro.h"

class IModel;
class IView;
class IController;

class Actor
{
public:
	Actor() = default;
	virtual ~Actor();

	DISALLOW_COPY_AND_ASSIGN(Actor);
	
	virtual void OnCreate() = 0;
	virtual void OnDestroy() = 0;

	virtual void OnUpdate(float deltaSeconds);
	virtual void OnRender() const;

protected:
	void ApplyModel(std::unique_ptr<IModel>&& model);
	void ApplyView(std::unique_ptr<IView>&& view);
	void ApplyController(std::unique_ptr<IController>&& controller);

private:
	bool IsValidController() const;
	bool IsValidView() const;

private:
	std::unique_ptr<IModel> _model;
	std::unique_ptr<IView> _view;
	std::unique_ptr<IController> _controller;
};