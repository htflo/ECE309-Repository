#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

// We assume we know the number of nodes up-front; not a fundamental 
// requirement but it simplifies our implementation for now.

class Graph {
protected:                 
  int numNodes;                    // number of nodes

public:
  Graph(int num):numNodes(num){}   // create a graph with num nodes

  virtual void addEdge(int v1,int v2) = 0;

  virtual void addAdjacentTo(int node, vector<int> adj) { 
     for (int to: adj) addEdge(node,to);
  }

  virtual vector<int> getAdjacentTo(int node) = 0;
};

class SparseGraph : public Graph {
protected:
  
  class Node {                     // represents each node
  public:
    vector<int> edges;          // adjacency list
  };
  
  Node *nodes;                     // array of nodes
  
public:
  SparseGraph(int num);                 // create a graph with num nodes
  void addEdge(int v1,int v2) override; // add edge from v1 to v2
  vector<int> getAdjacentTo(int node) override;
};

SparseGraph::SparseGraph(int num)
  :Graph(num) /*call base class constructor*/
{
  nodes = new Node[numNodes]; // allocate node array, each entry is a node
}   
// Add an edge to the graph         
void SparseGraph::addEdge(int v1,int v2) {
  // if v1 >= numNodes
  
   vector<int> &edges = nodes[v1].edges;
   if (std::find(edges.begin(),edges.end(),v2) == edges.end()) {
     nodes[v1].edges.push_back(v2); // add v2 to v1’s list
     // since edges are bi-directional, we add it both ways:
     nodes[v2].edges.push_back(v1); // add v1 to v2’s list
   }
}

// Return node’s adjacency list
vector<int> SparseGraph::getAdjacentTo(int node) 
{
   return nodes[node].edges;
}

class DenseGraph : public Graph {
protected:
  bool *edges; // interpret as a 2-D array, edge[i][j] => edge[N*i + j]
  int index(int i, int j) { return i*numNodes+j; }
public:
  DenseGraph(int num);                    // create a graph with num nodes
  void addEdge(int v1,int v2) override;   // add edge from v1 to v2
  vector<int> getAdjacentTo(int node) override;
};


DenseGraph::DenseGraph(int num)
:Graph(num) {
	edges = new bool[numNodes*numNodes]; // need num*num bools
    for(int i=0; i<numNodes*numNodes; i++) edges[i] = false;
} 
                   
void DenseGraph::addEdge(int v1, int v2) {
  edges[index(v1,v2)] = true;
  edges[index(v2,v1)] = true;
}

// Return node’s adjacency list
vector<int> DenseGraph::getAdjacentTo(int node) 
{
   vector<int> adj;
   for(int i=0; i<numNodes; i++) {
      if (edges[index(node,i)]) {
         adj.push_back(i);
      }
   }
   return adj;
}

int main()
{
  Graph &g = *(new DenseGraph(5));

  g.addEdge(0,1);
  g.addEdge(1,4);
  g.addEdge(1,2);
  g.addEdge(4,2);
  g.addEdge(0,3);
  g.addEdge(3,2);

  int from = 4;
  vector<int> adj = g.getAdjacentTo(from);
  
  /*for(auto i = adj.begin(); i != adj.end(); i++)
    {
      int to = *i;
      std::cout << 0 << "->" << to << std::endl;
    }
  */
  
  for(int to: adj)
    {
      std::cout << from << "->" << to << std::endl;
    }
  
  return 0;
}


