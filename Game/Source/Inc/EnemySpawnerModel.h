#pragma once

#include <glm/glm.hpp>

#include "IModel.h"

class EnemySpawnerModel : public IModel
{
public:
	EnemySpawnerModel() = default;
	EnemySpawnerModel(const glm::vec2& position, float spawnTime)
		: _position(position)
		, _spawnTime(spawnTime)
		, _stepTime(0.0f) {}
	EnemySpawnerModel(EnemySpawnerModel&& instance) noexcept
		: _position(instance._position)
		, _spawnTime(instance._spawnTime)
		, _stepTime(instance._stepTime) {}
	EnemySpawnerModel(const EnemySpawnerModel& instance)
		: _position(instance._position)
		, _spawnTime(instance._spawnTime)
		, _stepTime(instance._stepTime) {}

	virtual ~EnemySpawnerModel() = default;

	EnemySpawnerModel& operator=(EnemySpawnerModel&& instance) noexcept
	{
		if (this == &instance)
		{
			return *this;
		}

		_position = instance._position;
		_spawnTime = instance._spawnTime;
		_stepTime = instance._stepTime;

		return *this;
	}

	EnemySpawnerModel& operator=(const EnemySpawnerModel& instance)
	{
		if (this == &instance)
		{
			return *this;
		}

		_position = instance._position;
		_spawnTime = instance._spawnTime;
		_stepTime = instance._stepTime;

		return *this;
	}

	const glm::vec2& GetPosition() const { return _position; }
	const float& GetStepTime() const { return _stepTime; }
	const float& GetSpawnTime() const { return _spawnTime; }

	void TickSpawnTimer(float deltaSeconds);
	void ResetStepTime() { _stepTime = 0.0f; }

private:
	glm::vec2 _position;
	float _stepTime = 0.0f;
	float _spawnTime = 0.0f;
};