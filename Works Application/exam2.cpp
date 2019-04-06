#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int dist[100001],flag[100001],c_flag;
vector<vector<int> >a(100000);
queue<int> q;
queue<int> dis;
void bfs(int n,int r)
{
    vector<int>:: iterator it;
q.push(r);
dis.push(0);
dist[r]=0;          // festive city
while(!q.empty())
    {
       int f=q.front();
       int d1=dis.front();
       dis.pop();
       q.pop();
            for(it=a[f].begin();it!=a[f].end();++it) // pushing all the connected cities
            {
            if(flag[*it]!=c_flag)
                {
                flag[*it]=c_flag;
                if(dist[*it]>d1)   //   minimizing the distance from the festive city
                {
                    q.push(*it);
                    dis.push(d1+1);// queue to maintain distance from the new festive city
                    dist[*it]=d1+1;
                }
            }
        }
    }
}
int main()
{
int n,m,i,x,y,g,h;
vector<int>:: iterator it;
cin>>n>>m;
for(i=0;i<=n;i++)
   {
        a[i].clear();
        dist[i]=100001;
        flag[i]=0;
   }
   dist[1]=0;
for(i=0;i<n-1;i++)
{
cin>>x>>y;
a[x].push_back(y);
a[y].push_back(x);
}
c_flag=1;
bfs(n,1);
for(i=1;i<=m;i++)
{
    cin>>g>>h;
    if(g==2)
        cout<<dist[h]<<endl;
    else
    {
        c_flag++;
        bfs(n,h);
    }
}
return 0;
}
