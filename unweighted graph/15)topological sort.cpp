/*
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv,
vertex u comes before v in the ordering.
Topological Sorting for a graph is not possible if the graph is not a DAG.
There can be more than one topological sorting for a graph.
This is Kahn's algorithm for topological sorting
*/
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int > >&adj,int u,int v)
{
    adj[u].push_back(v);
}
int main()
{
    /*int n=3,e=3;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,0,2);*/

    int n=6,e=7;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,2,4);
    addEdge(adj,3,5);
    addEdge(adj,4,5);

    /*int n=4,e=4;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,1);*/

    cout<<"Adjacency list:\n";
    for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<int>result;

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
        result.push_back(x);
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
    if(result.size()!=n)
    {
        cout<<"Graph is not DAG";
    }
    else
    {
        cout<<"Topological order:";
        for(int i=0;i<result.size();i++)
        {
           cout<<result[i]<<" ";
        }
    }
    return 0;
}
