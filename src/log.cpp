#include "log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Magnetar
{
	std::shared_ptr<spdlog::logger> Logger::sLogger;

	void Logger::init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		sLogger = spdlog::stdout_color_mt("HAZEL");
		sLogger->set_level(spdlog::level::trace);

		sLogger->info("Magnetar::Logger initialised!");
	}
}
