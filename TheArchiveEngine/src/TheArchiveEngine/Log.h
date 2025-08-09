#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"




namespace TheArchiveEngine {

	class THEARCHIVEENGINE_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}



//Core log macros
#define AE_CORE_TRACE(...)        ::TheArchiveEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AE_CORE_INFO(...)         ::TheArchiveEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AE_CORE_WARN(...)         ::TheArchiveEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AE_CORE_ERROR(...)        ::TheArchiveEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AE_CORE_FATAL(...)        ::TheArchiveEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)


///client log macros
#define AE_TRACE(...)             ::TheArchiveEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AE_INFO(...)              ::TheArchiveEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define AE_WARN(...)              ::TheArchiveEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AE_ERROR(...)             ::TheArchiveEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define AE_FATAL(...)             ::TheArchiveEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)

