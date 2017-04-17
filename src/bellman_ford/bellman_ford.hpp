#include "../undirected_graph/undirected_graph.hpp"
#include <vector>
#include <climits>
#include <iostream>

#ifndef BELLMAN_FORD_HPP
#define BELLMAN_FORD_HPP

struct Bellman_ford {
  undirected_graph<int, int> G;
  int src;

  Bellman_ford(undirected_graph<int, int> & G, int src) : G(G), src(src) { }

  void shortest_path();

};

void Bellman_ford::shortest_path() {
  std::vector<int> distance(G.verticies().size(), INT_MAX);
  distance[src] = 0;

   for(int i = 0; i < G.verticies().size() - 1; i++) {
     for(auto e : G.edges()) {
       int u = e.source;
       int v = e.target;
       int w = e.weight;
       if(distance[u] != INT_MAX && distance[u] + w < distance[v])
         distance[v] = distance[u] + w;
     }
   }

   for(auto e : G.edges()) {
     int u = e.source;
     int v = e.target;
     int w = e.weight;
     if(distance[u] != INT_MAX && distance[u] + w < distance[v])
       std::cout << "Graph contains a negative cycle\n";
   }

  for(int i = 0; i < distance.size(); i++)
    std::cout << i << "  -->  " << distance[i] << "\n";

   return;
}

#endif