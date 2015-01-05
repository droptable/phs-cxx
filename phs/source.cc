#include "source.hh"
#include "directory.hh"

namespace phs {

  Source::Source(const std::string& alias, const std::istream& stream, const Type type)
    : alias(alias), stream(stream), type(type)
  {}

  const std::string& Source::get_alias()
  {
    return this->alias;
  }

  const std::istream& Source::get_stream()
  {
    return this->stream;
  }

  const Type Source::get_type()
  {
    return this->type;
  }

  SourceList SourceFactory::from_directory(const std::string& path)
  {
    PathList files = Directory::get_files(path);
    SourceList list;

    for(auto file : files)
      list.push_back(SourceFactory::from_file(file));

    return list;
  }

  Source SourceFactory::from_file(const std::string& path)
  {
    return Source{path, std::ifstream{path}, Source::IsFile};
  }

  Source SourceFactory::from_text(const std::string& text)
  {
    return Source{"text", std::istream{new stringbuf{text}}, Source::IsText};
  }

  Source SourceFactory::from_text(const std::istream& stream)
  {
    return Source{"text", stream, Source::IsText};
  }

} /* ns phs */;
