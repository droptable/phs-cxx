#ifndef _PHS_SOURCE_HH
#define _PHS_SOURCE_HH

#include <iostream>
#include <fstream>
#include <memory>

#include "ast.hh"
#include "types.hh"

namespace phs {

  struct Source
  {
    private:
      std::istream stream; // keeps filebuf

    public:
      std::shared_ptr<ast::Unit> unit;

    public:
      Source(std::istream&& stream);

    public:
      std::string& get_alias();
      std::istream& get_stream();
  } /* class Source */;
}

#endif
