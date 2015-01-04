#ifndef _PHS_SOURCE_HH
#define _PHS_SOURCE_HH

#include <set>
#include <iostream>
#include <fstream>
#include <string>

#include "types.hh"
#include "ast.hh"

namespace phs {

  using SourcePtr = std::shared_ptr<Source>;
  using SourceSet = std::set<SourcePtr>;

  struct Source
  {
    enum Type { SRC_TEXT, SRC_FILE };

    Source(const std::string&, std::istream&, const Type);
    ~Source();

    const Type& get_type();
    std::string& get_name();
    std::istream& get_stream();

    static SourceSet from_dir(const std::string&);
    static SourcePtr from_text(const std::string&, std::istream&);
    static SourcePtr from_file(const std::string&, std::istream&);

  private:
    std::string& name;
    std::istream& stream;
    const Type type;
  };

}

#endif
