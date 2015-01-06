#include "../directory.hh"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

namespace phs {

  PathList Directory::get_files(const std::string& path)
  {
    PathList files;

    dirent *ent;
    stat ent_info;
    DIR *dir = opendir(path.c_str());

    if (nullptr == dir)
      return files;

    std::string abs_path;

    while (nullptr != (ent = readdir(dir))) {
      abs_path = (path + '/' + std::string(ent.d_name));

      if (0 == stat(abs_path.c_str(), &ent_info) && S_ISREG(ent_info.st_mode))
        files.push_back(std::move(abs_path));

      abs_path.clear();
    }

    closedir(dir);

    return files;
  }

}
