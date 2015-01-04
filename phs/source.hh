#ifndef _PHS_SOURCE_HH
#define _PHS_SOURCE_HH

#include <iostream>
#include <fstream>
#include <memory>
#include <list>

#include "ast.hh"
#include "types.hh"

namespace phs {

  using SourceList = std::list<Source>;

  struct Source
  {
    public:
      enum Type {
        IsText,
        IsFile
      };

    private:
      std::istream stream; // keeps filebuf
      Type type;

    public:
      std::shared_ptr<ast::Unit> unit;

    public:
      Source(const std::string& alias, std::istream&& stream, Type type);

    public:
      std::string& get_alias();
      std::istream& get_stream();
  } /* class Source */;

  struct SourceFactory {
    public:
      static SourceList& from_directory(const std::string& path);

      static Source& from_file(std::string& path);

      static Source& from_text(std::string& text);
      static Source& from_text(std::istream& stream);
  } /* class SourceFactory */;

}

#endif
