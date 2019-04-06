#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int scan(int *no)
{
        int n=0;
        register int ch=getchar();
        for(;ch>47&&ch<58;ch=getchar())
        {
                n=(n<<1)+(n<<3)+ch-48;
        }
        *no=n;
}
inline void sscan(char *st)
{
    register int i=0;
    register char c=0;
      while(c<33)
       c=getchar();
  while (c!='\n') {
       st[i]=c;
       c=getchar();
      i=i+1;
   }
    st[i]='\0';
}

int main()
{
int n,m,i,type,ch,pos,c,d,diff,j,cnt,f,res;
char a[100000];//sub[100000];
//scanf("%d%d",&n,&m);
scan(&n);
scan(&m);
sscan(&a);
//for(i=0;i<n;i++)
//printf("%c",a[i]);
while(m--)
{
scan(&type);
if(type==1)
{
scan(&pos);
scan(&ch);
a[pos-1]=(char)(ch+48);
//for(i=0;i<n;i++)
//printf("%c",a[i]);
}
else if(type==2)
{cnt=0;
scan(&c);
scan(&d);
diff=d-c+1;
f=1;
while(f<=diff)
{
    for(i=c-1;(i+f)<=d;i++)
    {
        res=0;
        for(j=i;j<(i+f);j++)
        {
            res=(res*10)+(a[j]-'0');
        }
          if(res%3==0)cnt++;
    }
f++;
}
printf("%d\n",cnt);
}
}
return 0;
}
