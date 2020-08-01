#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int > >&adj,int u,int v)
{
    adj[u].push_back(v);
}
bool DFS(vector<vector<int > >adj,int x,vector<bool>&visited,vector<bool>&recStack,stack<int>&s)
{
    if(recStack[x])
    {
        return true;
    }
    if(visited[x])
    {
        return false; // the node is already visited and we didn't get a cycle with this node
    }
    visited[x]=true;
    recStack[x]=true;
    s.push(x);
    for(int i=0;i<adj[x].size();i++)
    {
        if(DFS(adj,adj[x][i],visited,recStack,s))
        {
            return true;
        }
    }
    recStack[x]=false;
    s.pop();
    return false;
}
bool graphHasCycle(vector<vector<int > >adj)
{
    vector<bool>visited(adj.size(),false);
    for(int i=0;i<adj.size();i++)
    {
        vector<bool>recStack(adj.size(),false);
        stack<int>s;
        if(DFS(adj,i,visited,recStack,s))
        {
            while(!s.empty())
            {
                cout<<s.top()<<" ";
                s.pop();
            }
            return true;
        }
    }
    return false;
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

    int n=4,e=4;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,1);

    /*int n=5,e=6;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,0,2);
    addEdge(adj,0,3);
    addEdge(adj,3,4);
    addEdge(adj,4,0);*/

    /*int n=7,e=9;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,0,2);
    addEdge(adj,0,3);
    addEdge(adj,3,4);
    addEdge(adj,4,0);
    addEdge(adj,0,5);
    addEdge(adj,5,6);
    addEdge(adj,6,0);*/

    cout<<"Adjacency list:\n";
    for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Cycles:\n";
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
