#pragma once

#include "IView.h"

// TODO: 플레이어 View 특화 아닌 좀 더 제너릭한 View를 사용하도록 수정 필요.
class PlayerView : public IView
{
public:
	virtual ~PlayerView() = default;
	virtual void Render(const IModel& model) override;
};