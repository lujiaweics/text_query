/**
 * @file TextQuery.hpp
 *
 * This file contains a declaration of the TextQuery struct which saves the data
 * from input file.
 */

#ifndef __TEXTQUERY_H__
#define __TEXTQUERY_H__

#include "util.hpp"
#include <sstream>
#include "QueryResult.hpp"

class TextQuery {
 public:
  using line_no = std::vector<std::string>::size_type;
  TextQuery(std::ifstream &);
  QueryResult query(const std::string &) const;

 private:
  std::shared_ptr<std::vector<std::string>>
      file;  // save the input text from the article
  std::map<std::string, std::shared_ptr<std::set<line_no>>>
      wm;  // associate each word with the set which saves the line numbers the
           // word occurs
};

TextQuery::TextQuery(std::ifstream &is) : file(new std::vector<std::string>) {
  std::string text;
  while (std::getline(is, text)) {
    file->push_back(text);
    int n = file->size() - 1;
    std::stringstream line(text);
    std::string word;
    while (line >> word) {
      auto &lines = wm[word];
      if (!lines) {
        lines.reset(new std::set<line_no>);
      }
      lines->insert(n);
    }
  }
}

QueryResult TextQuery::query(const std::string &sought) const {
  static std::shared_ptr<std::set<line_no>> nodata(
      new std::set<line_no>);  // if query word not found, return a shared_ptr
                               // which refer to a empty set
  auto loc = wm.find(sought);
  if (loc == wm.end()) {
    return QueryResult(sought, nodata, file);
  } else {
    return QueryResult(sought, loc->second, file);
  }
}

#endif // __TEXTQUERY_H__