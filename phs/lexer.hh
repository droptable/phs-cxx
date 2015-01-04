#ifndef _PHS_LEXER_HH
#define _PHS_LEXER_HH

#include <string>
#include <deque>
#include <memory>

#include "types.hh"
#include "source.hh"
#include "token.hh"

namespace phs {

  class Lexer 
  {
    Source& src;
    std::deque<TokenPtr> queue;

    bool at_eof = false;
    bool at_end = false;

    uint line = 0;
    uint coln = 0;

    Token* tok;
    TokenPtr eof;

    //         v-  true  -> create a token, 
    //         v-  false -> discard data
    bool scan(bool);

    bool scan_rxp(bool);
    bool scan_str(bool);
    bool scan_anum(bool);
    bool scan_rid(bool);
    bool scan_punct(bool);
    bool scan_end(bool);

    void skip_ws();

  public:
    Lexer(Source&);
    ~Lexer();

    void skip(int = 1);
    const TokenPtr& peek(int = 1);
    TokenPtr next();
  };

}

#endif
