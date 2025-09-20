#include <raylib.h>

#include "PlayerModel.h"
#include "PlayerView.h"

void PlayerView::Render(const IModel& model)
{
	const PlayerModel& playerModel = static_cast<const PlayerModel&>(model);
	const Vector2& center = playerModel.GetCenter();
	const Color& color = playerModel.GetColor();
	const float& radius = playerModel.GetRadius();
	
	DrawCircle(center.x, center.y, radius, color);
}