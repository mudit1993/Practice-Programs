#include<stdio.h>
#include<string.h>
int main()
{
     int q,len,i,sum,a1,l,r;
     char s[1000000],a,b;
    scanf("%s",&s);
    len=strlen(s);
    scanf("%d",&q);
    while(q--)
    {
       a1=i=sum=0;
    scanf(" %c %c %d%d",&a,&b,&l,&r);
      l--;r--;
      i=l;
      while(s[i]!=a && i<=r){i++;}
    for(;i<=r;i++)
    {
        if(s[i]==a)
        {
            a1++;continue;
        }
        else if(s[i]==b)
        {
            sum+=a1;
        }
    }
printf("%d\n",sum);
    }
return 0;
}
