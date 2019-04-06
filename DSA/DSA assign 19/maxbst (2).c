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
NODE ptr;
int opt,no;
do{
printf("1)Insertion\n");
printf("2)Traverse \n3)Exit\n");
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
case 3:printf("\n");

}
}while(opt>0 && opt<=2);
ptr=root;
while(ptr->left!=NULL)
ptr=ptr->left;
printf("Minimum is %d\n",ptr->data);
ptr=root;
while(ptr->right!=NULL)
ptr=ptr->right;
printf("Maximum is %d\n",ptr->data);
}


void insert(int x)
{
NODE nw,temp;
 nw=(NODE)malloc(sizeof(struct node));
 nw->left=NULL;
 nw->right=NULL;
 nw->data=x;
 if(root==NULL)
{
 root=nw;
//max=min=root->data;
} 
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
