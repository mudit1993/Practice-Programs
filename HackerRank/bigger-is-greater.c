#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() {

   int t,len,i,j,f,posi,posj,m,k;
   char w[101],temp;
   scanf("%d",&t);
   while(t--)
   {
       posi=0;f=posj=0;
       scanf("%s",w);
       len=strlen(w);
        for(i=0;i<len-1;i++)
        {
            if(w[i]<w[i+1]){
                posi=i;f=1;
            }
        }
        if(f==1){
        for(j=posi;j<len;j++)
        {
            if(w[posi]<w[j]){
                posj=j;
            }
        }
        temp=w[posi];
        w[posi]=w[posj];
        w[posj]=temp;
        for(k=posi+1;k<len;k++)
        {
            for(m=posi+1;m<posi+1+(len-k);m++)
            {
            if(w[m]>w[m+1])
            {
                temp=w[m];
                w[m]=w[m+1];
                w[m+1]=temp;
            }
        }
        }
    //if(f==1)
        printf("%s\n",w);
        }
    else
        printf("no answer\n");

   }
    return 0;
}
