#ifndef FLOYD_HPP
#define FLOYD_HPP

#include "../undirected_graph/undirected_graph.hpp"

struct Floyd {
  undirected_graph<int, int> G;

  Floyd(undirected_graph<int, int> & G) : G(G) { }

  void shortest_paths();

};

void Floyd::shortest_paths() {

  return;
}

#endif