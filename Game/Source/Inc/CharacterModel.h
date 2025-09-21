#pragma once

#include <raylib.h>
#include <glm/glm.hpp>

#include "IModel.h"

class CharacterModel : public IModel
{
public:
	CharacterModel() = default;
	CharacterModel(const glm::vec2& center, const glm::vec2& direction, const glm::vec4& color, const float& radius, const float& speed)
		: _center(center)
		, _direction(direction)
		, _color(color)
		, _radius(radius)
		, _speed(speed) {}
	CharacterModel(CharacterModel&& instance) noexcept
		: _center(instance._center)
		, _direction(instance._direction)
		, _color(instance._color)
		, _radius(instance._radius)
		, _speed(instance._speed) {}
	CharacterModel(const CharacterModel& instance) noexcept
		: _center(instance._center)
		, _direction(instance._direction)
		, _color(instance._color)
		, _radius(instance._radius)
		, _speed(instance._speed) {}

	virtual ~CharacterModel() = default;

	CharacterModel& operator=(CharacterModel&& instance) noexcept
	{
		if (this == &instance)
		{
			return *this;
		}

		_center = instance._center;
		_direction = instance._direction;
		_color = instance._color;
		_radius = instance._radius;
		_speed = instance._speed;
		
		return *this;
	}

	CharacterModel& operator=(const CharacterModel& instance) noexcept
	{
		if (this == &instance)
		{
			return *this;
		}

		_center = instance._center;
		_direction = instance._direction;
		_color = instance._color;
		_radius = instance._radius;
		_speed = instance._speed;

		return *this;
	}

	const glm::vec2& GetCenter() const { return _center; }
	const glm::vec2& GetDirection() const { return _direction; }
	const glm::vec4& GetColor() const { return _color; }
	const float& GetRadius() const { return _radius; }
	const float& GetSpeed() const { return _speed; }

	void SetCenter(const glm::vec2& center) { _center = center; }
	void SetDirection(const glm::vec2& direction) { _direction = direction; }
	void SetColor(const glm::vec4& color) { _color = color; }
	void SetRadius(const float& radius) { _radius = radius; }
	void SetSpeed(const float& speed) { _speed = speed; }

	void Move(float deltaSeconds);
	void ApplyMovement(const glm::vec2& direction, float deltaSeconds);

private:
	glm::vec2 _center = glm::vec2{0.0f, 0.0f};
	glm::vec2 _direction = glm::vec2{ 0.0f, 0.0f };
	glm::vec4 _color = glm::vec4{ 1.0f, 0.5f, 0.1f, 1.0f };
	float _radius = 20.0f;
	float _speed = 300.0f;
};