#ifndef FLOYD_HPP
#define FLOYD_HPP

#include "../undirected_graph/undirected_graph.hpp"
#include <vector>
#include <climits>
#include <iostream>

struct Floyd {
  undirected_graph<int, int> G;

  Floyd(undirected_graph<int, int> & G) : G(G) { }

  void shortest_paths();

};

void Floyd::shortest_paths() {
  std::vector<std::vector<int>> distances;
  std::vector<std::vector<int>> parents;

  for(auto v : G.verticies()) {
    std::vector<int> dtemp;
    std::vector<int> ptemp2;
    for(int i = 0; i < G.verticies().size(); i++) {
      dtemp.push_back(3000000); //INT_MAX causes an overflow.. not sure what to do here
      ptemp2.push_back(0);
    }
    distances.push_back(std::move(dtemp));
    parents.push_back(std::move(ptemp2));
  }

  // clean this up - this sets up the initial distances vector
  for(int i = 0; i < G.verticies().size(); i++) {
    distances[i][i] = 0;  // I think this might break something if there is a negative cycle
    for(int j = 0; j < G.verticies()[i].edge_list.size(); j++) {
      distances[i][G.edges()[G.verticies()[i].edge_list[j]].target] = G.edges()[G.verticies()[i].edge_list[j]].weight;
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

  for(auto v : distances) {
    for(auto i : v) {
      std::cout << i << ' ';
    }
    std::cout << "\n";
  }

  for(auto v : parents) {
    for(auto i : v) {
      std::cout << i << ' ';
    }
    std::cout << "\n";
  }

  return;
}

#endif