#include<iostream>

using namespace std;
long long int q,w[100000];
bool ww[10001][10001];

bool weightSum(unsigned int l,unsigned int r,unsigned int w1)
{
    long long  int n=r-l+1;
    for (int i=1; i<= w1; i++)
     {
       for (int j=1; j<= n; j++)
       {
         ww[i][j] = ww[i][j-1];
         if (i >= w[l+j-1])
           ww[i][j] = ww[i][j] || ww[i - w[l+j-1]][j-1];
       }
     }
     return ww[w1][n];
}

int main()
{
    long long int i,tmp,n,sum,dis[11],cnt=0,j,flg,arr[1024],cnt1=0;
    unsigned int op,l,r,w1;
    cin>>n>>q;
    for(i=1;i<=n;i++)
    {
        flg=0;
        cin>>w[i];
        for(j=cnt-1;j>=0;j--)
        {
            if(w[i]==dis[j]){flg=1;break;}
        }
        if(!flg)
            dis[cnt++]=w[i];
    }
    for(i=0;i<1024;i++)
    {
        sum=0;
        for(j=0;j<cnt;j++)
        {
            if((i&1<<j))
            {
                sum+=dis[j];
            }
        }
        arr[cnt++]=sum;
    }
    //ww[0][0]=true;
    for(i=0;i<=10001;i++)
    {
        ww[i][0]=false;
        ww[0][i]=true;
    }
    ww[1][0]=false;
    while(q--)
    {
        cin>>op;
        if(op==1)
        {
            cin>>l>>r;
            w[l]=r;
        }
        else if(op==2)
        {
            cin>>l>>r;
            while(l<r)
           {
               tmp=w[l];
               w[l]=w[r];
               w[r]=tmp;
               l++;r--;
           }
        }
        else {
                sum=0;flg=0;
            cin>>l>>r>>w1;
        for(i=l;i<=r;i++)
            sum+=w[i];
            if ((weightSum(l,r,w1) == true  && sum>w1)|| sum==w1|| )
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }

           }


return 0;
}
