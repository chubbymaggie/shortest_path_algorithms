#ifndef FLOYD_HPP
#define FLOYD_HPP

#include "../undirected_graph/undirected_graph.hpp"
#include <vector>
#include <climits>
#include <iostream>

struct Floyd {
  undirected_graph<int, int> G;
  std::vector<std::vector<int>> distances;
  std::vector<std::vector<int>> parents;

  Floyd(undirected_graph<int, int> & G) : G(G) {
    for(auto v : G.verticies()) {
      std::vector<int> dtemp(std::vector<int>(G.verticies().size(), 3000000));
      std::vector<int> ptemp(std::vector<int>(G.verticies().size(), 0));
      distances.push_back(std::move(dtemp));
      parents.push_back(std::move(ptemp));
    }
  }

  void shortest_paths();
  void print_paths();
  void print_costs();

};

void Floyd::shortest_paths() {

  // set up the initial distances vector
  for(int i = 0; i < G.verticies().size(); i++) {
    distances[i][i] = 0;  // I think this might break something if there is a negative cycle
    for(int j = 0; j < G.verticies()[i].edge_list.size(); j++) {
      auto edge = G.verticies()[i].edge_list[j];
      distances[i][G.edges()[edge].target] = G.edges()[edge].weight;
    }
  }
  
  //The actual algorithm
  for(int k = 0; k < G.verticies().size(); k++) {
    for(int i = 0; i < G.verticies().size(); i++) {
      for(int j = 0; j < G.verticies().size(); j++) {
        if(distances[i][k] + distances[k][j] < distances[i][j]) {
          distances[i][j] = distances[i][k] + distances[k][j];
          parents[i][j] = k;
        }
      }
    }
  }

  return;
}

void Floyd::print_paths() {
  for(auto v : parents) {
    for(auto i : v) {
      std::cout << i << ' ';
    }
    std::cout << "\n";
  }
}

void Floyd::print_costs() {
  for(auto v : distances) {
    for(auto i : v) {
      std::cout << i << ' ';
    }
    std::cout << "\n";
  }
}

#endif