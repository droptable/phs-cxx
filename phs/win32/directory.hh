#ifndef _PHS_WIN32_DIRECTORY_H
#define _PHS_WIN32_DIRECTORY_H

#include <list>
#include <string>

using PathList = std::list<std::string>;

class Directory {

  static PathList& get_files(const std::string& path);

} /* class Directory */;

#endif
