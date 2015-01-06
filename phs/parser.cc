
#include "ast.hh"
#include "lexer.hh"
#include "parser.hh"

namespace phs {
  
  Parser::Parser()
  {}

  Parser::~Parser()
  {}

  // lexer shortcuts
  inline void Parser::skip(int n = 1) 
  { 
    lex.skip(n); 
  }

  inline const TokenPtr& Parser::peek(int n = 1) 
  { 
    return lex.peek(n); 
  }

  inline TokenPtr Parser::next()
  { 
    return lex.next(); 
  }

  void Parser::expect(Token::Type type)
  {
    if (peek()->type != type)
      throw SyntaxError();

    skip();
  }

  bool Parser::consume(Token::Type type)
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
    lex = &lex_;
    return parse_unit();
  }

  // entrypoint #2
  ast::UnitPtr Parser::parse(Source& src)
  {
    lex = new Lexer(src);
    auto unit = parse_unit();
    delete lex;
    return unit;
  }


}
