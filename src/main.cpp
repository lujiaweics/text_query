#include <fstream>

#include "../include/AndQuery.hpp"
#include "../include/NotQuery.hpp"
#include "../include/OrQuery.hpp"
#include "../include/Query.hpp"
#include "../include/TextQuery.hpp"
#include "../include/util.hpp"

int main() {
  std::ifstream in("../res/article.txt");
  if (!in) {
    std::cout << "file open error" << std::endl;
    exit(-1);
  }

  TextQuery tQuery(in);
  Query q = Query("fiery") & Query("bird") | Query("wind");
  print(std::cout, q.eval(tQuery));
  q = ~Query("beautiful") & (Query("fiery") | Query("bird"));
  print(std::cout, q.eval(tQuery));

  in.close();

  return 0;
}