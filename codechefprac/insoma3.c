#include<stdio.h>
int main()
{
    int i,j,a[100000],flag=0,maxx=0,cnt=0,pos=0,n;
    scanf("%d",&n);
    scanf("%d",&a[0]);
    for(i=1;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[pos]<a[i] && flag==0)
        {
            pos=i;
        }
        else flag=1;
    }
   // maxx=a[pos];
 //  printf("%d ",pos);
   if(n>1){
    for(i=pos;i<n;i++)
    {
        maxx=a[i];
        j=i-1;
        while(maxx<a[j]&&j>=0)
        {
            cnt++;
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=maxx;
        /*if(a[i]>maxx){maxx=a[i];continue;}
        else
        {
            for(j=0;j<i;j++)
            {
                if(a[j]>a[i]) cnt++;
            }
        }*/
    }
   }
   printf("%d\n",cnt);

return 0;
}
