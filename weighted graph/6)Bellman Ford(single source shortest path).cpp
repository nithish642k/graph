/*
Algorithm:
   Do V-1 times:
      for every edge(u,v):
         d[u]+cost[u,v]<d[v]
           d[v]=d[u]+cost[u,v]

For a graph without negative cycles,
 the shortest distances won't not change after V-1 iterations
If the graph contains negative cycles,
 the distances will keep changing even after V-1 iterations,
  so the algorithm cannot find shortest paths if the graph contains negative cycles
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
    addEdge(cost,0,1,-1);
    addEdge(cost,0,2,4);
    addEdge(cost,1,2,3);
    addEdge(cost,1,3,2);
    addEdge(cost,1,4,2);
    addEdge(cost,3,2,5);
    addEdge(cost,3,1,1);
    addEdge(cost,4,3,-3);
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

    for(int i=0;i<n-1;i++)
    {
        for(int u=0;u<n;u++)
        {
            for(int v=0;v<n;v++)
            {
                if(cost[u][v]&&dist[u]!=INT_MAX&&dist[u]+cost[u][v]<dist[v])
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
