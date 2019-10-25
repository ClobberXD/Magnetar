#include "magnetar.h"

int main()
{
	if (!Magnetar::Application::init())
		return 1;

	Magnetar::Application::shutdown();
	return 0;
}
