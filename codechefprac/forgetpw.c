#include<stdio.h>
#include<String.h>
int main()
{
    int i,t,n,len,flag,flag1,l,u;
    char c,p,a[126],s[1000000];
    scanf("%d",&t);
    while(t--)
    {
        for(i=32;i<126;i++)
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf(" %c %c",&c,&p);
            a[c]=p;
           // printf("c[i]-%c,p[i]-%c\n",a[c],c);
        }
        scanf("%s",s);
        len=strlen(s);
        l=u=flag=flag1=0;
        for(i=0;i<len;i++)
        {
            s[i]=a[s[i]];
            if((s[i]=='0' && flag==0)||(s[i]=='0' && flag1==0))
            {
                if(flag==0)
                l=i;
                else
                u=i;
            }
            else if(s[i]=='.')
            {
                if(l==i-1) {l=i;flag=1;}
                u=i;
            }
            else{
                if(flag==0) flag=1;

            }

        }
    }
    return 0;
}
