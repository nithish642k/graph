#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=5;
    vector<vector<int>>edges={{0,1,5},
                              {0,3,8},
                              {1,3,9},
                              {1,2,6},
                              {3,4,7},
                              {3,2,2},
                              {4,1,5},
                              {2,4,4}};
    int src=0;
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<edges.size();i++)
    {
        int a=edges[i][0];
        int b=edges[i][1];
        int cost=edges[i][2];

        adj[a].push_back({b,cost});
        adj[b].push_back({a,cost});
    }
    vector<int>dist(n,INT_MAX);
    dist[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].first;
            int uv_cost=adj[u][i].second;
            if(dist[u]+uv_cost<dist[v])
            {
                dist[v]=dist[u]+uv_cost;
                pq.push({dist[v],v});
            }
        }
    }
    cout<<"Minimum distances from "<<src<<":"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<dist[i]<<" ";
    }
    return 0;
}
/*
To print the shortest path:
#include<bits/stdc++.h>
using namespace std;
void printPath(vector<int>&parent,int index)
{
    if(index<0)
        return;
    printPath(parent,parent[index]);
    cout<<index+1<<" ";
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n);
    int a,b,cost;
    int src=0;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>cost; a--; b--;
        adj[a].push_back({b,cost});
        adj[b].push_back({a,cost});
    }
    vector<int>parent(n,-1);
    vector<int>dist(n,INT_MAX);
    dist[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].first;
            int uv_cost=adj[u][i].second;
            if(dist[u]+uv_cost<dist[v])
            {
                parent[v]=u;
                dist[v]=dist[u]+uv_cost;
                pq.push({dist[v],v});
            }
        }
    }
    if(dist[n-1]==INT_MAX)
    {
        cout<<"-1";
    }
    else
    {
        printPath(parent,n-1);
    }
    return 0;
}
*/
