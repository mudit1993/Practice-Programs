#include<stdio.h>
int main(){
	long long sum,count,fact,n,i,j,left,right,T,k;
	scanf("%lld",&T);
	int arr[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
	while(T--){
		sum=0;
		scanf("%lld %lld %lld",&n,&left,&right);
		for(i = 0;arr[i]<=n; i++){
			fact=(right/arr[i])-((left-1)/arr[i]);
			sum=sum+fact;
          }
         // printf("%lld\n",sum);

		for(j=0;j<i-1;j++){
			for(k=j+1;k<i;k++){
				count=arr[j]*arr[k];
				fact=(right/count)-((left-1)/count);
				sum=sum-fact;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
