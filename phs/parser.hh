#ifndef _PHS_PARSER_HH
#define _PHS_PARSER_HH

#include <list>

#include "types.hh"
#include "ast.hh"
#include "lexer.hh"
#include "source.hh"

namespace phs {

  class ParseError : public std::exception {};
  class SyntaxError : public ParseError {};

  class Parser
  {
    Lexer& lex;

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
    inline const TokenPtr& peek(int = 1);
    inline TokenPtr next();

  public:
    Parser();
    ~Parser();

    ast::UnitPtr parse(Lexer&);
    ast::UnitPtr parse(Source&);

    // parse methods

    ast::UnitPtr parse_unit();

    ast::ModulePtr parse_module();
    ast::ContentPtr parse_content();
    ast::ModulePtr parse_module_nst();

    ast::UseDeclPtr parse_use_decl(const ast::ModsPtr&);
    ast::UseItemPtr parse_use_decl_item();

    ast::ClassDeclPtr parse_class_decl(const ast::ModsPtr&);
    ast::TraitDeclPtr parse_trait_decl(const ast::ModsPtr&);
    ast::IfaceDeclPtr parse_iface_decl(const ast::ModsPtr&);

    ast::FnDeclPtr parse_fn_decl(const ast::ModsPtr&);
    ast::VarDeclPtr parse_var_decl(const ast::ModsPtr&);
    ast::VarDeclPtr parse_var_decl_no_semi(const ast::ModsPtr&, bool);
    ast::VarListPtr parse_var_list_decl(const LocPtr&, const ast::ModsPtr&, bool);
    ast::VarItemPtr parse_var_item(bool);

    ast::StmtPtr parse_stmt();
    ast::BlockPtr parse_block();

    ast::NodePtr parse_comp();
    ast::NodePtr parse_label_or_stmt();

    ast::DoStmtPtr parse_do_stmt();
    ast::IfStmtPtr parse_if_stmt();

    ast::ForStmtPtr parse_for_stmt();
    ast::ForInStmtPtr parse_for_in_stmt();
    
    ast::TryStmtPtr parse_try_stmt();
    ast::GotoStmtPtr parse_goto_stmt();
    ast::TestStmtPtr parse_test_stmt();
    ast::BreakStmtPtr parse_break_stmt();
    ast::ContinueStmtPtr parse_continue_stmt();
    ast::ThrowStmtPtr parse_throw_stmt();
    ast::WhileStmtPtr parse_while_stmt();
    ast::AssertStmtPtr parse_assert_stmt();

    ast::SwitchStmtPtr parse_switch_stmt();
    ast::CaseItemPtr parse_switch_case();

    ast::ReturnStmtPtr parse_return_stmt();
    ast::ExprStmtPtr parse_expr_stmt();

    ast::ExprPtr parse_expr(bool, bool);
    ast::ExprPtr parse_expr_ops(int, bool, bool);
    ast::ExprPtr parse_primary_expr(bool, bool);
    ast::ExprPtr parse_member_expr(bool, bool);
    ast::ExprPtr parse_expr_atom(bool, bool);

    ast::RxpLitPtr parse_rxp_lit();
    ast::StrLitPtr parse_str_lit();
    ast::ArrLitPtr parse_arr_lit();
    ast::TupLitPtr parse_tup_lit();
    ast::ObjLitPtr parse_obj_lit();
    ast::ObjPairPtr parse_obj_pair();

    ast::FnExprPtr parse_fn_expr(bool);
    ast::NewExprPtr parse_new_expr(bool);
    ast::DelExprPtr parse_del_expr(bool);
    ast::YieldExprPtr parse_yield_expr(bool);

    ast::NamePtr parse_name();
    ast::IdentPtr parse_ident(bool);
  };

}

#endif
