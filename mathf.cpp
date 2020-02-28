#include "mathf.h"

float mathf::point_direction(const vec2 a, const vec2 b)
{
	return atan2f(b.y - a.y, b.x - a.x);
}

float mathf::point_distance(vec2 a, vec2 b)
{
	return sqrtf((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
