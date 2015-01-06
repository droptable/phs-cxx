#ifndef _PHS_ENV_HH
#define _PHS_ENV_HH

#if defined(_WIN32)
#define OS_WINDOWS

#elif defined(__gnu_linux__) || defined(__linux__)
#define OS_LINUX

#elif defined(__APPLE__) || defined(__MACH__)
#define OS_APPLE

#else
#define OS_UNKNOWN

#endif

#endif
