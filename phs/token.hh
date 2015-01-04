#ifndef _PHS_TOKEN_HH
#define _PHS_TOKEN_HH

#include <string>
#include <memory>
#include <map>
#include <type_traits>

#include "types.hh"

namespace phs {

  class Token;
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
    enum Type: int
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
    } type;

    using BaseType = std::underlying_type<Type>;
    /*using Type = int; // we're using both ints and chars as type,
    // a special enum would be too strict.
    const Type type;*/

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

    Token(const BaseType);
    ~Token();
  };

  std::map<std::string, Token::Type> Keywords {
    {"true", Token::T_TRUE}, {"false", Token::T_FALSE}, {"null", Token::T_NULL},
    {"as", Token::T_AS}, {"fn", Token::T_FN}, {"let", Token::T_LET},
    {"use", Token::T_USE}, {"del", Token::T_DEL}, {"new", Token::T_NEW},
    {"enum", Token::T_ENUM}, {"type", Token::T_TYPE}, {"class", Token::T_CLASS},
    {"trait", Token::T_TRAIT}, {"iface", Token::T_IFACE}, {"module", Token::T_MODULE},
    {"require", Token::T_REQUIRE}, {"ident", Token::T_IDENT}, {"this", Token::T_THIS},
    {"super", Token::T_SUPER}, {"self", Token::T_SELF}, {"get", Token::T_GET},
    {"set", Token::T_SET}, {"do", Token::T_DO}, {"if", Token::T_IF},
    {"elif", Token::T_ELIF}, {"else", Token::T_ELSE}, {"for", Token::T_FOR},
    {"try", Token::T_TRY}, {"goto", Token::T_GOTO}, {"yield", Token::T_YIELD},
    {"break", Token::T_BREAK}, {"continue", Token::T_CONTINUE}, {"print", Token::T_PRINT},
    {"throw", Token::T_THROW}, {"catch", Token::T_CATCH}, {"finally", Token::T_FINALLY},
    {"while", Token::T_WHILE}, {"assert", Token::T_ASSERT}, {"switch", Token::T_SWITCH},
    {"case", Token::T_CASE}, {"default", Token::T_DEFAULT}, {"return", Token::T_RETURN},
    {"const", Token::T_CONST}, {"final", Token::T_FINAL}, {"global", Token::T_GLOBAL},
    {"static", Token::T_STATIC}, {"extern", Token::T_EXTERN}, {"public", Token::T_PUBLIC},
    {"private", Token::T_PRIVATE}, {"protected", Token::T_PROTECTED}, {"sealed", Token::T_SEALED},
    {"inline", Token::T_INLINE}, {"unsafe", Token::T_UNSAFE}, {"native", Token::T_NATIVE},
    {"hidden", Token::T_HIDDEN}, {"php", Token::T_PHP}, {"test", Token::T_TEST},
    {"int", Token::T_TINT}, {"bool", Token::T_TBOOL}, {"float", Token::T_TFLOAT},
    {"string", Token::T_TSTR}, {"tuple", Token::T_TTUP}, {"dec", Token::T_TDEC},
    {"any", Token::T_TANY}, {"__DIR__", Token::T_CDIR}, {"__FILE__", Token::T_CFILE},
    {"__LINE__", Token::T_CLINE}, {"__COLN__", Token::T_CCOLN}, {"__FN__", Token::T_CFN},
    {"__CLASS__", Token::T_CCLASS}, {"__TRAIToken::T__", T_CTRAIT}, {"__METHOD__", Token::T_CMETHOD},
    {"__MODULE__", Token::T_CMODULE}
  };

} /* ns phs */;

#endif /* _PHS_TOKEN_HH */
