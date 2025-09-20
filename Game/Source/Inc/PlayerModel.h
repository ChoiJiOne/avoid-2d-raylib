#pragma once

#include <raylib.h>

#include "IModel.h"

class PlayerModel : public IModel
{
public:
	PlayerModel() = default;
	PlayerModel(const glm::vec2& center, const glm::vec4& color, const float& radius, const float& speed)
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

	const glm::vec2& GetCenter() const { return _center; }
	const glm::vec4& GetColor() const { return _color; }
	const float& GetRadius() const { return _radius; }
	const float& GetSpeed() const { return _speed; }

	void SetCenter(const glm::vec2& center) { _center = center; }
	void SetColor(const glm::vec4& color) { _color = color; }
	void SetRadius(const float& radius) { _radius = radius; }
	void SetSpeed(const float& speed) { _speed = speed; }

private:
	glm::vec2 _center = glm::vec2{0.0f, 0.0f};
	glm::vec4 _color = glm::vec4{ 1.0f, 0.5f, 0.1f, 1.0f };
	float _radius = 20.0f;
	float _speed = 300.0f;
};