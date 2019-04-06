#include<stdio.h>
int main()
{
int t,n,a[3][100000],veh,one=0,two=0,thr=0,x,y,flag=0,i;
scanf("%d%d",&n,&t);
for(i=0;i<n;i++)
{
    scanf("%d",&veh);
    switch(veh)
    {
        case 1: a[veh-1][one++]=i;
                break;
        case 2: a[veh-1][two++]=i;
                break;
        case 3: a[veh-1][thr++]=i;
               // break;
    }
}
while(t--)
{
    flag=0;
    scanf("%d%d",&x,&y);
    for(i=0;i<one;i++){
        if(a[0][i]>=x && a[0][i]<=y){
            printf("1\n");
            flag=-1;
        }
    }
    for(i=0;i<two&&flag!=-1;i++)
    {
        if(a[1][i]>=x && a[1][i]<=y){
            printf("2\n");
            flag=-1;
        }
    }
    for(i=0;i<thr&&flag!=-1;i++)
    {
        if(a[2][i]>=x && a[2][i]<=y){
            printf("3\n");
            flag=-1;
        }
    }
}
return 0;
}
