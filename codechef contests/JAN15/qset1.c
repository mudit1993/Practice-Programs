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
int main()
{
int n,m,i,type,ch,pos,c,d,diff,j,k,cnt,f,res;
char a[100000];//sub[100000];
//scanf("%d%d",&n,&m);
scan(&n);
scan(&m);
scanf("%s",&a);
//for(i=0;i<n;i++)
//printf("%c",a[i]);
while(m--)
{
scanf("%d",&type);
if(type==1)
{
scanf("%d",&pos);
scanf("%d",&ch);
a[pos-1]=(char)(ch+48);
//for(i=0;i<n;i++)
//printf("%c",a[i]);
}
else if(type==2)
{cnt=0;
scanf("%d%d",&c,&d);
diff=d-c+1;
f=1;
while(f<=diff)
{
    for(i=c-1;(i+f)<=d;i++)
    {k=0;res=0;char sub[f+1];
        for(j=i;j<(i+f);j++)
        {
            sub[k++]=a[j];
        }
       // for(j=0;j<k; j++)
        //res=(res*10)+(sub[j]-'0');
       res=atoi(sub);
      //  printf("res-%d  ",res);
        if(res%3==0)cnt++;
    }
f++;
}
printf("%d\n",cnt);
}
}
return 0;
}
