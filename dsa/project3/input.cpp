
// C++ Program to Implement Adjacency List
#include <iostream>
#include <vector>
using namespace std;

// Class representing a graph
class Graph
 {
private:
  // Adjacency list to represent the graph
  vector<vector<int> > adjList;
  // Boolean flag to indicate if the graph is directed
  bool isDirected;

public:
  // Constructor to initialize the graph
  // Parameters: vertices - number of vertices in the
  // graph
  //  directed - flag to indicate if the graph is directed
  //  (default is false)
  Graph(int vertices, bool directed = false) {
    // Resize the adjacency list to accommodate the
    // vertices
    adjList.resize(vertices);
    // Set the directed flag
    isDirected = directed;
  }

  // Function to add an edge to the graph
  // Parameters: src - source vertex
  // dest - destination vertex
  void addEdge(int src, int dest) {
    // Add the destination to the adjacency list of the
    // source
    adjList[src].push_back(dest);
    // If the graph is undirected
    if (!isDirected) {
      // Add the source to the adjacency list of the
      // destination
      adjList[dest].push_back(src);
    }
  }

  // Function to print the adjacency list of the graph
  void printGraph(const int nodes[]) {
    // Iterate through each vertex
    for (int i = 0; i < adjList.size(); ++i) {
      // Print the vertex
      cout << nodes[i] << ": ";
      // Iterate through the adjacency list of the
      // vertex
      for (int j = 0; j < adjList[i].size(); ++j) {
        // Print each adjacent vertex
        cout << adjList[i][j] << " -> ";
      }
      // Indicate the end of the adjacency list
      cout << "NULL" << endl;
    }
  }
  void dfsrec (vector <vector<int> > &adj, vector <bool> &visted, int s)
  {
    for(size_t j=0;j<adj[s].size();++j)
    {
      int i = adj[s][j];
      if(!visted[i])//check to see if not visted 
      {
        dfsrec(adj,visted,i); //recursive call for the none visted nones
      }
    }
  }

void dfs(const vector <vector<int> > &adj ,int startNode)
{
vector <bool> visted(adj.size(),false); //set all nodes to false

performDFS(adj,visted,startNode);//start recursivly from given start node
}

void performDFS(const vector<vector<int> > &adj,vector<bool>& visted ,int currentNode )
{
visted[currentNode]=true; //mark current node as visted

cout<<"Visting node: " << currentNode<< endl; 

}


};




