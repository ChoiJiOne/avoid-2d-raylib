#pragma once

#include <raylib.h>

#include "IModel.h"

class PlayerModel : public IModel
{
public:
	PlayerModel() = default;
	PlayerModel(const Vector2& center, const Color& color, const float& radius)
		: _center(center), _color(color), _radius(radius) {}
	PlayerModel(PlayerModel&& instance) noexcept
		: _center(instance._center), _color(instance._color), _radius(instance._radius) {}
	PlayerModel(const PlayerModel& instance) noexcept
		: _center(instance._center), _color(instance._color), _radius(instance._radius) {}

	virtual ~PlayerModel() = default;

	PlayerModel& operator=(PlayerModel&& instance) noexcept
	{
		if (this == &instance)
		{
			return *this;
		}

		_center = instance._center;
		_color = instance._color;
		_radius = instance._radius;
		
		return *this;
	}

	PlayerModel& operator=(const PlayerModel& instance) noexcept
	{
		if (this == &instance)
		{
			return *this;
		}

		_center = instance._center;
		_color = instance._color;
		_radius = instance._radius;

		return *this;
	}

	const Vector2& GetCenter() const { return _center; }
	const Color& GetColor() const { return _color; }
	const float& GetRadius() const { return _radius; }

	void SetCenter(const Vector2& center) { _center = center; }
	void SetColor(const Color& color) { _color = color; }
	void SetRadius(const float& radius) { _radius = radius; }

private:
	Vector2 _center = Vector2{0.0f, 0.0f};
	Color _color = Color{ 0, 0, 0, 255 };
	float _radius = 100.0f;
};