#include "../undirected_graph/undirected_graph.hpp"
#include "bellman_ford.hpp"

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6

int main() {
  
  auto ug = undirected_graph<int, int>();

  for(int i = 0; i < 7; i++) {
    ug.add_vertex(i);
  }

  ug.add_edge(A, B, 2);
  ug.add_edge(A, C, 4);
  ug.add_edge(A, F, 7);

  ug.add_edge(B, A, 2);
  ug.add_edge(B, C, 3);
  ug.add_edge(B, D, 3);

  ug.add_edge(C, A, 4);
  ug.add_edge(C, B, 3);
  ug.add_edge(C, D, 4);
  ug.add_edge(C, E, 3);
  ug.add_edge(C, F, 8);

  ug.add_edge(D, B, 3);
  ug.add_edge(D, C, 4);
  ug.add_edge(D, E, 6);
  
  ug.add_edge(E, C, 3);
  ug.add_edge(E, D, 6);
  ug.add_edge(E, F, 6);
  ug.add_edge(E, G, 8);

  ug.add_edge(F, A, 7);
  ug.add_edge(F, C, 8);
  ug.add_edge(F, E, 6);
  ug.add_edge(F, G, 12);

  ug.add_edge(G, E, 8);
  ug.add_edge(G, F, 12);

  auto bf = Bellman_ford(ug, A);
  bf.shortest_path();

  return 0;
}