#include<stdio.h>
#include<string.h>
int main()
{
    int no[101],n,i,res[1001],temp;
    char s[101];
    int flag=0,j,k,f=0;
for(i=0;i<=1000;i++)
    {
        if(i%8==0)
            res[i]=1;
        else res[i]=0;
    }
        res[6]=res[2]=res[4]=1;
    for(i=12;i<100;i+=8)
    {
        res[i]=2;
    }
    scanf("%s",s);
    printf("hi");
    n=strlen(s);
    for(i=0;i<n;i++)
    {
        no[i]=(int)(s[i])-48;
       // printf("%d",no[i]);
       if(no[i]==0){
        flag=1;
       }
    }

    if(flag==0){
for(i=n-1;i>=0;i--)
{
if(no[i]==8){
    printf("YES\n%d\n",no[i]);
    return 0 ;
}
else if(res[no[i]]==1){
break;
}
f=2;
}
for(k=i-1;k>=0 && i>=1;k--)
{
    temp=(no[k]*10)+no[i];
//printf("%d,",temp);
if(res[temp]==1){
    printf("YES\n%d\n",temp);
    return 0;
}
else{
        if(res[temp]==2) break;
    f=2;
}
}
for(j=k-1;j>=0 && k>=1;j--)
{
    temp=(no[j]*100)+temp;
//printf("%d,",temp);
if(res[temp]==1){
    printf("YES\n%d\n",temp);
    return 0;
}
else{
   // printf("sfb");
f=1;
}
}

}
else{
    printf("YES\n0\n");
}

if(f==1||f==2)
   {printf("NO\n");}
    else if(n==2)
    {
       // printf("%d",temp);
        if(res[temp]!=1)
            printf("NO\n");
    }
    else if(n==1 && (no[0]!=8 && no[0]!=0)) { printf("NO\n");}
return 0;
}
