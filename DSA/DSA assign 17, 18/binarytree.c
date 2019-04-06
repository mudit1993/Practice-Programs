#include<stdio.h>
#include<malloc.h>
typedef struct node
{
int data;
struct node *right;
struct node *left;
}*NODE;
NODE root=NULL;
void insert(int);
void search();
void preorder(NODE);
void inorder(NODE);
void postorder(NODE);
int main()
{
int opt,no;
do{
printf("1)Insertion\n");
printf("2)Search an element\n");
printf("3)Traverse \n4)Exit\n");
scanf("%d",&opt);
switch(opt)
{
case 1:
printf("Enter number\n");
scanf("%d",&no);
insert(no);
printf("Data inserted\n");
break;
case 2:
search();
break;
case 3:
preorder(root);
printf("\n");
inorder(root);
printf("\n");
postorder(root);
printf("\n");
break;
case 4:
printf("Terminated!\n");
}
}while(opt>0 && opt<=3);
}


void insert(int x)
{
NODE nw,temp;
 nw=(NODE)malloc(sizeof(struct node));
 nw->left=NULL;
 nw->right=NULL;
 nw->data=x;
 if(root==NULL)
 root=nw;
 else
 {
 temp=root;
 while(1)
 {
 if(temp->data<nw->data)
 {

 if(temp->right==NULL)
 {
 temp->right=nw;
 break;
 }
 else
 {
  temp=temp->right;
 }
 }
 else
 {
 if(temp->data >nw->data)
 {
 if(temp->left==NULL)
 {
 temp->left=nw;
 break;
 }
  else
 { 
 temp=temp->left;
 }
 }
 else
 break;
 }
 }
 }
}

void search()
{
int n;
printf("Enter a number to be searched\n");
scanf("%d",&n);
NODE p;
p=root;
while(p!=NULL && p->data!=n)
{
if(p->data>n)
p=p->left;
else
p=p->right;
}
if(p!=NULL)
printf("Search Successful!!\n");
else
printf("Number not found!");
}


void preorder(NODE p)
{
if(p!=NULL)
{
printf("%d ",p->data);
preorder(p->left);
preorder(p->right);
}
}



void inorder(NODE p)
{
if(p!=NULL)
{
inorder(p->left);
printf("%d ",p->data);
inorder(p->right);
}
}

void postorder(NODE p)
{
if(p!=NULL)
{
postorder(p->left);
postorder(p->right);
printf("%d ",p->data);
}
}
