#pragma once
#include <chrono>
#include <chrono>

class timer
{
public:
	timer() = default;
	void start();
	void stop();
	double get_elapsed_time();
	bool is_running() const;
private:
	std::chrono::steady_clock::time_point start_time_;
	std::chrono::steady_clock::time_point end_time_;
	bool running_{};
};
