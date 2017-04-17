#include "../undirected_graph/undirected_graph.hpp"
#include <vector>
#include <iostream>
#include <queue>
#include <climits>

struct Dijkstra {
  undirected_graph<int, int> G;
  int src;

  Dijkstra(undirected_graph<int, int> & G, int src) : G(G), src(src) { }
  
  std::vector<int> shortest_path();  

}; 

std::vector<int> Dijkstra::shortest_path() {

  std::priority_queue<std::pair<int,int> , std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>> > queue;
  std::vector<int> distance(G.verticies().size(), INT_MAX);

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
      }
    }
  }

  for(int i = 0; i < distance.size(); i++)
    if(distance[i] != INT_MAX)
      std::cout << i << " --> " << distance[i] << "\n";
  
  return distance;
}



