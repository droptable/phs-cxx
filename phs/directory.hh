#ifndef _PHS_DIRECTORY_H
#define _PHS_DIRECTORY_H

#include "os.hh"

#ifdef OS_UNKNOWN
# error "not implemented yet"
#endif

#include <list>
#include <string>

namespace phs {
  using PathList = std::list<std::string>;

  class Directory {
    public:
#ifdef OS_WINDOWS
      const char Separator = '\\';
#elif defined(OS_NIX)
      const char Separator = '/';
#endif

    public:
      static PathList get_files(const std::string& path);
  } /* class Directory */;
} /* ns phs */;

#endif
