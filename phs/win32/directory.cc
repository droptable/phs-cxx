#include "directory.hh"

#include <windows.h>

namespace phs {
  PathList Directory::get_files(const std::string& path)
  {
    PathList files;

    WIN32_FIND_DATA find_data;
    HANDLE find_handle;

    find_handle = FindFirstFile((path + Directory::Separator + '*').c_str(), &find_data);

    if(INVALID_HANDLE_VALUE == find_handle)
      return files;

    do {
      if(!(find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
        std::string abs_path = path + Directory::Separator + std::string(find_data.cFileName);
        files.push_back(abs_path);
      }
    } while(0 != FindNextFile(find_handle, &find_data));

    FindClose(find_handle);

    return files;
  }
} /* ns phs */;
