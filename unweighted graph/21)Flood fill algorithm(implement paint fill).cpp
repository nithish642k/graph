/*
In MS-Paint, when we take the brush to a pixel and click, the color of the region of that pixel is replaced with a new selected color.
Following is the problem statement to do this task.
Given a 2D screen, location of a pixel in the screen and a color,
replace color of the given pixel and all adjacent same colored pixels with the given color.
*/
#include<bits/stdc++.h>
using namespace std;
void floodFill(vector<vector<int>>&screen,int m,int n,int x,int y,int oldColor,int newColor)
{
    if(x<0||x>=m||y<0||y>=n)
        return;
    if(screen[x][y]==newColor)
        return;
    if(screen[x][y]!=oldColor)
        return;
    screen[x][y]=newColor;
    floodFill(screen,m,n,x+1,y,oldColor,newColor);
    floodFill(screen,m,n,x-1,y,oldColor,newColor);
    floodFill(screen,m,n,x,y+1,oldColor,newColor);
    floodFill(screen,m,n,x,y-1,oldColor,newColor);
}
int main()
{
    int m=8,n=8;
    vector<vector<int>>screen={{1, 1, 1, 1, 1, 1, 1, 1},
                               {1, 1, 1, 1, 1, 1, 0, 0},
                               {1, 0, 0, 1, 1, 0, 1, 1},
                               {1, 2, 2, 2, 2, 0, 1, 0},
                               {1, 1, 1, 2, 2, 0, 1, 0},
                               {1, 1, 1, 2, 2, 2, 2, 0},
                               {1, 1, 1, 1, 1, 2, 1, 1},
                               {1, 1, 1, 1, 1, 2, 2, 1}};

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<screen[i][j]<<" ";
        }
        cout<<endl;
    }
    int x=4,y=4; // location of the pixel to click
    int newColor=3;


    int oldColor=screen[x][y];

    floodFill(screen,m,n,x,y,oldColor,newColor);
    cout<<"Screen after filling:\n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<screen[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
