/*
 A negative cycle is one in which the overall sum of the cycle comes negative.
 Negative weights are found in various applications of graphs.
 For example, instead of paying cost for a path, we may get some advantage if we follow the path.

 Time complexity: O(V^3)
*/
#include<bits/stdc++.h>
#define INF 9999
using namespace std;
int main()
{
    //0->no self edge INF->no direct edge
    /*int n=4;
    vector<vector<int>>cost={{0,1,INF,INF},
                            {INF,0,-1,INF},
                            {INF,INF,0,-1},
                            {-1,INF,INF,0}};*/
    /*int n=4;
    vector<vector<int>>cost={{0,-5,INF,INF},
                            {INF,0,-3,INF},
                            {INF,INF,0,-1},
                            {10,INF,INF,0}};*/

   int n=6;
    vector<vector<int>>cost={{0,1,INF,INF,INF,INF},
                            {INF,0,2,INF,-1,INF},
                            {INF,INF,0,1,INF,INF},
                            {-1,INF,INF,0,INF,INF},
                            {INF,INF,INF,INF,0,-1},
                            {INF,1,INF,INF,INF,0}};

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
	    int flag=0;
        for(int i=0;i<n;i++)
        {
            if(dist[i][i]<0)
            {
                cout<<i<<" ";
                flag=1;
            }
        }
        if(!flag)
            cout<<"No negative cycles";
    return 0;
}

