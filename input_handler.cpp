#include "input_handler.h"

void input_handler::update_mouse(const SDL_Event event, const SDL_EventType event_type, const float render_scaling)
{
	switch (event_type)
	{
		case SDL_MOUSEBUTTONDOWN:
		{
			if(event.button.button == SDL_BUTTON_LEFT)
			{
				previous_mouse_state_[0] = mouse_state_[0];
				mouse_state_[0] = true;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				previous_mouse_state_[1] = mouse_state_[1];
				mouse_state_[1] = true;
			}
		} break;
		case SDL_MOUSEBUTTONUP:
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				previous_mouse_state_[0] = mouse_state_[0];
				mouse_state_[0] = false;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				previous_mouse_state_[1] = mouse_state_[1];
				mouse_state_[1] = false;
			}
		} break;
		case SDL_MOUSEMOTION:
		{
			mouse_x_ = event.motion.x * render_scaling;
			mouse_y_ = event.motion.y * render_scaling;
		} break;
		case SDL_MOUSEWHEEL:
		{
			wheel_ = event.wheel.y;
		} break;
	default: ;
	}
}

bool input_handler::is_mouse_button_down(const mouse_button button)
{
	return !previous_mouse_state_[static_cast<int>(button)] && mouse_state_[static_cast<int>(button)];
}

bool input_handler::is_mouse_button_up(const mouse_button button)
{
	return previous_mouse_state_[static_cast<int>(button)] && !mouse_state_[static_cast<int>(button)];
}

bool input_handler::is_mouse_button(const mouse_button button)
{
	return mouse_state_[static_cast<int>(button)];
}
/*
bool input_handler::is_key_down(SDL_Keycode key)
{
}

bool input_handler::is_key_up(SDL_Keycode key)
{
}

bool input_handler::is_key(SDL_Keycode key)
{
}*/

int input_handler::get_mouse_x() const
{
	return mouse_x_;
}

int input_handler::get_mouse_y() const
{
	return mouse_y_;
}

int input_handler::get_mouse_wheel() const
{
	return wheel_;
}

vec2 input_handler::get_mouse() const
{
	return vec2(get_mouse_x(), get_mouse_y());
}
