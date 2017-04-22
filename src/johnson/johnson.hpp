#ifndef JOHNSON_HPP
#define JOHNSON_HPP

#include "../undirected_graph/undirected_graph.hpp"
#include "../bellman_ford/bellman_ford.hpp"
#include "../dijkstra/dijkstra.hpp"
#include <vector>

struct Johnson {
  undirected_graph<int, int> G;
   
  Johnson(undirected_graph<int, int> & G) : G(G) { }

  void shortest_paths();

  
};

void Johnson::shortest_paths() {
  //check if re-weight is needed?
/* reweighting graph */
  for(auto e : G.edges())
    std::cout << e.weight << " ";
  std::cout << "\n";

  undirected_graph<int, int> temp;

  for(auto v : G.verticies()) {
    temp.add_vertex(v.data);
  }

  for(auto e : G.edges()) {
    temp.add_edge(e.source, e.target, e.weight);
  }
  //temp.verticies().size() with be our 'x' node for bellman
  int x = temp.verticies().size();
  temp.add_vertex(x);
  for(auto v : temp.verticies()) {
    temp.add_edge(x, v.data, 0);
  }

  auto bf = Bellman_ford(temp, x);
  bf.shortest_path();
  std::vector<int> temp_distances = bf.distance;
  
  for(auto d : temp_distances)
    std::cout << d << " ";
  std::cout << "\n";
  
  undirected_graph<int, int> reweighted_graph;
  for(auto v : G.verticies())
    reweighted_graph.add_vertex(v.data);

  

  for(auto e : G.edges()) {
    int weight = e.weight + temp_distances[e.source] - temp_distances[e.target];
    reweighted_graph.add_edge(e.source, e.target, weight);
  }



  for(auto e : reweighted_graph.edges())
    std::cout << e.weight << " ";
  std::cout << "\n";

  /* reweighted graph finished */

  /* run dijkstras on all verticies */
  /* distances[0] holds vector of distances to nodes from vertex 0 */
  std::vector<std::vector<int>> distances;
  std::vector<std::vector<int>> parents;

  for(auto v : reweighted_graph.verticies()) {
    auto d = Dijkstra(reweighted_graph, v.data);
    d.shortest_path();
    std::cout << v.data << " -> " << v.data << "\n";
    d.print_path();
    distances.push_back(d.distance);
    parents.push_back(d.parent);
  }


  /* should move printing of path to its own function. also need to find costs of original graph by using path



  return;
}

#endif