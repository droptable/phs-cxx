#include "directory.hh"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

PathList Directory::get_files(const std::string& path)
{
  PathList files;

  dirent *ent;
  stat ent_info;
  DIR *dir = opendir(path.c_str());

  if(nullptr == dir)
    return files;

  while(nullptr != (ent = readdir(dir))) {
    std::string abs_path = (path + Directory::PathSeparator + std::string(ent.d_name));

    if(0 == stat(abs_path.c_str(), &ent_info) && S_ISREG(ent_info.st_mode))
      files.push_back(abs_path);
  }

  closedir(dir);

  return files;
}
