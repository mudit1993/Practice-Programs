#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
void partition(int ar_size, int *  ar) {
    int pivot=ar[0],t,j=0,i=0;
    int a[10000],x=0;
        while(i<ar_size){
            if(pivot>ar[i])
                a[x++]=ar[i];
            i++;
        }
        i=0;
        while(i<ar_size){
            if(pivot==ar[i])
               a[x++]=ar[i];
        i++;
        }
        while(j<ar_size){
            if(pivot<ar[j])
            a[x++]=ar[j];
        j++;
        }
     for(i=0;i<x;i++)
       {
       printf("%d ",a[i]);
   }

}

int main(void) {

   int _ar_size,i;
   scanf("%d", &_ar_size);
int _ar[_ar_size], _ar_i;
for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) {
   scanf("%d", &_ar[_ar_i]);
}
partition(_ar_size, _ar);

   return 0;
}
