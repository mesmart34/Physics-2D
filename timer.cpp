#include "timer.h"

void timer::start()
{
	start_time_ = std::chrono::high_resolution_clock::now();
	running_ = true;
}

void timer::stop()
{
	running_ = false;
}

double timer::get_elapsed_time()
{
	if (!running_) 
		return 0.0f;
	start_time_ = end_time_;
	end_time_ = std::chrono::high_resolution_clock::now();
	return std::chrono::duration<double>(end_time_ - start_time_).count();
}

bool timer::is_running() const
{
	return running_;
}
