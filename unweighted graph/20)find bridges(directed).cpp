/*
An edge in an undirected connected graph is a bridge iff removing it disconnects the graph.
Naive approach:
remove edges one by one, do DFS and see if they the graph is still connected,if not print the edge
Time complexity: O(E*(V+E))
*/
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int > >&adj,int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void DFS(vector<vector<int > >adj,vector<bool>&visited,int x,int rx,int ry)
{
    visited[x]=true;
    for(int i=0;i<adj[x].size();i++)
    {
        if(!(x==rx&&adj[x][i]==ry)&&!visited[adj[x][i]])
        {
            DFS(adj,visited,adj[x][i],rx,ry);
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
    cout<<"Bridges:";
    for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            int flag=0;
            int rx=i;
            int ry=adj[i][j];
            vector<bool>visited(n,false);
            DFS(adj,visited,0,rx,ry);
            for(int k=0;k<n;k++)
            {
              if(!visited[k])
              {
                flag=1;
                break;
              }
            }
            if(flag)
            {
              cout<<rx<<" "<<ry<<endl;
            }
        }
    }
    return 0;
}
