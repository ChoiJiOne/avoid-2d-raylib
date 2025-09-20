#include <raylib.h>
#include <glm/glm.hpp>

#include "PlayerModel.h"
#include "PlayerView.h"

void PlayerView::Render(const IModel& model)
{
	const PlayerModel& playerModel = static_cast<const PlayerModel&>(model);
	const glm::vec2& center = playerModel.GetCenter();
	const glm::vec4& color = playerModel.GetColor();
	const float& radius = playerModel.GetRadius();
	Color c = ColorFromNormalized(Vector4{ color.x, color.y, color.z, color.w });
	DrawCircle(center.x, center.y, radius, c);
}