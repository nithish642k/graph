/* Note:

consider the graph 0-1 having adjacency list( 0->1  1->0)
this graph may look like it has a cycle,but it doesn't since 0 is from where 1 came from(O is the parent of 1)
So,we need to handle this case

if(neighbor is the parent)
    not a cycle

When there is a cycle?

start DFS
mark visited the nodes as you go
if(neighbor is not the parent&&the node is already visited)
    cycle exist

*/
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int > >&adj,int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool DFS(vector<vector<int > >adj,vector<bool>&visited,int x,int parent)
{
    visited[x]=true;
    for(int i=0;i<adj[x].size();i++)
    {
        if(!visited[adj[x][i]])
        {
            if(DFS(adj,visited,adj[x][i],x))  // this if is important for the code to work
                return true;
        }
        else if(adj[x][i]!=parent) // already visited and not parent
        {
            return true;
        }
    }
    return false;
}
bool graphHasCycle(vector<vector<int > >adj,vector<bool>visited)
{
    for(int i=0;i<adj.size();i++)
    {
        if(!visited[i])
        {
            if(DFS(adj,visited,i,-1))
                return true;
        }
    }
  return false;
}
int main()
{
    /*int n=3,e=2;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);*/

    /*int n=3,e=3;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,0);*/

    /*int n=4,e=4;
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,1);*/

    int n=5,e=4;  // disconnected graph
    vector<vector<int > >adj(n,vector<int>());
    addEdge(adj,0,1);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,2);

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

    if(graphHasCycle(adj,visited))
        cout<<"Cycle exists";
    else
        cout<<"No cycles";

    return 0;
}
