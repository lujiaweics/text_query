/**
 * @file QueryResult.hpp
 *
 * This file contains a declaration of the QueryResult struct which saves the result from query.
 */
#include <bits/stdc++.h>
using line_no = std::vector<std::string>::size_type;

class QueryResult {
  friend std::ostream& print(std::ostream&, const QueryResult&);
 public:
  QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f): sought(s), lines(p), file(f) {}
 private:
  std::string sought;                                               // the query word
  std::shared_ptr<std::set<line_no>> lines;                         // refer to the set which saves the line numbers the word occurs
  std::shared_ptr<std::vector<std::string>> file;                   // refer to the vector which saves the input text
};

// formatting singular or plural forms of word
std::string make_plural(size_t ctr, const std::string& word , const std::string& ending) {
	return ctr == 1 ? word : word + ending;
}

std::ostream& print(std::ostream& os, const QueryResult &qr) {
  os << qr.sought << " occours " << qr.lines->size() << " "
    << make_plural(qr.lines->size(), "time", "s") << std::endl;
  for (auto num: *qr.lines) {
    os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
  }
  return os;
}