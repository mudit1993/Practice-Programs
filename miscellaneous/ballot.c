#include<stdio.h>
int main()
{
int t,i,k,f,j,l;
long c,c1;
scanf("%d",&t);
int arr[t];
int a[10];
for(j=0;j<t;i++)
{
    scanf("%d%ld%d%d",&k,&c,&i,&f);
    c1=0;
    for(l=0;l<k;l++)
    scanf("%d",&a[l]);
    l=0;
    while(i<f)
    {
        i*=a[l];
        i=i%10000;
        c1+=c;
        l++;
    }
    if(i==f)
    printf("%d\n",c1);
    else printf("-1\n");

}
return 0;
}
