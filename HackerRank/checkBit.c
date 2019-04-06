#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
int cnt=0,i,n,m,maxx=0,j,k,team=0;
   char d[500][500];
   scanf("%d%d",&n,&m);
   for(i=0;i<n;i++)
   {
       scanf("%s",d[i]);
   }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            cnt=0;
            for(k=0;k<m;k++)
            {
                if((d[i][k]|d[j][k])=='1')
                {
                    cnt++;
                }
            }
            if(cnt==maxx) team++;
            else if(cnt>maxx)
            {
                maxx=cnt;
                team=1;
            }
        }
    }
   printf("%d\n%d\n",maxx,team);

   return 0;
}
