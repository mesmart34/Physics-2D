#pragma once
#include <stdint.h>
#include "vec2.h"

class polygon
{
public:
	polygon() = default;
	polygon(vec2 *vertices, uint32_t vec2_number);
	vec2 get_vertex(uint32_t index) const;
	vec2 get_edge_dir(uint32_t index) const;
	uint32_t get_vertices_number() const;
	vec2 position;
private:
	vec2 *vertices;
	vec2* edge_direction;
	uint32_t vertices_number;
};

