#ifndef _PHS_AST_HH
#define _PHS_AST_HH

#include <vector>
#include <memory>

#include "types.hh"
#include "lexer.hh"

namespace phs {
  namespace ast {

    // types
    using Mods = std::vector<TokenPtr>;
    using ModsPtr = std::shared_ptr<Mods>;

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
      const LocPtr loc;
      const Kind kind;

      Node(const LocPtr, const Kind);
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

    // pointer types
    using NodePtr = std::shared_ptr<Node>;

    using UnitPtr = std::shared_ptr<Unit>;
    using ModulePtr = std::shared_ptr<Module>;
    using ContentPtr = std::shared_ptr<Content>;

    using DeclPtr = std::shared_ptr<Decl>;

    using UseDeclPtr = std::shared_ptr<UseDecl>;
    using UseItemPtr = std::shared_ptr<UseItem>;

    using ClassDeclPtr = std::shared_ptr<ClassDecl>;
    using IfaceDeclPtr = std::shared_ptr<IfaceDecl>;
    using TraitDeclPtr = std::shared_ptr<TraitDecl>;

    using FnDeclPtr = std::shared_ptr<FnDecl>;
    using VarDeclPtr = std::shared_ptr<VarDecl>;
    using VarListPtr = std::shared_ptr<VarList>;
    using VarItemPtr = std::shared_ptr<VarItem>;

    using StmtPtr = std::shared_ptr<Stmt>;

    using BlockPtr = std::shared_ptr<Block>;
    using DoStmtPtr = std::shared_ptr<DoStmt>;
    using IfStmtPtr = std::shared_ptr<IfStmt>;
    using ForStmtPtr = std::shared_ptr<ForStmt>;
    using ForInStmtPtr = std::shared_ptr<ForInStmt>;

    using TryStmtPtr = std::shared_ptr<TryStmt>;
    using GotoStmtPtr = std::shared_ptr<GotoStmt>;
    using TestStmtPtr = std::shared_ptr<TestStmt>;
    using BreakStmtPtr = std::shared_ptr<BreakStmt>;
    using ContinueStmtPtr = std::shared_ptr<ContinueStmt>;
    using ThrowStmtPtr = std::shared_ptr<ThrowStmt>;
    using WhileStmtPtr = std::shared_ptr<WhileStmt>;
    using AssertStmtPtr = std::shared_ptr<AssertStmt>;

    using SwitchStmtPtr = std::shared_ptr<SwitchStmt>;
    using CaseItemPtr = std::shared_ptr<CaseItem>;

    using ReturnStmtPtr = std::shared_ptr<ReturnStmt>;
    using ExprStmtPtr = std::shared_ptr<ExprStmt>;

    using ExprPtr = std::shared_ptr<Expr>;

    using UnaryExprPtr = std::shared_ptr<UnaryExpr>;
    using BinaryExprPtr = std::shared_ptr<BinaryExpr>;
    using CondExprPtr = std::shared_ptr<CondExpr>;
    using AssignExprPtr = std::shared_ptr<AssignExpr>;
    using CastExprPtr = std::shared_ptr<CastExpr>;
    using CheckExprPtr = std::shared_ptr<CheckExpr>;

    using RxpLitPtr = std::shared_ptr<RxpLit>;
    using StrLitPtr = std::shared_ptr<StrLit>;
    using ArrLitPtr = std::shared_ptr<ArrLit>;
    using TupLitPtr = std::shared_ptr<TupLit>;
    using ObjLitPtr = std::shared_ptr<ObjLit>;
    using ObjPairPtr = std::shared_ptr<ObjPair>;

    using FnExprPtr = std::shared_ptr<FnExpr>;
    using NewExprPtr = std::shared_ptr<NewExpr>;
    using DelExprPtr = std::shared_ptr<DelExpr>;

    using ParenExprPtr = std::shared_ptr<ParenExpr>;
    using YieldExprPtr = std::shared_ptr<YieldExpr>;

    using NamePtr = std::shared_ptr<Name>;
    using IdentPtr = std::shared_ptr<Ident>;
  } /* ns ast */;
} /* ns phs */;

#endif
