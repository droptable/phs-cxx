#ifndef _PHS_AST_HH
#define _PHS_AST_HH

#include <vector>

namespace phs {

  // see lexer.hh
  struct Loc;
  struct Token;

  namespace ast {

    // modifier list
    typedef std::vector<Token*> mods;

    // node-kinds
    enum class Kind 
	  {
		  UNIT, MODULE, CONTENT,
      DECL, USE_DECL, USE_ITEM,
      CLASS_DECL, TRAIT_DECL, IFACE_DECL,
      FN_DECL, VAR_DECL, VAR_LIST, VAR_ITEM,
      STMT, BLOCK, BLOCK_STMT = BLOCK,
      DO_STMT, IF_STMT, FOR_STMT, FOR_IN_STMT,
      TRY_STMT, GOTO_STMT, TEST_STMT,
      BREAK_STMT, CONTINUE_STMT,
      THROW_STMT, WHILE_STMT, ASSERT_STMT,
      SWITCH_STMT, CASE_ITEM,
      RETURN_STMT, EXPR_STMT,
      EXPR, UNARY_EXPR, BINARY_EXPR,
      COND_EXPR, ASSIGN_EXPR, CAST_EXPR, CHECK_EXPR,
      RXP_LIT, STR_LIT, ARR_LIT, TUP_LIT,
      OBJ_LIT, OBJ_PAIR,
      FN_EXPR, NEW_EXPR, DEL_EXPR,
      PAREN_EXPR, YIELD_EXPR,
      NAME, IDENT
	  };

    struct Node 
    {
      const Loc* loc;
      const Kind kind;

      Node(const Loc*, const Kind);
    };

    // basics
    struct Unit : public Node {};
    struct Module : public Node {};
    struct Content : public Node {};
    
    // declarations
    struct Decl : public Node {};

    struct UseDecl : public Decl {};
    struct UseItem : public Node {};

    struct ClassDecl : public Decl {};
    struct TraitDecl : public Decl {};
    struct IfaceDecl : public Decl {};
    
    struct FnDecl : public Decl {};
    struct VarDecl : public Decl {};
    struct VarList : public Decl {};
    struct VarItem : public Node {};
    
    // statements
    struct Stmt : public Node {};
   
    struct Block : public Stmt {};
    struct DoStmt : public Stmt {};
    struct IfStmt : public Stmt {};

    struct ForStmt : public Stmt {};
    struct ForInStmt : public Stmt {};

    struct TryStmt : public Stmt {};
    struct GotoStmt : public Stmt {};
    struct TestStmt : public Stmt {};
    struct BreakStmt : public Stmt {};
    struct ContinueStmt : public Stmt {};
    struct ThrowStmt : public Stmt {};
    struct WhileStmt : public Stmt {};
    struct AssertStmt : public Stmt {};

    struct SwitchStmt : public Stmt {};
    struct CaseItem : public Node {};

    struct ReturnStmt : public Stmt {};
    struct ExprStmt : public Stmt {};

    // expressions
    struct Expr : public Node {};
    
    struct UnaryExpr : public Expr {};
    struct BinaryExpr : public Expr {};
    struct CondExpr : public Expr {};
    struct AssignExpr : public Expr {};
    struct CastExpr : public Expr {};
    struct CheckExpr : public Expr {};

    struct RxpLit : public Expr {};
    struct StrLit : public Expr {};
    struct ArrLit : public Expr {};
    struct TupLit : public Expr {};
    struct ObjLit : public Expr {};
    struct ObjPair : public Expr {};

    struct FnExpr : public Expr {};
    struct NewExpr : public Expr {};
    struct DelExpr : public Expr {};

    struct ParenExpr : public Expr {};
    struct YieldExpr : public Expr {};

    struct Name : public Expr {};
    struct Ident : public Expr {};
  }
}

#endif
