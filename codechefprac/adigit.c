#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char ch;
    int s[100001],a[10][10],j;
    int i,len,x,pos,sum;
    scanf("%d%d",&len,&x);
    for(i=1;i<=len;i++)
    {
        scanf(" %c",&ch);
        s[i]=(int)ch-48;
    }
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
        a[i][j]=abs(j-i);
    while(x--)
    {
        sum=0;
        scanf("%d",&pos);
        for(i=1;i<pos;i++)
        {
            sum+=(a[s[pos]][s[i]]);
            //(abs(s[pos]-s[i]));
        }
        printf("%d\n",sum);
    }
  //  for(i=1;i<=len;i++)
  // printf("%d",s[i]);
return 0;
}
