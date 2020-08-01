/*
finds shortest distance from single source to all vertices on directed weighted graph
This code uses adjacency matrix representation of the graph

Algorithm:
initialize distance to other vertices from source as INF
repeat:
 pick the vertex whose distance from source is minimum
    relax:
      if(d[u]+cost[u][v]<d[v])
        d[v]=d[u]+cost[v]

Note:Djikstra's algorithm won't give correct output when the graph contains negative edges.
To handle,negative edges,go for Bellman Ford's algorithm
*/
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int > >&adj,int u,int v,int cost)
{
    adj[u][v]=cost;
}
int getMinimumDistanceVertex(vector<int>dist,vector<bool>visited)
{
    int minDist=INT_MAX;
    int minVertex;
    for(int i=0;i<dist.size();i++)
    {
        if(dist[i]<minDist&&!visited[i])
        {
            minDist=dist[i];
            minVertex=i;
        }
    }
    return minVertex;
}
int main()
{
    int n=5;  // number of vertices
    cout<<"Adjacency matrix(cost matrix):\n";
    vector<vector<int > >cost(n,vector<int>(n,0));
    addEdge(cost,0,1,5);
    addEdge(cost,0,3,8);
    addEdge(cost,1,3,9);
    addEdge(cost,1,2,6);
    addEdge(cost,3,4,7);
    addEdge(cost,3,2,2);
    addEdge(cost,4,1,5);
    addEdge(cost,2,4,4);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }
    int src=0;
    vector<int>dist(n,INT_MAX); // initialize distances to other nodes from source as infinity
    dist[src]=0;
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++) // the direct edges from source are found only after the first iteration
    {
        int u=getMinimumDistanceVertex(dist,visited);
        visited[u]=true;
        for(int v=0;v<cost.size();v++)
        {
            if(cost[u][v]&&!visited[v]&&dist[u]!=INT_MAX&&dist[u]+cost[u][v]<dist[v])
            {
                dist[v]=dist[u]+cost[u][v];
            }
        }
    }
    cout<<"Minimum distances:";
    for(int i=0;i<n;i++)
    {
        cout<<dist[i]<<" ";
    }
    return 0;
}

