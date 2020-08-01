/*
idea:every directed acyclic graph has a topological order
no topological order->cycle exists
*/
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int > >&adj,int u,int v)
{
    adj[u].push_back(v);
}
bool graphHasCycle(vector<vector<int > >adj)
{
    int n=adj.size();
    vector<int>inDegree(n,0);
    for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            inDegree[adj[i][j]]++;
        }
    }
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        if(inDegree[i]==0)
        {
            q.push(i);
        }
    }
    int visitedNodes=0;
    while(!q.empty())
    {
        visitedNodes++;
        int x=q.front();
        q.pop();
        for(int i=0;i<adj[x].size();i++)
        {
            inDegree[adj[x][i]]--;
            if(inDegree[adj[x][i]]==0)
            {
                q.push(adj[x][i]);
            }
        }
    }
    return visitedNodes!=n;
}
int main()
{
    /*int n=3,e=3;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,0);*/

    /*int n=3,e=3;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,0,2);*/

    /*int n=4,e=4;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,1);*/

    int n=5,e=6;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,0,2);
    addEdge(adj,0,3);
    addEdge(adj,3,4);
    addEdge(adj,4,0);

    cout<<"Adjacency list:\n";
    for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    if(graphHasCycle(adj))
    {
        cout<<"Graph has cycle";
    }
    else
    {
        cout<<"No cycle";
    }
    return 0;
}
