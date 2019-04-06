#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int t,i,l,cnt;
    char s[10001];
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        scanf("%s",s);
        l=strlen(s);
        for(i=0;i<l/2;i++)
        {
            cnt+=abs(s[i]-s[l-1-i]);
        }
        printf("%d\n",cnt);
    }
      return 0;
}
