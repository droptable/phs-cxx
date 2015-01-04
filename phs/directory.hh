#ifndef _PHS_DIRECTORY_H
#define _PHS_DIRECTORY_H

#include <list>
#include <string>

#if !defined(__WIN32__) || !defined(__gnu_linux__) || !defined(__linux__) || !defined(__APPLE__) || !defined(__MACH__)
# error "not implemented yet"
#endif

using PathList = std::list<std::string>;

class Directory {

#ifdef __WIN32__
  const char PathSeparator = '\\';
#else defined(__gnu_linux__) || defined(__linux__) || defined(__APPLE__) || defined(__MACH__)
  const char PathSeparator = '/';
#endif

  static PathList get_files(const std::string& path);

} /* class Directory */;

#endif
