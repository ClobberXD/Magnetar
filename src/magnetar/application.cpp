#include "application.h"

#include "log.h"

namespace Magnetar
{

Application::Application(int argc, char **argv)
{
	Logger::init();
	LOG_TRACE("Application::Application | argc = {0}", argc);

	// TODO: Actually initialise stuff here
}

Application::~Application()
{
	LOG_TRACE("Application::~Application");
}

int Application::run()
{
	LOG_WARN("Application::run | This function should not be executed though!");

	return 0;
}

}
