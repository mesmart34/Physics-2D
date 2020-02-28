#pragma once
#include "vec2.h"
#include "vector"
#include "polygon.h"

class physics
{
public:
	static bool intersects(polygon a, polygon b); 
private:
	static bool axis_separate_polygons(vec2& axis, polygon a, polygon b);
	static void calculate_intervals(vec2 axis, polygon p, float &min, float &max);
};

