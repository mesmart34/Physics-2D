#pragma once
#include <vector>
#include "SDL.h"
#include "display.h"
#include "vec2.h"
class renderer
{
public:
	renderer() = default;
	renderer(display& display, int width, int height);
	void set_draw_color(const SDL_Color color);
	void clear() const;
	void present() const;
	void begin() const;
	void end() const;
	int get_width() const;
	int get_height() const;
	void draw_line(const int x1, const int y1, const int x2, const int y2) const;
	void draw_line(const vec2 start, const vec2 end) const;
	//void draw_rectangles(std::vector<rectangle*>& rectangles) const;
	static vec2 get_renderer_scale(SDL_Renderer* renderer);
private:
	SDL_Renderer* renderer_;
	SDL_Color draw_color_;
	SDL_Texture* target_texture_;
	int width_;
	int height_;
};
