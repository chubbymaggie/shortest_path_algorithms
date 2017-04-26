#include "../bellman_ford/bellman_ford.hpp"
#include "../undirected_graph/undirected_graph.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

const int S = 1000;
const int N = 1000000;

int main() {

for (int n = S; n <= N; n += S) {

    // Time based random seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    // Pre-generate all the numbers we're going to pick and put them in
    // a random order.
    std::vector<int> random(n);
    std::iota(random.begin(), random.end(), 0);
    std::shuffle(random.begin(), random.end(), std::default_random_engine(seed));

    // Setting up the graph
    undirected_graph<int, int> ug;
    for (int i = 0; i < n; ++i) {
      ug.add_vertex(i);

      /* for sparse graph */
      ug.add_edge(i, random[i], rand() % 40);

      /* for dense graph */
      // for(int j = 0; j < n; j++) {
      //   ug.add_edge(i, j, rand() % 40);
      // }
    }
    // Set up Dijkstra
    auto bf = Bellman_ford(ug, 0);

    // Get the current system time in nanoseconds.
    auto start = std::chrono::system_clock::now();
    
    // Perform shortest path
    bf.shortest_path();

    // Get the current system time in nanoseconds.
    auto stop = std::chrono::system_clock::now();

    // Print the number of nanoseconds each test takes.
    std::cout << n << ' ' << (stop - start).count() << std::endl;
  }




  return 0;
}