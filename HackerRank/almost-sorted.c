#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long int a[100001];
int checkrev(int x,int y)
{
int i,f=0;
for(i=x;i<y;i++)
{
    if(a[i]>a[i+1])
        f++;
    //else
      //  d++;
}
if(f==(y-x))
    return 1;
else
return 0;
}
int main() {

    long int i,j,t,n,l,r,s=0,rev;
    scanf("%ld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%ld",&a[i]);
    }
    j=n-1;i=0;
    while(i<j){
        //printf("%ld %ld\n",i,j);
        while(a[i]<a[i+1] && (i+1)<n){
            i++;
        }
        while(a[j]>a[j-1] && (j-1)>=0){
            j--;
        }
        //printf("%ld %ld\n",i,j);
        if(j<2 && i>=n-1 && s==0)
        {printf("Yes\n");break;}
        else if(i<j && s==0)
        {
         t=a[i];
         a[i]=a[j];
         a[j]=t;
         s=1;
         l=i;r=j;
         i=0;j=n-1;
         continue;
        }
        else if(s==1){
                if(i>j)
               {
                    printf("yes\nswap %ld %ld\n",l+1,r+1);
                    break;
               }
            rev=checkrev(l+1,r-1);
            if(rev==0)
                printf("no\n");
            else if(rev==1 && r-l>2)
                printf("yes\nreverse %ld %ld\n",l+1,r+1);
                break;
        }
    }
    return 0;
}
