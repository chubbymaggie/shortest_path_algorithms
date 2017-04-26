#ifndef FLOYD_HPP
#define FLOYD_HPP

#include "../undirected_graph/undirected_graph.hpp"
#include <vector>
#include <climits>
#include <iostream>
#include <iomanip>

struct Floyd {
  undirected_graph<int, int> G;
  std::vector<std::vector<int>> distances;
  std::vector<std::vector<int>> parents;

  Floyd(undirected_graph<int, int> & G) : G(G) {
    for(auto v : G.verticies()) {
      std::vector<int> dtemp(std::vector<int>(G.verticies().size(), 3000000));
      std::vector<int> ptemp(std::vector<int>(G.verticies().size(), -1));
      distances.push_back(std::move(dtemp));
      parents.push_back(std::move(ptemp));
    }
  }

  void shortest_paths();
  void print_paths();
  void print_costs();

};

void Floyd::shortest_paths() {

  for(auto v : G.verticies()) {
    distances[v.data][v.data] = 0;
  }

  for(auto e : G.edges()) {
    distances[e.source][e.target] = e.weight;
    parents[e.source][e.target] = e.target;
  }
  
  //The actual algorithm
  for(int k = 0; k < G.verticies().size(); k++) {
    for(int i = 0; i < G.verticies().size(); i++) {
      for(int j = 0; j < G.verticies().size(); j++) {
        if(distances[i][k] + distances[k][j] < distances[i][j]) {
          distances[i][j] = distances[i][k] + distances[k][j];
          parents[i][j] = parents[i][k];
        }
      }
    }
  }

  return;
}

void Floyd::print_paths() {
  for(int i = 0; i < parents.size(); i++) {
    for(int j = 0; j < parents[i].size(); j++) {

      if(parents[i][j] == -1) {
        std::cout << i << " -> " << j << "\n";
      }
      else {
        int u = i;
        int v = j;
        std::vector<int> path;
        path.push_back(u);
        while(u != v) {
          u = parents[u][v];
          path.push_back(u);
        }
        for(int y = 0; y < path.size() - 1; y++) {
          std::cout << path[y] << " -> ";
        }
        std::cout << path[path.size() - 1] << "\n";
      }
    }
  }
}

void Floyd::print_costs() {
  for(auto v : distances) {
    for(auto i : v) {
      std::cout << std::setw(2) << i << ' ';
    }
    std::cout << "\n";
  }
}

#endif