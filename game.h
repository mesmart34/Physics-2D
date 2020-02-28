#pragma once
#include <iostream>
#include <vector>
#include "abstract_game.h"
#include "game.h"

class game final : public abstract_game
{
public:
	void on_start() override;
	void on_update(float delta_time, input_handler& input) override;
	void on_render(renderer& renderer) override;
};
