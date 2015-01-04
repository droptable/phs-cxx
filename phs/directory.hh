#ifndef _PHS_DIRECTORY_H
#define _PHS_DIRECTORY_H

#include "os.hh"

#ifdef OS_UNKNOWN
# error "not implemented yet"
#endif

#include <list>
#include <string>

using PathList = std::list<std::string>;

#ifdef OS_WINDOWS
const char PathSeparator = '\\';
#elif defined(OS_NIX)
const char PathSeparator = '/';
#endif

class Directory {
  public:
    static PathList get_files(const std::string& path);
} /* class Directory */;

#endif
