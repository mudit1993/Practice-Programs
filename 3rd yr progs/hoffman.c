#include<stdio.h>
int f[20],
char chr[20],c1;
int size;
typedef struct node
{
char c;
int freq;
struct *left,*right;
}*NODE;
void heapify(int *f,int i,int size)
{
int l=2*i,r=(2*i)+1;
int large=i;
char c;

if(f[l]<f[large] && l<=size)
large=l;
if(f[r]<f[large] && r<=size)
large=r;
if(large==i)
{
return;
}
else{
f[large]=f[large]+f[i];
f[i]=f[large]-f[i];
f[large]=f[large]-f[i];
c=chr[large];
chr[large]=chr[i];
chr[i]=c;
heapify(f,large,size);
}
}
void build_heap(int *f,int size)//heapify
{
int i;
for(i=(size/2);i>=1;i--)
heapify(f,i,size);
//return f[1];
}
void insert(int *f,int size,int item)
{
size++;
int i=size;
while(item>a[i/2] &&i>=1)
{
f[i]=f[i/2];
chr[i]=chr[i/2];
i=i/2;
}
f[i]=item;
chr[i]=

}
int delete(int *f,int size)// delete and return min. value
{
int temp=f[1];
c1=chr[1];
f[1]=f[size];
chr[1]=chr[size];
size--;
build_heap(f,size);
return temp;
}
void main()
{
int i,j,x,y,n;
NODE z;
char c2[20];
printf("Enter number of different characters\n");
scanf("%d",&size);
n=size;
for(i=1;i<=size;i++)
{
printf("Enter character and its frequency\n");
scanf("%c%d",&chr[i],&f[i]);
}
for(i=2;i<=size;i++)
{
x->freq=delete(f,size);

y->freq=delete(f,size);
z=(NODE)malloc(sizeof(struct node));
z->c=chr[i];
z->freq=x->freq+y->freq;
z->left=x;
z->right=y;
insert()
}
}


