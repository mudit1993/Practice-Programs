#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char a[10000];
    int i,t,a1[27],b1[27],lena,del=0;
    scanf("%d",&t);
    while(t--){
    scanf("%s",a);
    lena=strlen(a);
    if(lena%2==1) {
        printf("-1\n");
        continue;
    }
        del=0;
      for(i=0;i<27;i++)
    {
        a1[i]=b1[i]=0;
    }

    for(i=0;i<lena/2;i++)
    {
        a1[a[i]-97]++;
        b1[a[i+lena/2]-97]++;
    }
    for(i=0;i<26;i++)
    {
        //printf("%d %d\n",a1[i],b1[i]);
        del+=abs(a1[i]-b1[i]);
    }
    printf("%d\n",del/2);
    }
    return 0;
}
