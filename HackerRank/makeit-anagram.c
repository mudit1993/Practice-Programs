#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char a[10000],b[10000];
    int i,j,a1[27],b1[27],lena,lenb,del=0;
    scanf("%s%s",a,b);
    printf("%s\n%s",a,b);
    for(i=0;i<27;i++)
    {
        a1[i]=b1[i]=0;
    }
    lena=strlen(a);
    lenb=strlen(b);
    for(i=0;i<lena;i++)
    {
        a1[a[i]-97]++;
    }
    for(i=0;i<lenb;i++)
    {
        b1[b[i]-97]++;
    }
    for(i=0;i<26;i++)
    {
        //printf("%d %d\n",a1[i],b1[i]);
        del+=abs(a1[i]-b1[i]);
    }
    printf("%d\n",del);
    return 0;
}
