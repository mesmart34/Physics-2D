#pragma once
#include "display.h"
#include "renderer.h"
#include "input_handler.h"
#include "timer.h"
#include "game.h"
#include <thread>

class core
{
public:
	core() = default;
	core(int width, int height);
private:
	void initialize(int width, int height);
	void run();
	void render(const float alpha);
	void physics();
	void handle_events();
	display display_{};
	renderer renderer_{};
	input_handler input_handler_{};
	timer core_loop_timer_;
	game game_{};
	bool running_;
	float render_scaling_ = 0.5f;
};
