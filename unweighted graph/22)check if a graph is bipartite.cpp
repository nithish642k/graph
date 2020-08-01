/*
Problem: is it possible to color vertices of the graph using two colors such that now two adjacent
vertices are colored using same color.

Algorithm used:DFS
*/
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int > >&adj,int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool DFS(vector<vector<int>>& adj,vector<int>&color,int x,int c)
{
    color[x]=c;
    for(int i=0;i<adj[x].size();i++)
    {
        if(color[adj[x][i]]==-1)
        {
            if(!DFS(adj,color,adj[x][i],!color[x]))
                return false;
        }
        else if(color[adj[x][i]]==color[x])
            return false;
    }
    return true;
}
bool isBipartite(vector<vector<int>>&adj)
{
    int n=adj.size();
    vector<int>color(n,-1);
    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            if(!DFS(adj,color,i,0))
                return false;
        }
    }
    return true;
}
int main()
{
    /*int n=4,e=4;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,2,3);
    addEdge(adj,0,3);
    addEdge(adj,2,1);*/

    /*int n=5,e=5;  // graph with odd cycle->not bipartite
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,0);*/

    int n=6,e=6;   // graph with even cycle->bipartite
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    addEdge(adj,5,0);

    cout<<"Adjacency list:\n";
    for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    if(isBipartite(adj))
        cout<<"Bipartite";
    else
        cout<<"Not bipartite";

    return 0;
}
