#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() {

   int n,i,len,j,cnt=0;
   int rock[101][27];
   char s[101];
    scanf("%d",&n);
    for(i=0;i<=n;i++)
        for(j=0;j<27;j++)
        rock[i][j]=0;
    for(j=0;j<n;j++)
    {
        scanf("%s",s);
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(rock[j][s[i]-97]==0)
            {
                rock[j][s[i]-97]=1;
                rock[n][s[i]-97]++;
            }
        }
    }
    for(i=0;i<27;i++)
    {
        if(rock[n][i]==n) cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
