#ifndef GRAPH_PRINT_HPP
#define GRAPH_PRINT_HPP

#include "../undirected_graph/undirected_graph.hpp"
#include <vector>
#include <iostream>

void print_graph(undirected_graph<int, int> & G) {

  std::cout << "digraph {\n";

  for(auto v : G.verticies()) {
    std::cout << "\t" << v.data << ";\n";
  }

  for(auto e : G.edges()) {
    std::cout << "\t" << e.source << " -> " << e.target << ";\n";
  }

  std::cout << "}\n";
}

#endif
