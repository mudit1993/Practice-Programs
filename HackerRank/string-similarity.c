#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

long long int stringSimilarity(char a[]) {
long long int sum=0,i,j,n,k;
    for(n=strlen(a),i=1;i<n;i++)
    {
        k=0;
        j=i;
        while(j<n && a[k]==a[j] ){
            sum++;k++;j++;
        }

    }
    return (sum+n);
}

int main() {
    int t, i;
    long long int res;
    scanf("%d",&t);
    char a[100001];
    for (i=0;i<t;i++) {
        scanf("%s",a);
        res=stringSimilarity(a);
        printf("%lld\n",res);
    }

    return 0;
}
