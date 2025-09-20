#include "Actor.h"
#include "IController.h"
#include "IModel.h"
#include "IView.h"
#include "GameAssert.h"

Actor::~Actor()
{
	if (_controller)
	{
		_controller.reset();
	}

	if (_view)
	{
		_view.reset();
	}

	if (_model)
	{
		_model.reset();
	}
}

void Actor::OnUpdate(float deltaSeconds)
{
	if (IsValidController())
	{
		_controller->Update(*_model, deltaSeconds);
	}
}

void Actor::OnRender() const
{
	if (IsValidView())
	{
		_view->Render(*_model);
	}
}

void Actor::ApplyModel(std::unique_ptr<IModel>&& model)
{
	_model = std::move(model);
}

void Actor::ApplyView(std::unique_ptr<IView>&& view)
{
	_view = std::move(view);
}

void Actor::ApplyController(std::unique_ptr<IController>&& controller)
{
	_controller = std::move(controller);
}

bool Actor::IsValidController() const
{
	return _model != nullptr && _controller != nullptr;
}

bool Actor::IsValidView() const
{
	return _model != nullptr && _view != nullptr;
}