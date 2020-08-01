/*
to find shortest distances between every pair of vertices in a given edge weighted directed Graph.
Algorithm:
We initialize the solution matrix same as the input graph matrix as a first step.
Then we update the solution matrix by considering all vertices as an intermediate vertex.
The idea is to one by one pick all vertices and updates all shortest paths which include
the picked vertex as an intermediate vertex in the shortest path.

Time Complexity:O(V^3)
*/#include<bits/stdc++.h>
#define INF 9999
using namespace std;
int main()
{
    //0->no self edge INF->no direct edge
     int n=4;
    vector<vector<int>>cost={{0,5,INF,10},
                            {INF,0,3,INF},
                            {INF,INF,0,1},
                            {INF,INF,INF,0}};
    vector<vector<int>>dist(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dist[i][j]=cost[i][j];
        }
    }
        for(int k=0;k<n;k++)// k->intermediate vertex,After the end of an iteration,vertex k is added to the set of intermediate vertices
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]); // if going from i to j through k is shorter,update the shortest distance
	            }
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(dist[i][j]==9999)
	             cout<<"INF"<<"\t";
	             else
	             cout<<dist[i][j]<<"\t";
	        }
	        cout<<endl;
	    }
    return 0;
}
