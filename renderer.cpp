#include "renderer.h"

renderer::renderer(display& display, const int width, const int height): draw_color_(SDL_Color{0, 0, 0, 0}), width_(width), height_(height)
{
	const uint32_t flags = SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_ACCELERATED;
	renderer_ = SDL_CreateRenderer(display.get_sdl_window(), 0, flags);
	SDL_RenderSetLogicalSize(renderer_, display.get_width(), display.get_height());
	target_texture_ = SDL_CreateTexture(renderer_, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
}

void renderer::set_draw_color(const SDL_Color color)
{
	draw_color_ = color;
	SDL_SetRenderDrawColor(renderer_, draw_color_.r, draw_color_.g, draw_color_.b, draw_color_.a);
}

void renderer::clear() const
{
	SDL_RenderClear(renderer_);
}

void renderer::present() const
{
	SDL_RenderPresent(renderer_);
}

void renderer::begin() const
{
	SDL_SetRenderTarget(renderer_, target_texture_);
}

void renderer::end() const
{
	SDL_SetRenderTarget(renderer_, nullptr);
	SDL_RenderCopyEx(renderer_, target_texture_, nullptr, nullptr, 0, nullptr, SDL_FLIP_NONE);
}

int renderer::get_width() const
{
	return width_;
}

int renderer::get_height() const
{
	return height_;
}

void renderer::draw_line(const int x1, const int y1, const int x2, const int y2) const
{
	SDL_RenderDrawLine(renderer_, x1, y1, x2, y2);
}

void renderer::draw_line(const vec2 start, const vec2 end) const
{
	SDL_RenderDrawLine(renderer_, start.x, start.y, end.x, end.y);
}

/*void renderer::draw_rectangles(std::vector<rectangle*>& rectangles) const
{
	for (auto r : rectangles)
	{
		const auto position = r->get_position();
		const auto size = r->get_size();
		SDL_Rect rect = {
			static_cast<int>(position.x),
			static_cast<int>(position.y),
			static_cast<int>(size.x),
			static_cast<int>(size.y)
		};
		SDL_SetRenderDrawColor(renderer_, r->get_color().r, r->get_color().g, r->get_color().b, r->get_color().a);
		SDL_RenderFillRect(renderer_, &rect);
	}
}*/

vec2 renderer::get_renderer_scale(SDL_Renderer* renderer)
{
	int width;
	int height;
	SDL_RenderGetLogicalSize(renderer, &width, &height);
	return vec2(width, height);
}