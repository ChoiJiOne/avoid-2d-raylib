#pragma once

#include <raylib.h>
#include <glm/glm.hpp>

class MathHelper
{
public:
	static Color ConvertVec4ToColor(const glm::vec4& color);
};