#include<stdio.h>
#include<string.h>
int main()
{
    int len,i,cnt=0;
    char s[100000],t[100000],r[100000];
    scanf("%s%s",s,t);
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]==t[i])
        {
            r[i]=s[i];
        }
        else{
            if(cnt==0)
            {
                cnt=1;
                r[i]=s[i];
            }
            else{
                cnt=0;
                r[i]=t[i];
            }
        }
    }
    if(cnt==1) printf("impossible\n");
    else{
    printf("%s\n",r);
    }
return 0;
}
