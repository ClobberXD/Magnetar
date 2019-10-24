#pragma once

#include "spdlog/spdlog.h"

namespace Magnetar
{
	class Logger
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger> &getLogger() { return sLogger; }

	private:
		static std::shared_ptr<spdlog::logger> sLogger;
	};
}

// Logger macros
#define LOG_TRACE(...) Magnetar::Logger::getLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)  Magnetar::Logger::getLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)  Magnetar::Logger::getLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) Magnetar::Logger::getLogger()->error(__VA_ARGS__)
#define LOG_FATAL(...) Magnetar::Logger::getLogger()->fatal(__VA_ARGS__)
