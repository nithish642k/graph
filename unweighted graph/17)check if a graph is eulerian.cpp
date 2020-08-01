#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>>&adj,int u,int v)
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
bool isStronglyConnected(vector<vector<int > >adj)
{
    for(int i=0;i<adj.size();i++)
    {
        vector<bool>visited(adj.size(),false);
        DFS(adj,visited,i);
        for(int j=0;j<adj.size();j++)
        if(!visited[j])
            return false;
    }
    return true;
}
bool isEulerian(vector<vector<int>>adj)
{
    if(!isStronglyConnected(adj))   // check if the graph is a single strongly connected component
        return false;
    vector<int>inDegree(adj.size(),0);
    for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            inDegree[adj[i][j]]++;
        }
    }
    for(int i=0;i<adj.size();i++)
    {
        if(inDegree[i]!=adj[i].size()) // check if inDegree equals out degree
            return false;
    }
    return true;
}
int main()
{
    int n=5;
    vector<vector<int>>adj(n,vector<int>());
    addEdge(adj,1,0);
    addEdge(adj,0,2);
    addEdge(adj,2,1);
    addEdge(adj,0,3);
    addEdge(adj,3,4);
    addEdge(adj,4,0);

    /*int n=6;
    vector<vector<int>>adj(n,vector<int>());
    addEdge(adj,1,0);
    addEdge(adj,0,2);
    addEdge(adj,2,1);
    addEdge(adj,0,3);
    addEdge(adj,3,4);
    addEdge(adj,4,0);
    addEdge(adj,0,5);*/

    if(isEulerian(adj))
        cout<<"The graph is eulerian";
    else
        cout<<"The graph is not eulerian";
    return 0;
}
