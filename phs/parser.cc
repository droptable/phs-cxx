
#include "ast.hh"
#include "lexer.hh"
#include "parser.hh"

namespace phs {

  Parser::Parser()
  {}

  Parser::~Parser()
  {}

  // lexer shortcuts
  inline void Parser::skip(int n = 1) { lex.skip(n); }
  inline const TokenUPtr& Parser::peek(int i = 1) { return lex.peek(i); }
  inline TokenPtr Parser::next() { return lex.next(); }

  void Parser::expect(const Token::BaseType type)
  {
    if (peek()->type != type)
      throw SyntaxError();

      skip();
    }

  bool Parser::consume(const Token::BaseType type)
  {
    if (peek()->type == type) {
      skip();
      return true;
    }

    return false;
  }

  void Parser::consume_semis()
  {
    while (peek()->type == ';')
      skip();
    }

  // entrypoint #1
  ast::UnitPtr Parser::parse(Lexer& lex_)
  {
    lex = lex_;
    return parse_unit();
  }

  // entrypoint #2
  ast::UnitPtr Parser::parse(Source& src)
  {
    lex = Lexer{src};
    return parse_unit();
  }

} /* ns phs */;
