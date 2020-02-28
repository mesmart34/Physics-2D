#include "physics.h"
#include <algorithm>
#include <stdint.h>

bool physics::intersects(polygon a, polygon b)
{
	for (uint32_t i = 0; i < a.get_vertices_number(); i++)
	{
		vec2 n = vec2(-a.get_edge_dir(i).y, a.get_edge_dir(i).x);
		if (axis_separate_polygons(n, a, b))
			return false;
	}
	for (uint32_t i = 0; i < b.get_vertices_number(); i++)
	{
		vec2 n = vec2(-b.get_edge_dir(i).y, b.get_edge_dir(i).x);
		if (axis_separate_polygons(n, a, b))
			return false;
	}
	return true;
}

bool physics::axis_separate_polygons(vec2& axis, polygon a, polygon b)
{
	float mina, maxa;
	float minb, maxb;
	calculate_intervals(axis, a, mina, maxa);
	calculate_intervals(axis, b, minb, maxb);
	if (mina > maxb || minb > maxa)
		return true;
	float d0 = maxa - minb;
	float d1 = maxb - mina;
	float depth = (d0 < d1) ? d0 : d1;
	float axis_lenght_squared = vec2::dot_product(axis, axis);
	axis *= depth / axis_lenght_squared;
	return false;
}

void physics::calculate_intervals(vec2 axis, polygon p, float& min, float& max)
{
	float d = vec2::dot_product(axis, p.get_vertex(0));
	min = max = d;
	for (int i = 0; i < p.get_vertices_number(); i++)
	{
		d = vec2::dot_product(p.get_vertex(i), axis);
		if (d < min)
		{
			min = d;
		}
		else if (d > max)
		{
			max = d;
		}
	}
}
