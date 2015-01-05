#include "source.hh"
#include "directory.hh"

namespace phs {

  template<class StreamBuffer>
  Source<StreamBuffer>::Source(const std::string& alias, StreamBuffer* buffer, const SourceType type)
    : alias(alias), stream(buffer), buffer(buffer), type(type)
  {}

  template<class StreamBuffer>
  const std::string& Source<StreamBuffer>::get_alias()
  {
    return this->alias;
  }

  template<class StreamBuffer>
  std::iostream& Source<StreamBuffer>::get_stream()
  {
    return this->stream;
  }

  template<class StreamBuffer>
  const Type Source<StreamBuffer>::get_type()
  {
    return this->type;
  }

  template<class StreamBuffer>
  SourceList Source<StreamBuffer>::from_directory(const std::string& path)
  {
    PathList files = Directory::get_files(path);
    SourceList list;

    for(auto file : files) /* TODO: file extension detection */
      list.push_back(Source<StreamBuffer>::from_file(file));

    return list;
  }

  template<class StreamBuffer>
  Source<StreamBuffer> Source<StreamBuffer>::from_file(const std::string& path)
  {
    StreamBuffer* buf = (new StreamBuffer)->open(path);

    if(nullptr == buf)
      throw FileNotFound();

    return Source<StreamBuffer>{path, buf, ST_FILE};
  }

  template<class StreamBuffer>
  Source<StreamBuffer> Source<StreamBuffer>::from_text(const std::string& text)
  {
    return TextSource{"text", new StreamBuffer{text}, ST_TEXT};
  }

} /* ns phs */;
