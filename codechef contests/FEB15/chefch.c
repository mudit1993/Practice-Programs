#include<stdio.h>
#include<string.h>
int main()
{
int t,len,i,pos,neg;
scanf("%d",&t);
char a[100000];
while(t--)
{
    pos=neg=0;
scanf("%s",a);
len=strlen(a);
//printf("hey-%s",a);
for(i=0;i<len;i++)
{
    if(i%2==0)//even positions
    {
        if(a[i]=='+')
        neg++;
        else
        pos++;
    }
    else{           //odd positions
         if(a[i]=='-')
        neg++;
        else
        pos++;
    }
}
//printf("neg-%d,pos-%d",neg,pos);
if(pos<neg)
    printf("%d\n",pos);
else printf("%d\n",neg);
}
return 0;
}
