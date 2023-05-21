#include <bits/stdc++.h>
#include "../include/TextQuery.hpp"

void runQueries(std::ifstream &infile) {
  TextQuery tq(infile);
  while(true) {
    std::cout << "enter word to look for, or q to quit: " ;
    std::string s;
    if (!(std::cin >> s) || s == "q") {
      break;
    }
    print(std::cout, tq.query(s)) << std::endl;
  }
}

int main() {
  std::ifstream in("../res/article.txt");
	if (!in) {
		std::cout << "file open error" << std::endl;
		exit(-1);
	}
  runQueries(in);
  in.close();

  return 0;
}