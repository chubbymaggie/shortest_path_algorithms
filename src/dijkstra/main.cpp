#include "dijkstra.hpp"
#include "../directed_graph/directed_graph.hpp"
#include <algorithm>
#include <random>
#include <chrono>

int main() {

  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

  auto G = directed_graph(2000000); 

  std::vector<int> nodes1;
  std::vector<int> nodes2;

  std::vector<int> weights;


  for(int i = 0; i < 2000000; i++)
    nodes1.push_back(i);

  for(int i = 1; i < 2000000; i++)
    nodes2.push_back(i);

  for(int i = 0; i < 2000000; i ++)
    weights.push_back(rand() % 10);

   //std::shuffle(nodes1.begin(), nodes1.end(), std::default_random_engine(seed));
   //std::shuffle(nodes2.begin(), nodes2.end(), std::default_random_engine(seed));
   std::shuffle(weights.begin(), weights.end(), std::default_random_engine(seed));


   for(int i = 0; i < 2000000; i++) {
     G.add_edge(nodes1[i], nodes2[i], weights[i]);
   }

  auto d = Dijkstra(G, 0);

  d.shortest_path();
  
  return 0;
};
