/*
MST-Minimum spanning tree is the spanning tree where the cost is minimum among all the spanning trees.
   -has only V-1 edges

Prim's algorithm-algorithm that finds a MST for weighted undirected graph
finds the MST with the total weight of all the edges in the tree minimized

Note:A disconnected graph does not have MST

idea:
Pick the edge with the lowest cost,add it to MST
find the next edge with lowest cost but the edge should be attached to the MST
repeat until all the vertices are connected

Time Complexity:O(V^3)
*/
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int > >&adj,int u,int v,int cost)
{
    adj[u][v]=cost;
    adj[v][u]=cost;
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
    inMST[0]=true;

    int noOfEdgesAdded=0,costOfMST=0;

    while(noOfEdgesAdded<n-1) //since MST must have edges equal to V-1
    {
        int min_cost=INT_MAX;
        int u=-1,v=-1;
        for(int i=0;i<n;i++)
        {
            if(inMST[i])
            {
                for(int j=0;j<n;j++)
                {
                    if(!inMST[j]&&cost[i][j]) // check for edge existence
                    {
                        if(cost[i][j]<min_cost)
                        {
                            min_cost=cost[i][j];
                            u=i;
                            v=j;
                        }
                    }
                }
            }
        }
        if(u!=-1&&v!=-1)
        {
            cout<<"("<<u<<","<<v<<","<<min_cost<<")";
            cout<<endl;
            inMST[v]=true;
            noOfEdgesAdded++;
            costOfMST+=min_cost;
        }
        else
        {
            cout<<"MST not possible";  // graph may be diconnected,MST not possible
            break;
        }
    }
    cout<<"Cost of MST:"<<costOfMST;

    return 0;
}
