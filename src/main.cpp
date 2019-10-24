#include "log.h"

int main()
{
	Magnetar::Logger::init();
	LOG_ERROR("Starting up...");

	LOG_TRACE("Shutting down...");
	return 0;
}
