#include "application.h"

#include "log.h"

namespace Magnetar
{

bool Application::init()
{
	Logger::init();

	// TODO: Actually initialise stuff here

	LOG_INFO("Application starting up...");
	return true;
}

void Application::shutdown()
{
	LOG_INFO("Application shutting down...");
}

}
