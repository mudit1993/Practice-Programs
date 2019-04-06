#include<stdio.h>
int a[10][100001];
int main()
{
    char ch,s[100001];
    int j,no;
    int i,len,x,pos,sum;
    scanf("%d%d",&len,&x);
    for(i=0;i<10;i++) a[i][0]=0;
    for(i=1;i<=len;i++)
    {
        scanf(" %c",&s[i]);
       //s[i]=(int)ch-48;
        for(j=0;j<10;j++)
        {
            a[j][i]=a[j][i-1];
        }
        a[(int)s[i]-48][i]++;
    }
     while(x--)
    {
        sum=0;
        scanf("%d",&pos);
        no=(int)s[pos]-48;
        for(i=0;i<=no;i++)
        {
            sum+=a[i][pos]*(no-i);
        }
        for(i=no+1;i<10;i++)
        {
            sum+=a[i][pos]*(i-no);
        }
        printf("%d\n",sum);
    }
  //  for(i=1;i<=len;i++)
  // printf("%d",s[i]);
return 0;
}
