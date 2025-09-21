#include "ActorManager.h"
#include "GameAssert.h"
#include "GameLogging.h"

void ActorManager::Startup()
{
	if (_isInitialized)
	{
		GAME_LOG_ERR("ALREADY_INITIALIZE_ACTOR_MANAGER");
		return;
	}

	_isInitialized = true;
}

void ActorManager::Shutdown()
{
	if (!_isInitialized)
	{
		GAME_LOG_ERR("NOT_INITIALIZE_ACTOR_MANAGER");
		return;
	}

	for (size_t idx = 0; idx < _actorPool.size(); ++idx)
	{
		if (_actorPool[idx].actor)
		{
			_actorPool[idx].actor->OnDestroy();
			_actorPool[idx].actor.reset();
			_actorPool[idx].isOccupied = false;
		}
	}

	_isInitialized = false;
}

void ActorManager::Destroy(const Actor* actor)
{
	int32_t actorID = -1;
	for (size_t idx = 0; idx < _actorPool.size(); ++idx)
	{
		if (actor == _actorPool[idx].actor.get())
		{
			actorID = static_cast<int32_t>(idx);
			break;
		}
	}

	if (actorID != -1 && _actorPool[actorID].actor)
	{
		_actorPool[actorID].actor->OnDestroy();
		_actorPool[actorID].actor.reset();
		_actorPool[actorID].isOccupied = false;
	}
}