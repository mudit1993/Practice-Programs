#include<stdio.h>
#include<string.h>
int main()
{
    int len,i,cnt=0;
    char s[100001],t[100001];
    char c[100001];
    scanf("%s%s",s,t);
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]!=t[i])
        {
            if(cnt&1)
                c[i]=s[i];
            else
                c[i]=t[i];
            cnt++;
        }
        else{
            c[i]=s[i];
        }
    }
    if(cnt&1) printf("impossible\n");
    else{
        for(i=0;i<len;i++)
    printf("%c",c[i]);
    printf("\n");
    }
return 0;
}
