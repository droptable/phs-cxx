#ifndef _PHS_SOURCE_HH
#define _PHS_SOURCE_HH

#include <iostream>
#include <fstream>
#include <memory>
#include <list>
#include <exception>

#include "ast.hh"
#include "types.hh"

namespace phs {

  enum SourceType {
    ST_TEXT,
    ST_FILE
  };

  class FileNotFound : public std::exception {};

  template<class StreamBuffer>
  class Source
  {
    public:
      using StreamBufferPtr = std::unique_ptr<StreamBuffer>;
      using SourceList = std::list< Source<StreamBuffer> >;

    private:
      std::string alias;
      std::iostream stream;
      StreamBufferPtr buffer;
      const Type type;

    public:
      ast::UnitPtr unit;

    public:
      Source(const std::string& alias, StreamBuffer* buffer, const SourceType type);

    public:
      static SourceList from_directory(const std::string& path);
      static Source<StreamBuffer> from_file(const std::string& path);
      static Source<StreamBuffer> from_text(const std::string& text);

    public:
      const std::string& get_alias();
      std::iostream& get_stream();
      const Type get_type();
  } /* class Source */;

# include "source.cc.inl"

  using TextSource = Source<std::stringbuf>;
  using FileSource = Source<std::filebuf>;
} /* ns phs */;

#endif
