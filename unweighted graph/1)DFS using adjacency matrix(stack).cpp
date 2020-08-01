/* DFS of an undirected graph using adjacency matrix*/
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<bool > >&adj,int u,int v)
{
    adj[u][v]=adj[v][u]=1;
}
int getUnvisitedAdjVertex(vector<vector<bool > >adj,vector<bool>visited,int x)
{
    for(int i=0;i<adj.size();i++)
    {
        if(adj[x][i]==1&&!visited[i])
            return i;
    }
    return -1;
}
int main()
{
    int n=6,e=6;
    vector<vector<bool > >adj(n,vector<bool>(n));
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,0,3);
    addEdge(adj,1,3);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    cout<<"Adjacency list:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    int start=0;
    vector<bool>visited(n,false);
    stack<int>s;

    visited[start]=true;
    cout<<"DFS:"<<start<<" ";
    s.push(start);

    while(!s.empty())
    {
        int v=getUnvisitedAdjVertex(adj,visited,s.top()); // get an unvisited adjacent vertex of TOS
        if(v!=-1)
        {
            visited[v]=true;
            cout<<v<<" ";
            s.push(v);
        }
        else
        {
            s.pop();
        }
    }
    return 0;
}
