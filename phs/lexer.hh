#ifndef _PHS_LEXER_HH
#define _PHS_LEXER_HH

#include "setup.hh"

#include <string>
#include <deque>
#include <memory>

#include "source.hh"

namespace phs {

  using TokenPtr = std::shared_ptr<Token>;

  struct Loc 
  {
    const std::string& file;
    const Span& span;

    Loc(const std::string&, const Span&);
  };
  
  struct Span 
  {
    const uint line;
    const uint coln;

    Span(const uint, const uint);
  };

  struct Token 
  {  
    using Type = int; // we're using both ints and chars as type, 
                      // a special enum would be too strict.
    const Type type;
    
    union {
      int32_t i32_lit;
      uint32_t u32_lit;
      int64_t i64_lit;
      uint64_t u64_lit;
      double dbl_lit;
      // utf-8 encoded string
      struct {
        uint8_t* data;
        size_t size; // in bytes
        size_t len; // in codepoints
      } str_lit;
    } lit;

    Token(const Type);
    ~Token();
  };

  enum: int 
  {
    T_EOF = 0,   // end of file
    T_END = 300, // user-defined end of source

    // literals
    T_STR_LIT, T_RXP_LIT, // quoted / regular-expression string
    T_LNUM_LIT, T_ULNUM_LIT, // 32bit
    T_QNUM_LIT, T_UQNUM_LIT, // 64bit
    T_DNUM_LIT, // double

    // keywords
    T_TRUE, T_FALSE, T_NULL,
    T_AS, T_FN,  T_LET, T_USE, T_DEL, T_NEW,
    T_ENUM, T_TYPE, T_CLASS, T_TRAIT, T_IFACE,
    T_MODULE, T_REQUIRE, T_IDENT,
    T_THIS, T_SUPER, T_SELF, T_GET, T_SET,
    T_DO, T_IF, T_ELIF, T_ELSE, T_FOR, T_TRY,
    T_GOTO, T_YIELD, T_BREAK, T_CONTINUE,
    T_PRINT, T_THROW, T_CATCH, T_FINALLY,
    T_WHILE, T_ASSERT, T_SWITCH, T_CASE, T_DEFAULT,
    T_RETURN, T_CONST, T_FINAL, T_GLOBAL,
    T_STATIC, T_EXTERN, T_PUBLIC, T_PRIVATE, T_PROTECTED,
    T_SEALED, T_INLINE, T_UNSAFE, T_NATIVE, T_HIDDEN,
    T_PHP, T_TEST, T_TINT, T_TBOOL, T_TFLOAT,
    T_TSTR, T_TTUP, T_TDEC, T_TANY,
    T_CDIR, T_CFILE, T_CLINE, T_CCOLN,
    T_CFN, T_CCLASS, T_CTRAIT, T_CMETHOD, T_CMODULE,

    // assigment
    T_APLUS, T_AMINUS, T_AMUL, T_ADIV, T_AMOD, T_APOW,
    T_AREF, T_ACONCAT, T_ASHIFT_L, T_ASHIFT_R,
    T_ABIT_OR, T_ABIT_AND, T_ABIT_XOR,
    T_ABOOL_OR, T_ABOOL_AND, T_ABOOL_XOR,

    // operators
    T_RANGE, T_DDDOT, T_ARR,
    T_BOOL_OR, T_BOOL_XOR, T_BOOL_AND,
    T_EQ, T_NEQ, T_IN, T_NIN, T_IS, T_NIS,
    T_GTE, T_LTE, T_SL, T_SR,
    T_REST, T_INC, T_DEC, T_POW
  };

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
    void push(Token*);

    TokenPtr peek(int = 1);
    TokenPtr next();
  };

}

#endif
