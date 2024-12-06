#include "input.cpp"
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

  int size;
  cout << "input size of the graph " << endl;
  cin >> size;

  int nodes[size];
  cout << "input nodes for the graph " << endl;

  for (int i = 0; i < size; ++i) {
    cin >> nodes[i];
  }

  int startingNode;
  int endingNode;

  cout << "Choose the starting node from the graph" << endl;
  cin >> startingNode;

  cout << "Choose the ending node from the graph" << endl;
  cin >> endingNode;

  Graph undirectedGraph(size);

  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; j++) {
      undirectedGraph.addEdge(nodes[i], nodes[j]);
    }
  }

  cout << "Undirected Graph Adjacency List:" << endl;
  undirectedGraph.printGraph(nodes);

  cout << "Connectivity Status: " << endl;
  cout << "Shortest Path: " << endl;
  cout << "total distance: " << endl;
}
