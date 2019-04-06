#include<stdio.h>
#include<string.h>
int main()
{
int t,n,i,d[126],len,f,x,y,j;
char c,p,s[1000000];
scanf("%d",&t);
while(t--)
{
    f=0;
 scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf(" %c %c",&c,&p);
            d[(int)c]=p;
        }
         scanf("%s",s);
       //  printf("%s\n",s);
        len=strlen(s);
    for(i=0;i<len;i++)
    {
       if((d[(int)s[i]]>='0' && d[(int)s[i]]<='9') ||d[(int)s[i]]=='.')
        s[i]=d[(int)s[i]];
        if(s[i]=='.') f=1;
    }
    x=0;y=len-1;
    while(s[x]=='0')
    {
        x++;
    }
    if(f==1)
    {

        while(s[y]=='0') y--;
    }
  //  printf("hey");
    if(s[y]=='.') y--;
    if(x<=y){
    for(i=x;i<=y;i++)
        printf("%c",s[i]);
    }
    else printf("0");
    printf("\n");
}
return 0;
}
