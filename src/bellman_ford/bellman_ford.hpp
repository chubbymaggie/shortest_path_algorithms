#include "../undirected_graph/undirected_graph.hpp"
#include <vector>
#include <climits>
#include <iostream>

#ifndef BELLMAN_FORD_HPP
#define BELLMAN_FORD_HPP

struct Bellman_ford {
  undirected_graph<int, int> G;
  int src;
  std::vector<int> distance;
  std::vector<int> parent;

  Bellman_ford(undirected_graph<int, int> & G, int src) : G(G), src(src), distance(G.verticies().size(), INT_MAX), parent(G.verticies().size(), -1) { }

  void shortest_path();

};

void Bellman_ford::shortest_path() {
  distance[src] = 0;

   for(int i = 0; i < G.verticies().size() - 1; i++) {
     for(auto e : G.edges()) {
       int u = e.source;
       int v = e.target;
       int w = e.weight;
       if(distance[u] != INT_MAX && distance[u] + w < distance[v]) {
         distance[v] = distance[u] + w;
         parent[v] = u;
       }
     }
   }

   for(auto e : G.edges()) {
     int u = e.source;
     int v = e.target;
     int w = e.weight;
     if(distance[u] != INT_MAX && distance[u] + w < distance[v]) {
       std::cout << "Graph contains a negative cycle\n";
       return;
     }
   }

  for(int i = 0; i < distance.size(); i++)
    if(distance[i] != INT_MAX)
      std::cout << i << " --> " << distance[i] << "\n";

  for(int i = 0; i < parent.size(); i++) 

    if(parent[i] != -1) {
      std::vector<int> path;
      path.push_back(i);
      int p = parent[i];
      while(p != -1) {
        path.push_back(p);
        p = parent[p];
      }

      reverse(path.begin(), path.end());

      for(int i = 0; i < path.size() - 1; i++) {
        std::cout << path[i] << " -> ";
      }

      std::cout << path[path.size() - 1] << "\n";

    }
  

   return;
}

#endif