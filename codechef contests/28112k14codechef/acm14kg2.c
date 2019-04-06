#include<stdio.h>
int main()
{
    int t,n,a,m,temp;
    scanf("%d",&t);
    //int arr[t];
    int i=0;
    while(t!=0)
    {
        scanf("%d%d%d",&n,&a,&m);
    temp=(m%n)+a;//arr[i]=(m%n)+a;
    if(temp>n)
       printf("%d\n",temp%n);// arr[i]=arr[i]%n;
        else printf("%d\n",temp);
        i++;
        t--;
    }
//for(t=0;t<i;t++)
  // printf("%d\n",arr[t]);
    return 0;
}
