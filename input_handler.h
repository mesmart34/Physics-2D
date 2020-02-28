#pragma once
#include "SDL.h"
#include "vec2.h"

enum mouse_button
{
	left = 0,
	right = 1
};

class input_handler
{
public:
	input_handler() = default;
	void update_mouse(SDL_Event event, SDL_EventType event_type, float render_scaling);
	bool is_mouse_button_down(mouse_button button);
	bool is_mouse_button_up(mouse_button button);
	bool is_mouse_button(mouse_button button);
	/*bool is_key_down(SDL_Keycode key);
	bool is_key_up(SDL_Keycode key);
	bool is_key(SDL_Keycode key);*/
	int get_mouse_x() const;
	int get_mouse_y() const;
	int get_mouse_wheel() const;
	vec2 get_mouse() const;
private:
	const uint8_t* keyboard_state_ = SDL_GetKeyboardState(nullptr);
	bool mouse_state_[2]{};
	bool previous_mouse_state_[2]{};
	int mouse_x_{};
	int mouse_y_{};
	int wheel_;
};
