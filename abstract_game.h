#pragma once
#include "renderer.h"
#include "input_handler.h"

class abstract_game
{
public:
	virtual ~abstract_game() = default;
	virtual void on_start() = 0;
	virtual void on_update(float delta_time, input_handler& input) = 0;
	virtual void on_render(renderer& renderer) = 0;
};
