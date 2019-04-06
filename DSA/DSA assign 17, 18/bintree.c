#include<stdio.h>
#include <malloc.h>
typedef struct bst
{
struct bst *l;
int info;
struct bst *r;
}*node;
node root=NULL;
void delete(int);
void create(int data)
{node nw,temp;
 nw=(node)malloc(sizeof(struct bst));
 nw->l=NULL;
 nw->r=NULL;
 nw->info=data;
 if(root==NULL)
 root=nw;
 else
 {
 temp=root;
 while(1)
 {
 if(temp->info<nw->info)
 {

 if(temp->r==NULL)
 {
 temp->r=nw;
 break;
 }
 else
 {
  temp=temp->r;
 }
 }
 else
 {
 if(temp->info >nw->info)
 {
 if(temp->l==NULL)
 {
 temp->l=nw;
 break;
 }
  else
 {
 temp=temp->l;
 }
 }
 else
 break;
 }
 }
 }
}
void inorder(node t)
{

if(t!=NULL)
{
inorder(t->l);
printf("%d\t",t->info);
inorder(t->r);
}
}
void preorder(node t)
{
 if(t!=NULL)
    {
    printf("%d\t",t->info);
    preorder(t->l);
    preorder(t->r);
    }
}
void postorder(node t)
{
 if(t!=NULL)
    {
    postorder(t->l);
    postorder(t->r);
    printf("%d\t",t->info);
    }
}
void search(int data)
{node t,p;int f=0;
 t=root;
 while(t!=NULL)
 {if(t->info==data)
  {f=1;
  break;
  }
  p=t;
  if (t->info>data)
  t=t->l;
  else
  t=t->r;
 }
if(f==1)
{printf("\nThe %d Element is Present",t->info);
 printf("\nParent of node %d is %d",t->info,p->info);
}
}


void delete(int data)
{
node t,p,gp,temp,temp1;
int f=0;
t=root;
while(t!=NULL)
{
if(t->info==data)
  {f=1;
  break;
  }
  gp=p;
  p=t;
  if (t->info>data)
  t=t->l;
  else
  t=t->r;

}
if(f==1)
{
	if(t->l==NULL && t->r==NULL)
	{
		if(p->r==t)
		p->r=NULL;
		else if(t==root)
        root=NULL;
		else
		p->l=NULL;
		free(t);
	}
	else if(t->r!=NULL && t->l==NULL)//)||(t->r==NULL && t->l!=NULL))
	{
		if(t==root)
		{
		root=t->r;
		}
		else if(p->l==t)
		p->l=t->r;
		else
		p->r=t->r;
	}
	else if(t->r==NULL && t->l!=NULL)
	{
		if(t==root)
		root=t->l;
		else if(p->l==t)
		p->l=t->l;
		else
		p->r=t->l;
	}
	else
	{
		temp=t->l;
		temp1=t;
		while(temp->r!=NULL)
		{
		temp1=temp;
		temp=temp->r;
		}
		t->info=temp->info;
		if(temp1==root)
		{
		root->l=NULL;
		free(temp);
		}
		else if(temp->r==NULL && temp->l==NULL)
		{temp1->r=temp->l;
		free(temp);
		}
		else
		{
		temp1->r=temp->l;
		free(temp);
		}
	}
}
}





void main()
{
int ch,a,b;
do
{
printf("\nenter the choice\n");
printf("1.creation\n2.inorder\n3.preorder\n4.postorder\n5.search\n6.Delete\n7.exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("enter the data\n");
	scanf("%d",&a);
	create(a);
	break;
case 2:inorder(root);
	break;
case 3:preorder(root);
	break;
case 4:postorder(root);
	break;
case 5:printf("\nEnter Element to be searched :");
       scanf("%d",&b);
	search(b);
	break;
case 6:printf("Enter a number to be deleted\n");
	scanf("%d",&b);
	delete(b);
}
}
while(ch!=7);
}
