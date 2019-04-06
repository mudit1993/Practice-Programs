#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int seq[5001][5001];
char a[5001],b[5001];
int main() {

    int l,i,j;
    scanf("%s%s",a,b);
    l=strlen(a);
    for(i=0;i<=l;i++)
         seq[0][i]=seq[i][0]=0;
    for(i=0;i<l;i++)
    {
        for(j=0;j<l;j++)
        {
            if(a[i]==b[j])
            {
                seq[i+1][j+1]=seq[i][j]+1;
            }
            else{
                seq[i+1][j+1]=seq[i][j+1]<seq[i+1][j]?seq[i+1][j]:seq[i][j+1];
            }
        }
    }
    printf("%d\n",seq[l][l]);
    return 0;
}
