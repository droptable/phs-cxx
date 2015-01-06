
#include "token.hh"

namespace phs {

  Loc::Loc(const std::string& file_, const SpanPtr span_)
    : file(file_), span(span_)
  {}

  Span::Span(const uint line_, const uint coln_)
    : line(line_), coln(coln_)
  {}

  Token::Token(const Token::Type type_, const LocPtr loc_)
    : type(type_), loc(loc_)
  {
    lit.str_lit.data = nullptr;
  }

  Token::~Token()
  {
    if ((type == T_STR_LIT || type == T_RXP_LIT) &&
        lit.str_lit.data != nullptr)
      delete[] lit.str_lit.data;
  }

}

