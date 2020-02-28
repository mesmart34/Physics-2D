#include "game.h"
#include "physics.h"


std::vector<polygon*> polygons = std::vector<polygon*>();
polygon *p1;
polygon *p2;

void game::on_start()
{
	vec2 a = vec2(100, 100);
	vec2 b = vec2(300, 300);
	vec2 c = vec2(100, 300);
	vec2* vecs = new vec2[3];
	vecs[0] = a;
	vecs[1] = b;
	vecs[2] = c;
	p1 = new polygon(vecs, 3);
	p2 = new polygon(vecs, 3);
	p2->position.x += 400.0f;
	p2->position.y += 100.0f;
	polygons.push_back(p1);
	polygons.push_back(p2);
}

void game::on_update(const float delta_time, input_handler& input)
{
	const auto mouse_pos = vec2(input.get_mouse_x(), input.get_mouse_y());
	p2->position = mouse_pos;
	
	for (int i = 0; i < polygons.size(); i++) 
	{
		for (int j = 0; j < polygons.size(); j++)
		{
			if(i != j)
				std::cout << physics::intersects(*polygons.at(i), *polygons.at(j)) << std::endl;
		}
	}
}

void game::on_render(renderer& renderer)
{
	for (int i = 0; i < polygons.size(); i++)
	{
		renderer.set_draw_color(SDL_Color{10, 100, 200});
		polygon p = *polygons.at(i);
		for (int j = 0; j < p.get_vertices_number() - 1; j++)
			renderer.draw_line(p.get_vertex(j) + p.position, p.get_vertex(j + 1) + p.position);
		renderer.draw_line(p.get_vertex(p.get_vertices_number() - 1) + p.position, p.get_vertex(0) + p.position);
	}
}
