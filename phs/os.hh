#ifndef _PHS_OS_HH
#define _PHS_OS_HH

#if defined(_WIN32_) || defined(_WIN32) || defined(__MINGW32__) || defined(__MINGW64__)
# define OS_WINDOWS
#elif defined(__gnu_linux__) || defined(__linux__) || defined(__APPLE__) || defined(__MACH__)
# define OS_NIX
#else
# define OS_UNKNOWN
#endif

#endif
