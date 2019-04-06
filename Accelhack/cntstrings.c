#include<stdio.h>
#include<string.h>
int main()
{
int t,n,k,i,j,maxx,flag,pos;
char c[50000];
//scanf("%c%c",c,d);
//printf("%c,%c",c,d);
int a[27];
scanf("%d",&t);
while(t--)
{
    maxx=flag=0;
    for(i=0;i<27;i++)
    {
        a[i]=0;
    }
scanf("%d%d",&n,&k);
scanf("%s",c);
for(i=0;i<n;i++){
a[((int)c[i])-97]+=1;
}
for(i=0;i<27;i++){
        maxx=0;
for(j=0;j<27;j++){
if(maxx<a[j]){
    maxx=a[j];
    pos=j;
}
}
if(maxx>k){
    printf("%c",(char)(pos+97));
    flag=1;
    a[pos]=0;
}
else{
    break;
}
}
if(flag==0)
    printf("NONE\n");
else printf("\n");
}
return 0;
}
