#include <cassert>

#include "lexer.hh"

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

  const TokenPtr& Lexer::peek(int n = 1)
  {
    assert(n > 0);

    while (queue.size() < n)
      if (scan(true))
        queue.push_back(TokenPtr(std::move(tok)));
      else {
        assert(eof != nullptr);
        return eof;
      }

    return queue[n - 1];
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

