#ifndef DIRECTED_GRAPH_HPP
#define DIRECTED_GRAPH_HPP

#include <list>

struct directed_graph {
  int size;
  std::list<std::pair<int, int>> * list;
  directed_graph(int s) : size(s) {
    list = new std::list<std::pair<int, int>> [size];
  }


  void add_edge(int u, int v, int w);

};

void directed_graph::add_edge(int u, int v, int w) {
  list[u].push_back(std::make_pair(v, w));
  list[v].push_back(std::make_pair(u, w));

  return;
}


#endif