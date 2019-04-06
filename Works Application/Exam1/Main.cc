#include<iostream>
using namespace std;
typedef long long int lli;


int grid[501][501],visited[501][501];
lli maxx=-1;
int n,m;
int yy[]={0,1,0};  // traverse right  -- columns
int xx[] = {1,0,-1}; // traverse  vertically  --  rows

void max_Sum(lli sum , int x, int y)
{
    if(maxx<sum && y==m-1)
    {
        maxx=sum; // reached the right end
    }
    for(int i=0; i < 3; i++)
    {
        int flag=0;
        int x1 = x + xx[i];  // moving vertical
        int y1 = y + yy[i];   // horizontal
       //cout<< x1 << " "<< y1<<" "<<i<< " sum="<<sum<<endl;
        if(x1==n)
        {
            flag=1;
            x1 = 0;//  teleport  to the top
        }
        if(x1==-1)
        {
            flag=1;
            x1=n-1;  // teleport to the bottom
        }
        if(y1==m){continue;}
        if(grid[x1][y1]==-1 || visited[x1][y1] ) continue;
        visited[x1][y1]=1;   // visited
        if(!flag)
            max_Sum(sum+grid[x1][y1],x1,y1);
        else
            max_Sum(0,x1,y1);// teleported
        visited[x1][y1]=0;   // backtracking
    }

}

int main()
{

    int i,j;
    cin>>n>>m;  //rows,columns
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            cin>>grid[i][j];
            visited[i][j]=0;// initializing visited array
        }
    for(j=0;j<m-1;j++)
    {
        for(i=0;i<n;i++)
        {
            if(grid[i][j]==-1) continue ;
            visited[i][j]=1;
            max_Sum(grid[i][j],i,j);
            visited[i][j]=0;
        }
    }
    if(m==1)
    {
        for(i=0;i<n;i++)
        {
            if(grid[i][0]==-1) continue ;
            visited[i][0]=1;
            max_Sum(grid[i][0],i,0);
            visited[i][0]=0;
        }
    }
     cout<<maxx<<endl;
    return 0;
}
