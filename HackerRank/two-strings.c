#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int i,t,a[27],len;
    char s[100000];
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<27;i++)
            a[i]=0;
        scanf("%s",s);
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            a[s[i]-97]++;
        }
        scanf("%s",s);
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(a[s[i]-97]>0)
                break;
        }
        if(i<len)
            printf("YES\n");
        else printf("NO\n");
    }
     return 0;
}
