/*
Eulerian Path is a path in graph that visits every edge exactly once.
(Note:Hamiltonian path is a path in graph that visits every vertex exactly once.)
Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex.

The problem is same as following question.
“Is it possible to draw a given graph without lifting pencil from the paper and without tracing any of the edges more than once”.

A graph is called Eulerian if it has an Eulerian Cycle and called Semi-Eulerian if it has an Eulerian Path.

Condition for euler cycle:
1)all non-zero degree vertices are connected.
(we don’t care about vertices with zero degree because they don’t belong to Eulerian Cycle or Path)
2)all vertices have even degree

Eulerian path:
1)all non-zero degree vertices are connected.
2)even number vertices have odd degree and all other vertices have even degree.

Time complexity:O(V+E)
*/
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
    for(int i=0;i<adj[x].size();i++)
    {
        if(!visited[adj[x][i]])
        {
            DFS(adj,visited,adj[x][i]);
        }
    }
}
bool isConnected(vector<vector<int>>adj)
{
    int n=adj.size();
 vector<bool>visited(n,false);

    int v;
    for(v=0;v<n;v++)
        if(adj[v].size()!=0) // find a vertex with non zero degree,we don't need to check zero degree vertices because they dont belong to euler path
          break;

    if(v==n)
        return true; // graph with no edges is connected

    DFS(adj,visited,v);

    for(int i=0;i<n;i++)
        if(!visited[i]&&adj[i].size()>0) // check if all non-zero degree vertices are visited
           return false;
    return true;
}
int isEulerian(vector<vector<int>>adj)
{
    int n=adj.size();
    if(!isConnected(adj))
        return 0;
    int odd=0;
    for(int i=0;i<n;i++)
    {
        if(adj[i].size()%2!=0)
            odd++;   // count vertices with odd degree
    }
    if(odd>2)
        return 0; // non-euler
    else if(odd==2)
        return 1; // euler path
    else
        return 2; // euler cycle
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

    /*int n=5,e=6;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,1,0);
    addEdge(adj,0,2);
    addEdge(adj,2,1);
    addEdge(adj,0,3);
    addEdge(adj,3,4);
    addEdge(adj,4,0);*/

    /*int n=5,e=6;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,1,0);
    addEdge(adj,0,2);
    addEdge(adj,2,1);
    addEdge(adj,0,3);
    addEdge(adj,3,4);
    addEdge(adj,1,3);*/

    /*int n=3,e=3;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,1,0);
    addEdge(adj,1,2);
    addEdge(adj,2,0);*/

    cout<<"Adjacency list:\n";
    for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    int res=isEulerian(adj);
    if(res==0)
        cout<<"Not eulerian";
    else if(res==1)
        cout<<"Has eulerian path";
    else
        cout<<"Has euler cycle";
    return 0;
}
