#include "display.h"

display::display(const std::string& title, const int width, const int height, const bool resizable): width_(width), height_(height)
{
	const uint32_t flags = resizable ? SDL_WINDOW_RESIZABLE : 0;
	window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
}

int display::get_width() const
{
	return width_;
}

int display::get_height() const
{
	return height_;
}

SDL_Window* display::get_sdl_window() const
{
	return window_;
}

