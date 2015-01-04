#ifndef _PHS_SOURCE_HH
#define _PHS_SOURCE_HH

#include <iostream>
#include <memory>

#include "ast.hh"
#include "types.hh"

namespace phs {

  template<class stream_type=std::istream>
  struct Source
  {
    private:
      stream_type stream;

    public:
      std::shared_ptr<ast::Unit> unit;

    public:
      Source(stream_type&& stream);

    public:
      std::string& get_alias();
      stream_type& get_stream();
  } /* class Source */;
}

#endif
