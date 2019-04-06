#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k=1,l=1,x,coun=0;
        cin>>n>>m;
        int *a=new int[n+1]();
        int i;
        for(i=0;i<m;i++)
        {
            cin>>x;
            a[x]=1;
        }

        while(coun<n-m)
        {
            if(k>n||l>n) break;
            while((a[k]==1||a[k]==2||a[k]==3)&&k<=n)
            {
                k++;
            }

            a[k]=2;
            coun++;
            while((a[l]==1||a[l]==2||a[l]==3)&&l<=n)
            {
                l++;
            }
            a[l]=3;
            coun++;
        }

            for(i=1;i<=n;i++)
            {
                if(a[i]==2)
                {
                    cout<<i<<" ";
                }
            }
            cout<<endl;
            for(i=1;i<=n;i++)
            {
                if(a[i]==3)
                {
                   cout<<i<<" ";
                }
            }
            cout<<endl;
          //  i=1;
        //while(i<=n) {cout<<a[i]; i++;}
        delete []a;

    }
    return 0;
}
