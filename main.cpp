#include <SDL.h>
#include "core.h"

#if _DEBUG
	#undef main
#endif

int main()
{
	auto physics = core(1280, 768);
	return 0;
}
