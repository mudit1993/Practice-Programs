#include<stdio.h>
#include<malloc.h>
typedef struct node
{
int data;
struct node *right;
struct node *left;
}*NODE;
NODE root=NULL;
NODE root1=NULL;
NODE insert(NODE,int);
void leaf(NODE);
void preorder(NODE);
void reorder(int,NODE);
void inorder(NODE);
void postorder(NODE);
int main()
{
NODE ptr;
int opt,no,n;
do{
printf("1)Insertion\n");
printf("2)Traverse\n3)no. of leaf nodes  \n4)Exit\n");
scanf("%d",&opt);
switch(opt)
{
case 1:
printf("Enter number\n");
scanf("%d",&no);
root=insert(root,no);
printf("Data inserted\n");
break;
case 2:
printf("Preorder:\n");
preorder(root);
printf("\n");
printf("Inorder:\n");
inorder(root);
printf("\n");
printf("Postorder:\n");
postorder(root);
printf("\n");
break;
case 3:
leaf(root);
printf("\nEnter a number from the above data to make a root\n");
scanf("%d",&n);
root1=(NODE)malloc(sizeof(struct node));
root1->data=n;
root1->left=root1->right=NULL;
break;
case 4:printf("\n");

}
}while(opt>0 && opt<=2);
reorder(n,root);
printf("Preorder:\n");
preorder(root1);
printf("\n");
printf("Inorder:\n");
inorder(root1);
printf("\n");
printf("Postorder:\n");
postorder(root1);
printf("\n");
}

void reorder(int n1,NODE p)
{
if(p!=NULL)
{
if(p->data!=n1)
root1=insert(root1,p->data);
reorder(n1,p->left);
reorder(n1,p->right);
}
}
NODE insert(NODE r,int x)
{
NODE nw,temp;
 nw=(NODE)malloc(sizeof(struct node));
 nw->left=NULL;
 nw->right=NULL;
 nw->data=x;
 if(r==NULL)
{
 r=nw;
//max=min=root->data;
} 
else
 {
 temp=r;
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
return r;
}




void leaf(NODE p)
{
if(p!=NULL)
{
leaf(p->left);
if(p->left==NULL && p->right==NULL)
printf("%d\t",p->data);
leaf(p->right);
}
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
