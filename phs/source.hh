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
      std::string alias;
      std::istream stream; // keeps filebuf
      const Type type;

    public:
      ast::UnitPtr unit;

    public:
      Source(const std::string& alias, const std::istream& stream, const Type type);

    public:
      const std::string& get_alias();
      const std::istream& get_stream();
      const Type get_type();
  } /* class Source */;

  struct SourceFactory {
    public:
      static SourceList from_directory(const std::string& path);

      static Source from_file(const std::string& path);

      static Source from_text(const std::string& text);
      static Source from_text(const std::istream& stream);
  } /* class SourceFactory */;

}

#endif
