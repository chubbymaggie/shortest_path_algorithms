#include "../undirected_graph/undirected_graph.hpp"
#include <vector>
#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

struct Dijkstra {
  undirected_graph<int, int> G;
  int src;
  std::vector<int> distance;
  std::vector<int> parent;

  Dijkstra(undirected_graph<int, int> & G, int src) : G(G), src(src), distance(G.verticies().size(), INT_MAX), parent(G.verticies().size(), -1) { }
  
  void shortest_path();
  void print_cost();
  void print_path();

}; 

void Dijkstra::shortest_path() {

  std::priority_queue<std::pair<int,int> , std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>> > queue;

  auto verticies = G.verticies();
  auto edges = G.edges();

  // (cost, vertex)
  queue.push(std::make_pair(0, src));
  distance[src] = 0;

  while(!queue.empty()) {
    int u = queue.top().second;
    queue.pop();

    for(auto i : verticies[u].edge_list) {
      int v = G.opposite(i, u);
      int weight = edges[i].weight;

      if (distance[v] > distance[u] + weight) {
        distance[v] = distance[u] + weight;
        queue.push(std::make_pair(distance[v], v));
        parent[v] = u;
      }
    }
  }
  
  return;
}


void Dijkstra::print_cost() {

  for(int i = 0; i < distance.size(); i++)
    if(distance[i] != INT_MAX)
      std::cout << i << " --> " << distance[i] << "\n";

  return;
}

void Dijkstra::print_path() {
  for(int i = 0; i < parent.size(); i++) {

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
  }
}




