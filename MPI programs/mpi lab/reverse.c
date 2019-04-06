#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
	*a^=*b;
	*b^=*a;
	*a^=*b;
}
void reverse(int *arr,int size){
	int i;
	int *q=&arr[size-1];
	for(i=size-1;i>=0;i--){
	printf("%d\t%d\n",*(arr+i),*(q-i));
	//swap((arr+i),(q-i));
}
}
void print(int *arr,int size){
	int i;
	for(i=0;i<size;i++)
	printf("%d\t",*(arr+i));
	printf("\n");
}
int main(){
	int i,size,*arr;
	printf("\nenter the size: ");
	scanf("%d",&size);
	arr=(int *)malloc(sizeof(int)*size);
	for(i=0;i<size;i++)	
	scanf("%d",&(*(arr+i)));
	//print(arr,size);
	reverse(arr,size);
	//print(arr,size);
	free(arr);
	arr=NULL;
	return 0;
}
