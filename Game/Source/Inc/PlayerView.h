#pragma once

#include "IView.h"

// TODO: �÷��̾� View Ưȭ �ƴ� �� �� ���ʸ��� View�� ����ϵ��� ���� �ʿ�.
class PlayerView : public IView
{
public:
	virtual ~PlayerView() = default;
	virtual void Render(const IModel& model) override;
};