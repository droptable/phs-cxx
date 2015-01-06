#ifndef _PHS_DIRECTORY_H
#define _PHS_DIRECTORY_H

#include "env.hh"

#include <list>
#include <string>

namespace phs {

  using PathList = std::list<std::string>;

  struct Directory 
  {
    static PathList get_files(const std::string& path);
  };

}

#endif
