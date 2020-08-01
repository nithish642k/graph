/*
idea:If the graph contains negative cycles,
 the shortest path distances will keep changing even after V-1 iterations,
  so the algorithm cannot find shortest paths if the graph contains negative cycles.
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
bool BellmanFordNegCycle(vector<vector<int > >cost,vector<bool>&visited,vector<int>dist,int src)
{
    int n=cost.size();
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
    for(int u=0;u<n;u++)
        {
            for(int v=0;v<n;v++)
            {
                if(cost[u][v]&&dist[u]!=INT_MAX&&dist[u]+cost[u][v]<dist[v]) // shortest distance changes even after V-1 iterations,so negative cycle exists
                   return true;
            }
        }
    return false;
}
int main()
{
    /*int n=5;  // number of vertices
    vector<vector<int > >cost(n,vector<int>(n,0));
    addEdge(cost,0,1,-1);
    addEdge(cost,0,2,4);
    addEdge(cost,1,2,3);
    addEdge(cost,1,3,2);
    addEdge(cost,1,4,2);
    addEdge(cost,3,2,5);
    addEdge(cost,3,1,1);
    addEdge(cost,4,3,-3);*/

    int n=6;  // number of vertices
    vector<vector<int > >cost(n,vector<int>(n,0));
    addEdge(cost,0,1,1);
    addEdge(cost,1,2,2);
    addEdge(cost,1,4,-1);
    addEdge(cost,2,3,1);
    addEdge(cost,3,0,-1);
    addEdge(cost,4,5,-1);
    addEdge(cost,5,1,1);

    cout<<"Adjacency matrix(cost matrix):\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<bool>visited(n,false);
    vector<int>dist(n,INT_MAX); // initialize distances to other nodes from source as infinity
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(BellmanFordNegCycle(cost,visited,dist,i)) // to handle the case when the cycle is diconnected,run Bellman ford from every unvisited vertex
            {
                flag=1;
                break;
            }
            for(int i=0;i<n;i++)
            {
                if(dist[i]!=INT_MAX)
                    visited[i]=true;
            }
        }
    }
    if(flag)
        cout<<"Negative cycle exists";
    else
        cout<<"No negative cycles";
    return 0;
}
