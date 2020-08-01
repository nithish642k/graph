/*
A vertex in an undirected connected graph is an articulation point (or cut vertex)
iff removing it disconnects the graph

Articulation points represent vulnerabilities in a connected network

For a disconnected undirected graph,
an articulation point is a vertex removing which increases number of connected components.

Naive approach:
remove vertices one by one and check if it disconnects the graph(using DFS)
time complexity: O(V*(V+E))

Better approach:
The idea is to use DFS (Depth First Search).
In DFS, we follow vertices in tree form called DFS tree. In DFS tree,
a vertex u is parent of another vertex v, if v is discovered by u.

In DFS tree, a vertex u is articulation point if one of the following two conditions is true.
1) u is root of DFS tree and it has at least two children.
2) u is not root of DFS tree and it has a child v such that no vertex in subtree rooted with v
   has a back edge to one of the ancestors (in DFS tree) of u.
See Tushar roy's video and GFG for this approach
*/
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int > >&adj,int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void DFS(vector<vector<int > >adj,vector<bool>&visited,int x,int removedVertex)
{
    visited[x]=true;
    for(int i=0;i<adj[x].size();i++)
    {
        if(adj[x][i]!=removedVertex&&!visited[adj[x][i]])
        {
            DFS(adj,visited,adj[x][i],removedVertex);
        }
    }
}
int main()
{
    int n=5,e=5;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,1,0);
    addEdge(adj,0,2);
    addEdge(adj,2,1);
    addEdge(adj,0,3);
    addEdge(adj,3,4);

    /*int n=4,e=3;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);*/

    /*int n=7,e=8;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,0);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,1,6);
    addEdge(adj,3,5);
    addEdge(adj,4,5);*/

    cout<<"Adjacency list:\n";
    for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Articulation point:";
    for(int i=0;i<n;i++)    // naive approach
    {
        int flag=0;
        int removedVertex=(i+1)%n;
        vector<bool>visited(n,false);
        DFS(adj,visited,i,removedVertex);
        for(int j=0;j<n;j++)
        {
            if(j!=removedVertex&&!visited[j])
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            cout<<removedVertex<<" ";
        }
    }
    return 0;
}
