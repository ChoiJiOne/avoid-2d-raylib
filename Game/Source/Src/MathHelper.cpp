#include "MathHelper.h"

Color MathHelper::ConvertVec4ToColor(const glm::vec4& color)
{
	Vector4 vecColor = Vector4{ color.x, color.y, color.z, color.w };
	return ColorFromNormalized(vecColor);
}