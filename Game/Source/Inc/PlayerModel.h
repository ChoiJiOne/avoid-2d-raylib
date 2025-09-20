#pragma once

#include <raylib.h>

#include "IModel.h"

class PlayerModel : public IModel
{
public:
	PlayerModel() = default;
	PlayerModel(const Vector2& center, const Color& color, const float& radius, const float& speed)
		: _center(center), _color(color), _radius(radius), _speed(speed){}
	PlayerModel(PlayerModel&& instance) noexcept
		: _center(instance._center), _color(instance._color), _radius(instance._radius), _speed(instance._speed) {}
	PlayerModel(const PlayerModel& instance) noexcept
		: _center(instance._center), _color(instance._color), _radius(instance._radius), _speed(instance._speed) {}

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
		_speed = instance._speed;
		
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
		_speed = instance._speed;

		return *this;
	}

	const Vector2& GetCenter() const { return _center; }
	const Color& GetColor() const { return _color; }
	const float& GetRadius() const { return _radius; }
	const float& GetSpeed() const { return _speed; }

	void SetCenter(const Vector2& center) { _center = center; }
	void SetColor(const Color& color) { _color = color; }
	void SetRadius(const float& radius) { _radius = radius; }
	void SetSpeed(const float& speed) { _speed = speed; }

private:
	Vector2 _center = Vector2{0.0f, 0.0f};
	Color _color = Color{ 255, 150, 100, 255 };
	float _radius = 20.0f;
	float _speed = 300.0f;
};