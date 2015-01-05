#include "token.hh"

namespace phs {

  Loc::Loc(const std::string& file_, const Span& span_)
    : file(file_), span(span_)
  {}

  Span::Span(const uint line_, const uint coln_)
    : line(line_), coln(coln_)
  {}

  Token::Token(const Token::BaseType type)
    : type(type)
  {
    this->lit.str_lit.data = nullptr;
  }

  Token::~Token()
  {
    if((this->type == T_STR_LIT || this->type == T_RXP_LIT) &&
      this->lit.str_lit.data != nullptr)
      delete[] lit.str_lit.data;
  }

} /* ns phs */;
