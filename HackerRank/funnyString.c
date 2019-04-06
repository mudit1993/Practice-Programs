#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int t,i,lens,flag;
    char s[10001];
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        scanf("%s",s);
        lens=strlen(s);
        for(i=1;i<lens;i++)
        {
            if(abs(s[i]-s[i-1])!=abs(s[lens-i]-s[lens-i-1]))
            {
                flag=1;break;
            }
        }
        if(flag==0)
            printf("Funny\n");
        else
            printf("Not Funny\n");
    }
    return 0;
}
