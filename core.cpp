#include "core.h"
#include <iostream>
#include "polygon.h"
#include "vec2.h"


core::core(const int width, const int height): running_(true)
{
	initialize(width, height);
}

void core::initialize(const int width, const int height)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	display_ = display("testing", width, height, true);
	render_scaling_ = 1.0f;
	renderer_ = renderer(display_, render_scaling_ * width, render_scaling_ * height);
	//physics::set_world_bounds(0, 0, render_scaling_ * width, render_scaling_ * height);
	input_handler_ = input_handler();
	core_loop_timer_ = timer();
	game_ = game();
	run();
}

void core::run()
{
	/*const auto target_fps = 60.0f;
	const auto delta_time = 1.0f / target_fps;
	auto accumulator = 0.0f;
	auto start_time = std::chrono::high_resolution_clock::now();
	while(running_)
	{
		const auto current_time = std::chrono::high_resolution_clock::now();
		accumulator += std::chrono::duration<float>(current_time - start_time).count();
		start_time = current_time;
		handle_events();
		game_.on_update(delta_time, input_handler_);
		if (accumulator > 0.2f)
			accumulator = 0.2f;	
		while(accumulator > delta_time)
		{
			physics();
			accumulator -= delta_time;
		}
		const auto alpha = accumulator / delta_time;
		render(alpha);
	}*/
	core_loop_timer_.start();
	game_.on_start();
	while(running_)
	{
		const auto delta_time = core_loop_timer_.get_elapsed_time();
		handle_events();
		game_.on_update(delta_time, input_handler_);
		render(0.0);
		std::this_thread::sleep_for(std::chrono::microseconds(5));
	}
	core_loop_timer_.stop();
}

void core::render(const float alpha)
{
	renderer_.begin();
	renderer_.set_draw_color(SDL_Color{ 0, 0,0, 0 });
	renderer_.clear();
	game_.on_render(renderer_);
	renderer_.end();
	renderer_.present();
}

void core::physics()
{
	
}

void core::handle_events()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_WINDOWEVENT:
			{
				switch (event.window.event)
				{
					case SDL_WINDOWEVENT_CLOSE:
					{
						running_ = false;
					} break;
				default: ;
				}
			} break;
			case SDL_MOUSEMOTION:
			{
				input_handler_.update_mouse(event, SDL_MOUSEMOTION, render_scaling_);
			} break;
			case SDL_MOUSEBUTTONDOWN:
			{
				input_handler_.update_mouse(event, SDL_MOUSEBUTTONDOWN, render_scaling_);
			} break;
			case SDL_MOUSEBUTTONUP:
			{
				input_handler_.update_mouse(event, SDL_MOUSEBUTTONUP, render_scaling_);
			} break;
			case SDL_MOUSEWHEEL:
			{
				input_handler_.update_mouse(event, SDL_MOUSEWHEEL, render_scaling_);
			} break;
		default: ;
		}
	}
}
