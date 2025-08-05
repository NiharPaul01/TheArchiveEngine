#pragma once

#ifdef AE_PLATFORM_WINDOWS
	#ifdef AE_BUILD_DLL
		#define THEARCHIVEENGINE_API _declspec(dllexport)
	#else 
		#define THEARCHIVEENGINE_API _declspec(dllimport)
	#endif
#else 
	#error The Archive Engine only supports Windows!

#endif // DEBUG
