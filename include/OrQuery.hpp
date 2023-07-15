#ifndef __ORQUERY_H__
#define __ORQUERY_H__

#include "BinaryQuery.hpp"

class OrQuery: public BinaryQuery {
  friend Query operator|(const Query&, const Query&);
  OrQuery(const Query &left, const Query &right): BinaryQuery(left, right, "|") {}
  QueryResult eval(const TextQuery& text) const;
};

QueryResult OrQuery::eval(const TextQuery& text) const {
  QueryResult right = this->rhs.eval(text), left = this->lhs.eval(text);
  auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
  ret_lines->insert(right.begin(), right.end());
  return QueryResult(rep(), ret_lines, left.get_file());
}

inline Query operator|(const Query &lhs, const Query &rhs) {
  return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

#endif // __ORQUERY_H__