#include<stdio.h>
#include<string.h>
int main()
{
int n,i,ch[27];
long long int sum=0,ch1[27];
char a[1000000];
for(i=0;i<26;i++)
   {

 ch[i]=ch1[i]=0;}
scanf("%d",&n);
scanf("%s",a);
for(i=0;i<n;i++)
{
ch[a[i]-97]++;
ch1[a[i]-97]+=ch[a[i]-97];
}
for(i=0;i<27;i++)
{
sum+=ch1[i];
}
printf("%lld\n",sum);
return 0;
}
