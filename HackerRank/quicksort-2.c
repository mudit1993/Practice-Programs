#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
/*
7
5 8 1 3 7 9 2
o/p
2 3
1 2 3
7 8 9
1 2 3 5 7 8 9
left left right left right 2 3
1 2 3
right left right 7 8 9
1 2 3 5 7 8 9
*/
void quicksort(int h,int *ar)
{
    int la[h],ra[h],i,pivot,x=0,y=0,k,ind;
    if(h<2)
        return;
        pivot=ar[0];
    for(i=1;i<h;i++)
    {
        if(ar[i]<=pivot)
        {
         la[x++]=ar[i];
        }
        else{
            ra[y++]=ar[i];
        }
    }
    //printf("hello");
    quicksort(x,la);
    //printf("hi");
    quicksort(y,ra);//left portion of the array is first sorted then right side
    ind=k=0;//  for every recursive step ar starts from 0 has its own ar[]-stack.
    for(k=0;k<x;k++)
    {
        ar[ind++]=la[k];
        printf("%d ",ar[ind-1]);
    }
    ar[ind++]=pivot;
    printf("%d ",pivot);

    for(k=0;k<y;k++)
    {
        ar[ind++]=ra[k];
        printf("%d ",ra[k]);
    }
    printf("\n");
}

int main(void) {

   int _ar_size,i;
   scanf("%d", &_ar_size);
int _ar_i,ar[10000];
for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) {
   scanf("%d", &ar[_ar_i]);
}
quicksort(_ar_size,ar);
   return 0;
}
