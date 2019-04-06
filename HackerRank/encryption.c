#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char s[100];
    int flr,cil,len,i,j;
    double f;
    scanf("%s",s);
    len=strlen(s);
    f=(double)pow(len,0.5);
    if((f-(int)f)==0)
       {
         flr=cil=(int)f;
       }
    else if((f-(int)f)>=0.5)
    {
        cil=flr=(int)f+1;
    }
    else if(f-(int)f<0.5)
    {
        flr=(int)f;
        cil=flr+1;
    }
     //printf("%d %d",flr,cil);
    for(i=0;i<f;i++)
    {
        for(j=0;j+i<len;j+=cil)
        {
            printf("%c",s[j+i]);
        }
        printf(" ");
    }
    printf("\n");
  //  printf("%d %d",flr,cil);
     return 0;
}
