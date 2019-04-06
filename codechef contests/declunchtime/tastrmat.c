#include<stdio.h>
int main()
{
char a[100000],b[5];
int c[99997];
int i,k,j,cnt;
scanf("%s",a);
scanf("%d",&k);
while(k--)
{
        scanf("%s",b);
    for(i=0;i<((int)strlen(a)-(int)strlen(b)+1);i++)
    {cnt=0;
        for(j=i;j<(i+(int)strlen(b));j++)
        {
            if(a[j]!=b[j]) cnt++;
        }
        c[i]=cnt;
    }
for(i=0;i<(int)strlen(c);i++)
   printf("%d",c[i]);
}
//for(i=0;i<strlen(a);i++)
  //  printf("%c",a[i]);
return 0;
}
