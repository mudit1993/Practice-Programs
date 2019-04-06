#include<stdio.h>
#include<malloc.h>
typedef struct node
{   struct node *left;
	struct node *right;
	int data;
	int freq;
	int code;
}N;
void heapify(N *a,int n,int i)
{
	int smallest=i,r=i*2+1,l=2*i;
	N temp;
	if(a[smallest].freq<a[r].freq && r<=n)
	smallest=r;
	if(a[smallest].freq<a[l].freq && l<=n)
	smallest=l;
	if(smallest==i)return;
	temp=a[i];
	a[i]=a[smallest];
	a[smallest]=temp;
	heapify(a,n,smallest);
}
N deletemin(N *a,int *n)
{
    N val=a[1];
    a[1]=a[*n];
    *n=*n-1;
    heapify(a,*n,1);
    return val;
}
void insertheap(N *a,int *n,N *val)
{
    int i;
	i=*n=*n+1;
	while(a[i/2].freq>a[i].freq && i>1)
	{
		a[i]=a[i/2];
		i=i/2;
	}
	a[i]=*val;
}
N huffman(N *a,int n)
{
    N *x,*y,*newnode,xx,yy;
    int i;
    for(i=n/2;i>0;i--)heapify(a,n,i);
    while(n>1)
    {
        xx=deletemin(a,&n);
        yy=deletemin(a,&n);
        newnode=(N*)malloc(sizeof(struct node));
        x=(N*)malloc(sizeof(struct node));
        x->data=xx.data;x->freq=xx.freq;x->left=xx.left;x->right=xx.right;
        y=(N*)malloc(sizeof(struct node));
        y->data=yy.data;y->freq=yy.freq;y->left=yy.left;y->right=yy.right;
        if(x->freq<y->freq){newnode->left=x;newnode->right=y;}
        else {newnode->left=y;newnode->right=x;}
        newnode->freq=x->freq+y->freq;
        insertheap(a,&n,newnode);
    }
    return deletemin(a,&n);
}
void pre(N *root,int n)
{
    if(root!=NULL)
    {
        pre(root->left,10*n+2);
        root->code=n;
        if(root->left==NULL && root->right==NULL)
        printf("%d=> %d\n",root->data,root->code);
        pre(root->right,10*n+1);
    }
}
main()
{
    int n,i,temp1,temp;
    N a[20],root;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the element and frequency count\n");
    for(i=1;i<=n;i++)
    {scanf("%d %d",&(a[i].data),&(a[i].freq));
    a[i].right=NULL;
    a[i].left=NULL;
    }
    root=huffman(a,n);
    printf("Hoffmann Coded form\n");
    pre(&root,0);

}
