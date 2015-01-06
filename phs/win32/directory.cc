#include "../directory.hh"

#ifdef _UNICODE
#error "use a multibyte charset"
#endif

namespace phs {

  PathList Directory::get_files(const std::string& path)
  {
    PathList files;

    WIN32_FIND_DATA find_data;
    HANDLE find_handle;

    find_handle = FindFirstFile((path + "\\*").c_str(), &find_data);

    if (INVALID_HANDLE_VALUE == find_handle)
      return files;

    std::string abs_path;

    do {
      if (!(find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
        abs_path = path + '\\' + find_data.cFileName;
        files.push_back(std::move(abs_path));
      }
    } while (0 != FindNextFile(find_handle, &find_data));

    FindClose(find_handle);

    return files;
  }

}
