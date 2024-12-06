void dfsrec (vector <vector<int>> &adj, vector <bool> &visted, int s)
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

void dfs(const vector <vector<int>> &adj ,int startNode)
{
vector <bool> visted(adj.size(),false); //set all nodes to false

performDFS(adj,visted,startNode);//start recursivly from given start node
}

void performDFS(const vector<vector<int>> &adj,vector<bool>& visted ,int currentNode )
{
visted[currentNode]=true; //mark current node as visted

cout<<"Visting node: " << currentNode<< endl; 

}