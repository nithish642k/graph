#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int > >&adj,int u,int v)
{
    adj[u].push_back(v);
}
void fillOrder(vector<vector<int > >adj,vector<bool>&visited,int x,stack<int>&s)
{
    visited[x]=true;
    for(int i=0;i<adj[x].size();i++)
    {
        if(!visited[adj[x][i]])
        {
            fillOrder(adj,visited,adj[x][i],s);
        }
    }
    s.push(x);  // store vertices in stack according to their finishing time
}
void DFS(vector<vector<int > >adj,vector<bool>&visited,int x)
{
    visited[x]=true;
    cout<<x<<" ";
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
    int n=5,e=5;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,2);
    addEdge(adj,2,1);
    addEdge(adj,1,0);
    addEdge(adj,0,3);
    addEdge(adj,3,4);
    /*
    int n=3,e=5;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,0);
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,0);
    addEdge(adj,2,2);
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
    vector<bool>visited(n,false);

    stack<int>s;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
            fillOrder(adj,visited,i,s);
    }

    vector<vector<int > >radj(n,vector<int>());
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            radj[adj[i][j]].push_back(i);      // reversing the edges
        }
    }

    for(int i=0;i<n;i++)
        visited[i]=false;    // reinitialize the visited array for second DFS

    cout<<"SCCs:\n";
    int scc=0;
    while(!s.empty())
    {
        int x=s.top();
        s.pop();
        if(!visited[x])
        {
            DFS(radj,visited,x);  // run second DFS on reversed graph
            scc++;
            cout<<endl;
        }
    }
    cout<<"Number of SCCs:"<<scc;
    return 0;
}
/*

Kosaraju's algorithm:
1)Run DFS,store vertices in stack according to their finishing time
2)reverse the edges to get the transposed graph T(G)
3)while stack is not empty,do:
    get TOS
    if(TOS is not visited)
        run DFS on T(G) from TOS
    pop TOS

(each DFS will give a strongly connected component)

Time Complexity:O(V+E)
*/
