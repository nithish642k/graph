/* DFS of an undirected graph using adjacency matrix-Recursive approach*/
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int > >&adj,int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void DFS(vector<vector<int > >adj,vector<bool>&visited,int x)
{
    visited[x]=true;
    cout<<x<<" ";
    for(int i=0;i<adj[x].size();i++)
    {
        if(!visited[adj[x][i]])
        {
            DFS(adj,visited,adj[x][i]);
        }
    }
}
int main()
{
    int n=6,e=6;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,0,3);
    addEdge(adj,1,3);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    // addEdge(adj,6,7);
    cout<<"Adjacency list:\n";
    for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<bool>visited(n,false);
    int start=0;

    DFS(adj,visited,start);
    return 0;
}
/*
To handle disconnected graph,Perform DFS from each unvisited vertex:
  for(int i=0;i<n;i++)
    if(!visited[i])
      DFS(adj,visited,i);
*/
