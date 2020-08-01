#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int > >&adj,int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int minDistance(vector<vector<int > >&adj,int src,int dest)
{
    if(src==dest)
    {
        return 0;
    }
    vector<bool>visited(adj.size(),false);
    queue<int>q;
    int distance=0;
    visited[src]=true;
    q.push(src);
    while(!q.empty())
    {
        int Size=q.size();
        while(Size--)
        {
            int x=q.front();
            q.pop();
            for(int i=0;i<adj[x].size();i++)
            {
              if(adj[x][i]==dest)
              {
                  distance++;
                  return distance;
              }
              if(!visited[adj[x][i]])
              {
                visited[adj[x][i]]=1;
                q.push(adj[x][i]);
              }
            }
        }
        distance++;
    }
    return -1;
}
int main()
{
    int n=8,e=7;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,0,3);
    addEdge(adj,1,3);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    addEdge(adj,6,7);
    cout<<"Adjacency list:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    int source=5;
    int destination=0;
    int res=minDistance(adj,source,destination);
    if(res==-1)
    {
        cout<<source<<" and "<<destination<<" are unreachable";
    }
    else
    {
        cout<<"Minimum distance from "<<source<<" to "<<destination<<" is:"<<res;
    }
    return 0;
}
