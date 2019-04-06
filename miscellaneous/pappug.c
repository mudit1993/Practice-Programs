#include<stdio.h>
#include<string.h>

int main()
{
char s[10000],word[100];
int t,i,j,q,s1,k,l,k1,cnt=0,n,l1,m,q1=0;
scanf("%d",&t);
int arr[t+1];
for(i=0;i<t;i++)
{
scanf("%s",s);
scanf("%d",&q);
int r[q+1];
q1+=q;
for(j=0;j<q;j++)
{
     r[j]=0;
    n=0;
scanf("%s",word);
s1=strlen(s);
for(k=0;k<s1;k++)
{
    k1=k;
cnt=0;
if(word[0]==s[k1])
{
    l1=strlen(word);
for(l=0;l<l1;l++)
{
if(word[l]==s[k1])
{
cnt++;
k1++;
}
else break;
}
if(cnt==l1)
{
    n++;
    r[j]=n;
}
}
}
}
for(m=0;m<q;m++)
    printf("%d\n",r[m]);
}
return 0;
}
