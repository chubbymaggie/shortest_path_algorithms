/*
  Created by: Mike Weyandt
  12-12-2016
*/

#ifndef UNDIRECTED_GRAPH_H
#define UNDIRECTED_GRAPH_H

#include <vector>

/*
Struct: edge

  Stores edge information for an undirected graph

*/

template<typename T>
struct edge {
  edge() = default;
  edge(int u, int v, int w) : source(u), target(v), weight(w) { }

  // Order of source/target does not matter in undirected graph
  int source;
  int target;
  int weight;

  int get_weight() { return weight; }
};

/*
Struct: vertex

  Stores vertex information for an undirected graph

*/

template<typename T>
struct vertex {
  vertex() = default;
  vertex(T const& t) : data(t), edge_list() { }

  std::vector<int> edges() const { return edge_list; }

  T data;
  std::vector<int> edge_list;
};

/*
Struct: undirected_graph

  Adjacency List - Undirected Graph

*/

template<typename V, typename E>
struct undirected_graph {
  
  undirected_graph() = default;

  std::vector<vertex<V>> vertex_set;
  std::vector<edge<E>>   edge_set;

  std::vector<int> edges(int) const;

  int add_vertex(V const&);
  int add_edge(int, int, int);
  bool has_edge(int, int);
  int find_edge(int, int);
  int opposite(int, int);

  std::vector<vertex<V>> verticies() const;
  std::vector<edge<E>> edges() const;

};

/*
Function: add_vertex

  Adds a vertex to the graph, return the index into
  vertex_set that the vertex is located at

*/

template<typename V, typename E>
int undirected_graph<V, E>::add_vertex(V const& v) {
  vertex_set.emplace_back(v);
  return vertex_set.size() - 1; //index of last vertex
}

/*
Function: add_edge

  Adds an edge to the graph, returns the index into
  edge_set that the edge is located at

*/

template<typename V, typename E>
int undirected_graph<V, E>::add_edge(int u, int v, int w) {
  edge_set.emplace_back(u, v, w);
  int e = edge_set.size() - 1; //index into edge_set
  vertex_set[u].edge_list.push_back(e);
  vertex_set[v].edge_list.push_back(e);
  return e;
}

/*
Function: edges
  
  Takes an index into the vertex_set, and returns
  the edge list from that vertex

*/

template<typename V, typename E>
std::vector<int> undirected_graph<V, E>::edges(int v) const {
    return vertex_set[v].edges();
}

/*
Function: has_edge

  Returns true if the edge exists in the graph

*/

template<typename V, typename E>
bool undirected_graph<V, E>::has_edge(int u, int v) {
  return find_edge(u, v) != edge_set.size() + 1;
}

/*
Function: find_edge

  Returns the index into edge_set for the given edge
  if it exists, otherwise it returns the size of
  edge_set + 1

*/

template<typename V, typename E>
int undirected_graph<V, E>::find_edge(int u, int v) {
  if(vertex_set[u].edge_list.size() < vertex_set[v].edge_list.size()) {
    std::swap(u, v);
  }
  std::vector<int> const& edges = vertex_set[u].edges();
  for (auto e : edges) {
    if(opposite(e, u) == v) {
      return e;
    }
  }
  return edge_set.size() + 1;
}

/*
Function: opposite

  Returns the index into vertex_set that's on
  the opposite side from vertex V in the edge E

*/

template<typename V, typename E>
int undirected_graph<V, E>::opposite(int e, int v) {
  if (v == edge_set[e].source)
    return edge_set[e].target;
  else
    return edge_set[e].source;
}

/*
Function: verticies
  
  Returns the vertex_set for the graph

*/

template<typename V, typename E>
std::vector<vertex<V>> undirected_graph<V, E>::verticies() const {
  return vertex_set;
}

/*
Function: edges

  Returns the edge_set for the graph

*/

template<typename V, typename E>
std::vector<edge<E>> undirected_graph<V, E>::edges() const {
  return edge_set;
}


#endif
