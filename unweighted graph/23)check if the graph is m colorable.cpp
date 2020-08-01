/*
M-coloring problem:
Checking if the graph can be colored with at most m colors such that no two adjacent vertices have the same color.

Backtracking solution
Time complexity:O(m^V) // total combination of colors

See GFG for finding chromatic number-minimum number of colors needed to color the graph
such that no two adjacent vertices have the same color.

*/
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int > >&adj,int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool isSafe(vector<vector<int > >adj,vector<int>color,int v,int c)
{
    for(int i=0;i<adj[v].size();i++)
    {
        if(color[adj[v][i]]==c)
            return false;
    }
    return true;
}
bool graphColoring(vector<vector<int > >adj,vector<int>&color,int m,int v)
{
    int n=adj.size();
    if(v==n)
        return true;
    for(int c=1;c<=m;c++)
    {
        if(isSafe(adj,color,v,c))
        {
            color[v]=c;
            if(graphColoring(adj,color,m,v+1))
            {
                return true;
            }
            color[v]=0; // if the assigned color doesn't lead to a solution,then remove it
        }
    }
    return false;
}
int main()
{
    int n=4,e=5;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,0);
    addEdge(adj,0,2);

   /*int n=6,e=6;   // graph with even cycle->bipartite
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    addEdge(adj,5,0);*/

    cout<<"Adjacency list:\n";
    for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    int m=3; // number of colors

    vector<int>color(n,0);
    if(graphColoring(adj,color,m,0))
    {
        cout<<"Solution:";
        for(int i=0;i<color.size();i++)
            cout<<color[i]<<" ";
    }
    else
    {
        cout<<"Not possible";
    }
    return 0;
}
