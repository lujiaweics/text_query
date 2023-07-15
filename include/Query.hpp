#ifndef __QUERY_H__
#define __QUERY_H__

#include "QueryResult.hpp"
#include "TextQuery.hpp"
#include "WordQuery.hpp"
#include "util.hpp"

class Query {
  friend Query operator~(const Query &);
  friend Query operator|(const Query &, const Query &);
  friend Query operator&(const Query &, const Query &);

 public:
  Query(const std::string &s);
  QueryResult eval(const TextQuery &t) const;
  std::string rep() const;

 private:
  Query(std::shared_ptr<Query_base> query) : q(query) {}
  std::shared_ptr<Query_base> q;
};
QueryResult Query::eval(const TextQuery &t) const { return q->eval(t); }
std::string Query::rep() const { return q->rep(); }
inline Query::Query(const std::string &s) : q(new WordQuery(s)){};

#endif  // __QUERY_H__