/*
Mother vertex-all vertices can be reached from this vertex through a path
There can be more than one mother vertices in a graph.
Naive approach:
run DFS V times and check for every vertex if it reaches all other vertices
Time Complexity: O(V*(V+E))

Efficient approach(based on Kosaraju): O(V+E)
It is based on the fact that if there exist mother vertex (or vertices),
then one of the mother vertices is the last finished vertex in DFS.

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
    int n=7,e=8;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,3);
    addEdge(adj,4,1);
    addEdge(adj,6,4);
    addEdge(adj,5,6);
    addEdge(adj,5,2);
    addEdge(adj,6,0);
    cout<<"Adjacency list:\n";
    for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\nMother vertex:";

    /*for(int i=0;i<n;i++)    // naive approach
    {
        int flag=0;
        vector<bool>visited(n,false);
        DFS(adj,visited,i);
        for(int j=0;j<n;j++)
        {
            if(!visited[j])
            {
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            cout<<i<<" ";
        }
    }
    */

    vector<bool>visited(n,false);  // this approach will output only one of the mother vertices
    int v=0; // to store last finished vertex;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            DFS(adj,visited,i);
            v=i;
        }
    }
    fill(visited.begin(),visited.end(),false);
    DFS(adj,visited,v);
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            flag=1;
            break;
        }
    }
    if(!flag)
    {
            cout<<v<<" ";
    }
    return 0;
}
