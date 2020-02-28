#pragma once
#include <string>
#include "SDL.h"

class display
{
public:
	display() = default;
	display(const std::string& title, int width, int height, bool resizable);
	int get_width() const;
	int get_height() const;
	SDL_Window* get_sdl_window() const;
private:
	SDL_Window* window_;
	int width_;
	int height_;
};
