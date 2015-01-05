#include <cassert>

#include "lexer.hh"

inline TokenUPtr& generate_unique(const TokenPtr& token) {
  TokenUPtr unique{new decltype(token)};
  *unique = *token;

  return unique;
}

const std::map<std::string, Token::Type> Keywords {
  {"true", T_TRUE}, {"false", T_FALSE}, {"null", T_NULL},
  {"as", T_AS}, {"fn", T_FN}, {"let", T_LET},
  {"use", T_USE}, {"del", T_DEL}, {"new", T_NEW},
  {"enum", T_ENUM}, {"type", T_TYPE}, {"class", T_CLASS},
  {"trait", T_TRAIT}, {"iface", T_IFACE}, {"module", T_MODULE},
  {"require", T_REQUIRE}, {"ident", T_IDENT}, {"this", T_THIS},
  {"super", T_SUPER}, {"self", T_SELF}, {"get", T_GET},
  {"set", T_SET}, {"do", T_DO}, {"if", T_IF},
  {"elif", T_ELIF}, {"else", T_ELSE}, {"for", T_FOR},
  {"try", T_TRY}, {"goto", T_GOTO}, {"yield", T_YIELD},
  {"break", T_BREAK}, {"continue", T_CONTINUE}, {"print", T_PRINT},
  {"throw", T_THROW}, {"catch", T_CATCH}, {"finally", T_FINALLY},
  {"while", T_WHILE}, {"assert", T_ASSERT}, {"switch", T_SWITCH},
  {"case", T_CASE}, {"default", T_DEFAULT}, {"return", T_RETURN},
  {"const", T_CONST}, {"final", T_FINAL}, {"global", T_GLOBAL},
  {"static", T_STATIC}, {"extern", T_EXTERN}, {"public", T_PUBLIC},
  {"private", T_PRIVATE}, {"protected", T_PROTECTED}, {"sealed", T_SEALED},
  {"inline", T_INLINE}, {"unsafe", T_UNSAFE}, {"native", T_NATIVE},
  {"hidden", T_HIDDEN}, {"php", T_PHP}, {"test", T_TEST},
  {"int", T_TINT}, {"bool", T_TBOOL}, {"float", T_TFLOAT},
  {"string", T_TSTR}, {"tuple", T_TTUP}, {"dec", T_TDEC},
  {"any", T_TANY}, {"__DIR__", T_CDIR}, {"__FILE__", T_CFILE},
  {"__LINE__", T_CLINE}, {"__COLN__", T_CCOLN}, {"__FN__", T_CFN},
  {"__CLASS__", T_CCLASS}, {"__TRAIT__", T_CTRAIT}, {"__METHOD__", T_CMETHOD},
  {"__MODULE__", T_CMODULE}
};

namespace phs {

  Lexer::Lexer(Source& src_)
    : src(src_)
  {
    tok = nullptr;
    eof = nullptr;
  }

  void Lexer::skip(int n = 1)
  {
    if (queue.size())
      queue.pop_front();
    else
      scan(false);
  }

  TokenUPtr Lexer::peek(int i = 1)
  {
    assert(i > 0);

    while (queue.size() < i)
      if (scan(true))
        queue.push_back(TokenPtr(tok));
      else {
        assert(eof != nullptr);
        return generate_unique(eof);
      }

    return generate_unique(queue[i - 1]);
  }

  TokenPtr Lexer::next()
  {
    if (queue.size()) {
      TokenPtr ref = queue[0];
      queue.pop_front();
      return ref;
    }

    if (scan(true))
      return TokenPtr(tok);

    assert(eof != nullptr);
    return eof;
  }

  bool Lexer::scan(bool mk)
  {
    skip_ws();

    return scan_rxp(mk) ||
           scan_str(mk) ||
           scan_anum(mk) ||
           scan_rid(mk) ||
           scan_punct(mk) ||
           scan_end(mk);
  }
}
