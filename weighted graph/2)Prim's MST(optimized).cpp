#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int > >&adj,int u,int v,int cost)
{
    adj[u][v]=cost;
    adj[v][u]=cost;
}
int getMinKeyVertex(vector<vector<int>> &cost,vector<bool>&inMST,vector<int>&key)
{
    int n=cost.size();
    int min=INT_MAX,minIndex;
    for(int i=0;i<n;i++)
    {
        if(!inMST[i]&&key[i]<min)
        {
            min=key[i];
            minIndex=i;
        }
    }
    return minIndex;
}
int main()
{
    int n=5;  // number of vertices
    cout<<"Adjacency matrix(cost matrix):\n";
    vector<vector<int > >cost(n,vector<int>(n,0));
    addEdge(cost,0,1,2);
    addEdge(cost,1,2,3);
    addEdge(cost,0,3,6);
    addEdge(cost,1,3,8);
    addEdge(cost,1,4,5);
    addEdge(cost,2,4,7);
    addEdge(cost,3,4,9);
    //addEdge(cost,6,7,6);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"MST:\n";
    vector<bool>inMST(n,false);
    vector<int>key(n,INT_MAX);
    vector<int>parent(n);
    int edgesAdded=0,total_cost=0;
    key[0]=1; // so that first vertex is always picked as the root vertex of MST
    parent[0]=-1;
    while(edgesAdded<n-1)
    {
        int u=getMinKeyVertex(cost,inMST,key);
        inMST[u]=true;
        for(int v=0;v<n;v++)
        {
            if(cost[u][v]&&!inMST[v]&&cost[u][v]<key[v])
            {
                key[v]=cost[u][v];
                parent[v]=u;
            }
        }
        edgesAdded++;
    }
    for(int i=1;i<n;i++)
    {
        total_cost+=cost[i][parent[i]];
    }
    for(int i=1;i<n;i++)
    {
        cout<<"("<<parent[i]<<","<<i<<","<<cost[parent[i]][i]<<")"<<endl;
    }
    cout<<"MST cost:"<<total_cost;
    return 0;
}
