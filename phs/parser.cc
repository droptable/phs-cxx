
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
    // no magic here
    lex->skip(n); 
  }

  inline void Parser::push(Token* tok) 
  { 
    // no magic here
    lex->push(tok); 
  }

  inline Token* Parser::peek(int n = 1) 
  { 
    // no magic here
    return lex->peek(n); 
  }

  inline Token* Parser::next() 
  { 
    // no magic here 
    return lex->next(); 
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
    while (peek()->type == T_SEMI)
      skip();
  }

  // entrypoint #1 
  ast::Unit* Parser::parse(Lexer& lex_)
  {
    lex = &lex_;
    return parse_unit();
  }

  // entrypoint #2
  ast::Unit* Parser::parse(Source& src)
  {
    lex = new Lexer(src);
    auto unit = parse_unit();
    delete lex;
    return unit;
  }


}
