#include "dijkstra.hpp"
#include "../undirected_graph/undirected_graph.hpp"

int main() {
  auto G = undirected_graph<int, int>(); 

  G.add_vertex(0);
  G.add_vertex(1);
  G.add_vertex(2);
  G.add_vertex(3);
  G.add_edge(0, 1, 10);
  G.add_edge(0, 3, 9);
  G.add_edge(0, 2, 7);
  G.add_edge(2, 3, 1);

  return 0;
};
