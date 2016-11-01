#pragma once

#include "clamp.hpp"

namespace astrant {

float smootherstep(float x, float edge0, float edge1) {
	x = clamped(0.0f, (x - edge0) / (edge1 - edge0), 1.0f);
	return x * x * x * (x * (x * 6 - 15) + 10);
}

}
