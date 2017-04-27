#ifndef JOHNSON_HPP
#define JOHNSON_HPP

#include "../undirected_graph/undirected_graph.hpp"
#include "../bellman_ford/bellman_ford.hpp"
#include "../dijkstra/dijkstra.hpp"
#include <vector>
#include <iomanip>

struct Johnson {
  undirected_graph<int, int> G;

  std::vector<std::vector<int>> distances;
  std::vector<std::vector<int>> parents;
  std::vector<int> temp_distances;
   
  Johnson(undirected_graph<int, int> & G) : G(G) { }

  void reweight_graph(undirected_graph<int, int> &, undirected_graph<int, int> &);
  void shortest_paths();
  void print_paths();
  void print_costs();
  
};

void Johnson::shortest_paths() {
  //check if re-weight is needed?

  undirected_graph<int, int> reweighted_graph;
  reweight_graph(G, reweighted_graph);

  /* run dijkstras on all verticies */
  /* distances[0] holds vector of distances to nodes from vertex 0 */
  for(auto u : reweighted_graph.verticies()) {
    auto d = Dijkstra(reweighted_graph, u.data);
    d.shortest_path();
    std::vector<int> org_dist;
    for(auto v : G.verticies()) {
      int org = d.distance[v.data] - temp_distances[u.data] + temp_distances[v.data];
      org_dist.push_back(org);
    }
    distances.push_back(org_dist);
    parents.push_back(d.parent);
  }

  return;
}

void Johnson::print_paths() {

  for(auto parent : parents) {
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
}

void Johnson::print_costs() {
  for(auto v : distances) {
    for(auto i : v) {
      std::cout << std::setw(2) << i << ' ';
    }
    std::cout << "\n";
  }
}

void Johnson::reweight_graph(undirected_graph<int, int> & G, undirected_graph<int, int> & reweighted_graph) {
  // need to be able to edit weights in graph, that would get rid of this extra graph
  undirected_graph<int, int> temp;

  for(auto v : G.verticies()) {
    temp.add_vertex(v.data);
  }

  for(auto e : G.edges()) {
    temp.add_edge(e.source, e.target, e.weight);
  }

  //temp.verticies().size() will be our 'x' node for bellman
  int x = temp.verticies().size();
  temp.add_vertex(x);
  for(auto v : temp.verticies()) {
    temp.add_edge(x, v.data, 0);
  }

  auto bf = Bellman_ford(temp, x);
  bf.shortest_path();
  temp_distances = bf.distance;
  
  for(auto v : G.verticies())
    reweighted_graph.add_vertex(v.data);
  
  for(auto e : G.edges()) {
    int weight = e.weight + temp_distances[e.source] - temp_distances[e.target];
    reweighted_graph.add_edge(e.source, e.target, weight);
  }

}

#endif