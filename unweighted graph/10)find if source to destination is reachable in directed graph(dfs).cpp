/*
idea:if DFS from source visits destination,it is possible to reach dest from src,else not
*/
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int > >&adj,int u,int v)
{
    adj[u].push_back(v);
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
int main()
{
    int n=4,e=6;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,0);
    addEdge(adj,0,2);
    addEdge(adj,2,3);
    addEdge(adj,3,3);
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
    int src=0,dest=2;
    DFS(adj,visited,src);
    if(visited[dest])
        cout<<"Reachable";
    else
        cout<<"Unreachable";
    return 0;
}
