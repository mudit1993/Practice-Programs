#include<stdio.h>
int main()
{
    int n,x,y,i,cnt=0;
    int a[100000],b[100000];
    scanf("%d%d%d",&n,&x,&y);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    for(i=0;i<n;i++)
    {
        if(a[i]>b[i] && x>0)
        {
            cnt+=a[i];
            x--;
        }
        else if(b[i]>a[i] && y>0)
        {
            cnt+=b[i];
            y--;
        }
    }
    for(i=0;i<n;i++)
    {
        if(a[i]==b[i] && (x>0||y>0)) cnt+=a[i];
    }
    printf("%d\n",cnt);
return 0;
}
