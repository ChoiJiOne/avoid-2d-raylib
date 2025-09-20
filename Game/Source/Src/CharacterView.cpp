#include <raylib.h>

#include "MathHelper.h"
#include "CharacterModel.h"
#include "CharacterView.h"

void CharacterView::Render(const IModel& model)
{
	const CharacterModel& character = static_cast<const CharacterModel&>(model);
	const glm::vec2& center = character.GetCenter();
	const float& radius = character.GetRadius();
	Color color = MathHelper::ConvertVec4ToColor(character.GetColor());

	DrawCircle(center.x, center.y, radius, color);
}