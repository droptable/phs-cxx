#ifndef _PHS_ENV_HH
#define _PHS_ENV_HH

#if defined(_WIN32)
#define OS_WINDOWS
#include <windows.h>

#else
#include <unistd.h>

#ifdef _POSIX_VERSION
#define OS_POSIX
#endif

#if defined(__gnu_linux__) || defined(__linux__)
#define OS_LINUX

/* @TODO bsd */
#elif defined(__APPLE__) || defined(__MACH__)
#define OS_UNIX

#else
#define OS_UNKNOWN
#endif /* defined(__gnu_linux__) || defined(__linux__) */

#endif /* defined(_WIN32) */

#endif
