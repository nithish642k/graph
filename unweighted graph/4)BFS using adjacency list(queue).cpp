/* BFS of an undirected graph using adjacency matrix*/
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int > >&adj,int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    int n=6,e=6;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,0,3);
    addEdge(adj,1,3);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    // addEdge(6,7);
    cout<<"Adjacency list:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    int start=0;
    vector<bool>visited(n,false);
    queue<int>q;

    visited[start]=true;
    cout<<"BFS:";
    q.push(start);

    while(!q.empty())
    {
        int x=q.front();
        cout<<x<<" ";
        for(int i=0;i<adj[x].size();i++)
        {
            if(!visited[adj[x][i]])
            {
                visited[adj[x][i]]=1;
                q.push(adj[x][i]);
            }
        }
        q.pop();
    }
    return 0;
}

/*
To handle disconnected graph,,Perform BFS from each unvisited vertex:
for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            visited[i]=true;
            q.push(i);
            while(!q.empty())
            {
                 int x=q.front();
                 cout<<x<<" ";
                for(int i=0;i<adj[x].size();i++)
                {
                    if(!visited[adj[x][i]])
                     {
                        visited[adj[x][i]]=1;
                        q.push(adj[x][i]);
                     }
                }
             q.pop();
            }
        }
    }



*/
