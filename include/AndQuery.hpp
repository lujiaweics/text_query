#ifndef __ANDQUERY_H__
#define __ANDQUERY_H__

#include <algorithm>

#include "BinaryQuery.hpp"

class AndQuery : public BinaryQuery {
  friend Query operator&(const Query &, const Query &);
  AndQuery(const Query &left, const Query &right)
      : BinaryQuery(left, right, "&"){};
  QueryResult eval(const TextQuery &) const;
};

QueryResult AndQuery::eval(const TextQuery &text) const {
  auto left = lhs.eval(text), right = rhs.eval(text);
  auto ret_lines = std::make_shared<std::set<line_no>>();
  set_intersection(left.begin(), left.end(), right.begin(), right.end(),
                   std::inserter(*ret_lines, ret_lines->begin()));
  return QueryResult(rep(), ret_lines, left.get_file());
}

inline Query operator&(const Query &lhs, const Query &rhs) {
  return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

#endif  // __ANDQUERY_H__