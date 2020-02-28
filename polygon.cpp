#include "polygon.h"

polygon::polygon(vec2* vertices, uint32_t vec2_number)
{
	this->vertices = vertices;
	this->vertices_number = vec2_number;
	for (int i = 1; i < vertices_number; i++)
	{
		vec2 temp = vertices[i] - vertices[i - 1];
		vec2 norm = vec2::get_normalized(vec2(-temp.y, temp.x));
		edge_direction[i - 1] = norm;
	}

}

vec2 polygon::get_vertex(uint32_t index) const
{
	return vertices[index];
}

vec2 polygon::get_edge_dir(uint32_t index) const
{
	return vec2();
}

uint32_t polygon::get_vertices_number() const
{
	return vertices_number;
}
