#pragma once

#include "IView.h"

// TODO: �÷��̾� View Ưȭ �ƴ� �� �� ���ʸ��� View�� ����ϵ��� ���� �ʿ�.
class CharacterView : public IView
{
public:
	virtual ~CharacterView() = default;
	virtual void Render(const IModel& model) override;
};