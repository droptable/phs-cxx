#ifndef _PHS_SOURCE_HH
#define _PHS_SOURCE_HH

#include "setup.hh"

#include <iostream>
#include <fstream>

#include "ast.hh"

namespace phs {

  struct Source
  {
    // parsed unit for this source
    ast::Unit* unit;

    virtual std::string& get_alias();
    virtual std::istream& get_stream();
  };

  class FileSource : public Source
  {
    std::fstream& fp;

  public:
    FileSource(const char*);
    ~FileSource();

    std::string& get_alias();
    std::istream& get_stream();
  };

}

#endif
