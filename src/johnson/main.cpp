#include "johnson.hpp"

int main() {
  auto ug = undirected_graph<int, int>();

  ug.add_vertex(0);
  ug.add_vertex(1);
  ug.add_vertex(2);
  ug.add_vertex(3);

  ug.add_edge(0, 2, -1);
  ug.add_edge(2, 1, 7);
  ug.add_edge(1, 0, 1);
  ug.add_edge(1, 3, 2);
  ug.add_edge(3, 2, 3);
  ug.add_edge(3, 0, -4);

  auto j = Johnson(ug);
  j.shortest_paths();
  j.print_paths();
  j.print_costs();

  return 0;
}