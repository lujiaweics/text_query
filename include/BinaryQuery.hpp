#ifndef __BINARYQUERY_H__
#define __BINARYQUERY_H__

#include "Query.hpp"
#include "Query_base.hpp"

class BinaryQuery : public Query_base {
 protected:
  BinaryQuery(const Query &l, const Query &r, std::string s)
      : lhs(l), rhs(r), opSym(s) {}
  std::string rep() const;
  Query lhs, rhs;
  std::string opSym;
};

std::string BinaryQuery::rep() const {
  return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
}

#endif // __BINARYQUERY_H__