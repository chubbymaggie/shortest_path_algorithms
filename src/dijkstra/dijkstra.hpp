#include "../directed_graph/directed_graph.hpp"
#include <vector>
#include <iostream>
#include <queue>
#include <climits>

struct Dijkstra {
  directed_graph G;
  int src;


  Dijkstra(directed_graph & G, int src) : G(G), src(src) { }
  
  std::vector<int> shortest_path();  
  


}; 



std::vector<int> Dijkstra::shortest_path() {


  std::priority_queue<std::pair<int,int> , std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>> > queue;
  std::vector<int> distance(2000000, INT_MAX);

  queue.push(std::make_pair(0, src));
  distance[src] = 0;

  while(!queue.empty()) {
    int u = queue.top().second;
    queue.pop();

    for(auto i = G.list[u].begin(); i != G.list[u].end(); i++) {

      int v = (*i).first;
      int weight = (*i).second;

     if(distance[v] > distance[u] + weight) {
       distance[v] = distance[u] + weight;
         queue.push(std::make_pair(distance[v], v));
     }

   
  }
}
  for(int i = 0; i < 2000000; i++)
    std::cout << i << " --> " << distance[i] << "\n";
  



  return distance;
}



