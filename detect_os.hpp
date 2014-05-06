#pragma once

#if defined(_WIN64) || defined(_WIN32)
	#define TARGET_WINDOWS
#elif defined(_WIN64)
	#define TARGET_WINDOWS_64_BITS
#elif defined(_WIN32)
	#define TARGET_WINDOWS_32_BITS
#elif defined(__APPLE__)
	#include "TargetConditionals.h"
	#if TARGET_OS_IPHONE
		#define TARGET_IOS
	#elif TARGET_IPHONE_SIMULATOR
		#define TARGET_IOS_SIMULATOR
	#elif TARGET_OS_MAC
		#define TARGET_OSX
	#else
		#error "You're devving on an unknown Apple-platform. Add it to this list, and update all the headers that include this header with the corresponding header files and such."
	#endif
#elif __linux
	#define TARGET_LINUX
#elif __unix
	#error "You're devving on an unknown unix-platform. Add it to this list, and update all the headers that include this header with the corresponding header files and such."
#elif __posix
	#error "You're devving on an unknown posix-platform. Add it to this list, and update all the headers that include this header with the corresponding header files and such."
#else
	#error "You're devving on an unknown platform. Add it to this list, and update all the headers that include this header with the corresponding header files and such."
#endif

