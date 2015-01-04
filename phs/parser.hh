#ifndef _PHS_PARSER_HH
#define _PHS_PARSER_HH

#include "setup.hh"

#include <list>

#include "ast.hh"
#include "lexer.hh"
#include "source.hh"

namespace phs {

  class ParseError : public std::exception {};
  class SyntaxError : public ParseError {};

  class Parser
  {
    Lexer* lex;

    struct Op {
      int prec;
      int arity;
      enum {
        OP_ASSOC_NONE,
        OP_ASSOC_LEFT,
        OP_ASSOC_RIGHT
      } assoc;
    };
    
    void expect(Token::Type) throw(ParseError);
    bool consume(Token::Type);
    void consume_semis();

    // forwarded to the lexer
    inline void skip(int = 1);
    inline void push(Token*);
    inline Token* peek(int = 1);
    inline Token* next();

  public:
    Parser();
    ~Parser();

    ast::Unit* parse(Lexer&);
    ast::Unit* parse(Source&);

    // parse methods

    ast::Unit* parse_unit();

    ast::Module* parse_module();
    ast::Content* parse_content();
    ast::Module* parse_module_nst();

    ast::UseDecl* parse_use_decl(ast::Mods*);
    ast::UseItem* parse_use_decl_item();

    ast::ClassDecl* parse_class_decl(ast::Mods*);
    ast::TraitDecl* parse_trait_decl(ast::Mods*);
    ast::IfaceDecl* parse_iface_decl(ast::Mods*);

    ast::FnDecl* parse_fn_decl(ast::Mods*);
    ast::VarDecl* parse_var_decl(ast::Mods*);
    ast::VarDecl* parse_var_decl_no_semi(ast::Mods*, bool);
    ast::VarList* parse_var_list_decl(Loc*, ast::Mods*, bool);
    ast::VarItem* parse_var_item(bool);

    ast::Stmt* parse_stmt();
    ast::Block* parse_block();

    ast::Node* parse_comp();
    ast::Node* parse_label_or_stmt();

    ast::DoStmt* parse_do_stmt();
    ast::IfStmt* parse_if_stmt();

    ast::ForStmt* parse_for_stmt();
    ast::ForInStmt* parse_for_in_stmt();
    
    ast::TryStmt* parse_try_stmt();
    ast::GotoStmt* parse_goto_stmt();
    ast::TestStmt* parse_test_stmt();
    ast::BreakStmt* parse_break_stmt();
    ast::ContinueStmt* parse_continue_stmt();
    ast::ThrowStmt* parse_throw_stmt();
    ast::WhileStmt* parse_while_stmt();
    ast::AssertStmt* parse_assert_stmt();

    ast::SwitchStmt* parse_switch_stmt();
    ast::CaseItem* parse_switch_case();

    ast::ReturnStmt* parse_return_stmt();
    ast::ExprStmt* parse_expr_stmt();

    ast::Expr* parse_expr(bool, bool);
    ast::Expr* parse_expr_ops(int, bool, bool);
    ast::Expr* parse_primary_expr(bool, bool);
    ast::Expr* parse_member_expr(bool, bool);
    ast::Expr* parse_expr_atom(bool, bool);

    ast::RxpLit* parse_rxp_lit();
    ast::StrLit* parse_str_lit();
    ast::ArrLit* parse_arr_lit();
    ast::TupLit* parse_tup_lit();
    ast::ObjLit* parse_obj_lit();
    ast::ObjPair* parse_obj_pair();

    ast::FnExpr* parse_fn_expr(bool);
    ast::NewExpr* parse_new_expr(bool);
    ast::DelExpr* parse_del_expr(bool);
    ast::YieldExpr* parse_yield_expr(bool);

    ast::Name* parse_name();
    ast::Ident* parse_ident(bool);
  };

}

#endif
