#ifndef _PHS_SOURCE_HH
#define _PHS_SOURCE_HH

#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "types.hh"
#include "ast.hh"

namespace phs {

  using SourcePtr = std::shared_ptr<Source>;
  using SourceList = std::list<SourcePtr>;

  struct Source
  {
    enum Type { 
      TYPE_GENERIC, // stdin/out or somewhere else managed
      TYPE_MEMORY,  // from memory [TBI]
      TYPE_TEXT,    // from a string
      TYPE_FILE     // from a file
    };

    Source(const Type, const std::string&);
    Source(const Type, const std::string&, std::istream*);
    Source(const Type, const std::string&, std::istream*, std::ostream*);
    virtual ~Source();

    // returns the source-type
    const Type& get_type() const;

    // returns the parsed unit for this source (parse-tree)
    ast::UnitPtr get_unit() const;

    // returns the name of this source (path or alias)
    // used as "location" in various debug/error outputs
    const std::string& get_name() const;

    // should return the destination stream
    virtual std::ostream& get_ostream();

    // should return the input stream
    virtual std::istream& get_istream();

    static SourceList from_dir(const std::string&);
    static SourcePtr from_text(const std::string&);
    static SourcePtr from_file(const std::string&);

  private:
    const Type type;
    const std::string name;

    // the stream (in/out) is owned by this source-instance.
    // which is not always the case (std::cin/out/err)
    bool i_owned = true;
    bool o_owned = true;

    std::istream* istm;
    std::ostream* ostm;

  protected:
    // set output stream
    void set_ostream(std::ostream*, bool);
    // set input stream
    void set_istream(std::istream*, bool);
  };

  struct FileSource : public Source
  {
    // note: NOT the same as 
    // `Source(Source::SRC_FILE, "path", open("path"))`
    // the input-stream gets managed by the source
    FileSource(const std::string&);
    virtual ~FileSource();
  };

  struct TextSource : public Source 
  {
    TextSource(const std::string&, std::string);
    TextSource(const std::string&, char*);
    TextSource(const std::string&, char*, size_t);
    virtual ~TextSource();
  };

}

#endif
