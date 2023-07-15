#ifndef __NOTQUERY_H__
#define __NOTQUERY_H__

#include "util.hpp"
#include "Query_base.hpp"
#include "Query.hpp"

class NotQuery : public Query_base {
  friend Query operator~(const Query &);
  NotQuery(const Query &q) : query(q) {}
  std::string rep() const { return "~(" + query.rep() + ")"; }
  QueryResult eval(const TextQuery &) const;
  Query query;
};

QueryResult NotQuery::eval(const TextQuery& text) const {
  auto result = query.eval(text);
  auto ret_lines = std::make_shared<std::set<line_no>>();
  auto beg = result.begin(), end = result.end();
  auto sz = result.get_file()->size();
  for (size_t n = 0; n != sz; ++n) {
    if (beg == end || *beg != n) {
      ret_lines->insert(n);
    } else if (beg != end) {
      ++beg;
    }
  }
  return QueryResult(rep(), ret_lines, result.get_file());
}

inline Query operator~(const Query &operand) {
  return std::shared_ptr<Query_base>(new NotQuery(operand));
}

#endif // __NOTQUERY_H__