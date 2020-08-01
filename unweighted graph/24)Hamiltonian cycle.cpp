/*
Hamiltonian Path in an undirected graph is a path that visits each vertex exactly once.
A Hamiltonian cycle (or Hamiltonian circuit) is a Hamiltonian Path such that there is an edge
(in the graph) from the last vertex to the first vertex of the Hamiltonian Path.

Determine whether a given graph contains Hamiltonian Cycle or not.
If it contains, then prints the path.

Backtracking solution
*/
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int > >&adj,int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool isSafe(vector<vector<int > >mat,vector<int>path,int pos,int v)
{
    if(mat[path[pos-1]][v]==0)  // Check if the vertex is an adjacent vertex of the previously added vertex.
        return false;
    for(int i=0;i<path.size();i++)
    {
        if(path[i]==v)
            return false; // if the vertex is already includes in the path
    }
    return true;
}
bool hamiltonianCycle(vector<vector<int > >mat,vector<int>&path,int pos)
{
    int n=mat.size();
    if(pos==n)
    {
        if(mat[path[pos-1]][path[0]]==1)
            return true;
        else
            return false;
    }
    for(int v=1;v<n;v++)
    {
        if(isSafe(mat,path,pos,v))
        {
            path[pos]=v;
            if(hamiltonianCycle(mat,path,pos+1))
                return true;
            path[pos]=-1; // If adding vertex v doesn't lead to a solution,then remove it
        }
    }
    return false;
}
int main()
{
    int n=5,e=7;   // graph with even cycle->bipartite
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,3,4);
    addEdge(adj,0,3);
    addEdge(adj,3,1);
    addEdge(adj,1,4);
     addEdge(adj,4,2);

    cout<<"Adjacency list:\n";
    for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<vector<int>>mat(n,vector<int>(n,0)); // prepare adj matrix for computation
    for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            mat[i][adj[i][j]]=1;
        }
    }
    cout<<"Adjacency matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<int>path(n,-1);
    path[0]=0;
    /* Let us put vertex 0 as the first vertex in the path.
    If there is a Hamiltonian Cycle, then the path can be
    started from any point of the cycle as the graph is undirected */
    if(hamiltonianCycle(mat,path,1)) // pass path by reference
    {
        cout<<"Hamiltonian Cycle:";
        for(int i=0;i<n;i++)
            cout<<path[i]<<" ";
        cout<<path[0];
    }
    else
    {
        cout<<"No hamiltonian cycle";
    }
    return 0;
}
