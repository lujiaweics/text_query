#ifndef __WORDQUERY_H__
#define __WORDQUERY_H__

#include "QueryResult.hpp"
#include "Query_base.hpp"
#include "TextQuery.hpp"
#include "util.hpp"

class WordQuery : public Query_base {
  friend class Query;
  WordQuery(const std::string &s) : query_word(s) {}
  QueryResult eval(const TextQuery &t) const;
  std::string rep() const override;
  std::string query_word;
};

QueryResult WordQuery::eval(const TextQuery &t) const {
  return t.query(query_word);
}

std::string WordQuery::rep() const { return query_word; }

#endif  // __WORDQUERY_H__