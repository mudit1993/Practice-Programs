#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int dist[100001],flag[100001],c_flag;
vector<vector<int> >a(100000);
queue<int> q;
void bfs(int n,int r)
{
    int d=1,cnt=0;  //  distance from the new festive city
q.push(r);
dist[r]=0;
while(!q.empty())
        {

       int f=q.front();
       q.pop();
       cnt=0;
            for(vector<int>:: iterator it=a[f].begin();it!=a[f].end();++it)
            {
            if(flag[*it]!=c_flag)
                {
                flag[*it]=c_flag;
                if(dist[*it]>d)
                {
                    cnt++;
                    q.push(*it);
                    dist[*it]=d;
                }
            }
        }
        cout<<"cnt"<<cnt<<" d="<<d;
        if(!cnt--)
        d++;
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
  /*  for(int j=1;j<=n;j++)
        cout<<dist[j]<<" ";
    cout<<endl;
}
/*for(i=1;i<=n;i++)
{
    for(it=a[i].begin();it!=a[i].end();++it)
    {
        cout<<*it<<" ";
    }
    cout<<"\n";
}*/

return 0;
}
