/* Strongly Connected graph-possible to reach every vertex from every other vertex through a series of directed edges
Time complexity: O(V*(V+E))
performs dfs v times
An efficient approach would be using Kosajaru's algorithm
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
bool checkSCC(vector<vector<int > >adj)
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
int main()
{

    int n=5,e=6;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,0);
    addEdge(adj,2,4);
    addEdge(adj,4,2);

    /*
    int n=4,e=3;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    */
    cout<<"Adjacency list:\n";
    for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    bool connected=checkSCC(adj);

    if(connected)
        cout<<"\nStrongly connected graph";
    else
        cout<<"\nNot strongly connected graph";

    return 0;
}
