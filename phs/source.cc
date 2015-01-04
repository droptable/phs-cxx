#include "source.hh"
#include "directory.hh"

namespace phs {

  Source::Source(const std::string& alias, std::istream& stream, Type type)
    : alias(alias), stream(stream), type(type)
  {}

  std::string& Source::get_alias()
  {
    return this->alias;
  }

  std::istream& Source::get_stream()
  {
    return this->stream;
  }

  type Source::get_type()
  {
    return this->type;
  }

  SourceList& SourceFactory::from_directory(const std::string& path)
  {
    PathList files = Directory::get_files(path);
    SourceList list;

    for(auto file : files)
      list.push_back(SourceFactory::from_file(file));

    return list;
  }

  Source& SourceFactory::from_file(std::string& path)
  {
    return Source{path, std::ifstream{path}, Source::IsFile};
  }

  Source& SourceFactory::from_text(std::string& text)
  {
    return Source{path, std::istream{new stringbuf{text}}, Source::IsText};
  }

  Source& SourceFactory::from_text(std::istream& stream)
  {
    return Source{path, stream, Source::IsText};
  }

} /* ns phs */;
