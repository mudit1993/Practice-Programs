#include<stdio.h>
#include<malloc.h>
typedef struct node
{
int data;
struct node *next;
}*NODE;
NODE start=NULL;
NODE insert(NODE);
NODE delete(NODE);
void disp(NODE);
main()
{
int opt;
do{
	printf("\nMain Menu\n");
	printf("1)Insert\n");
	printf("2)Delete\n");
	printf("3)Display\n");
	printf("4)Exit\n");
	scanf("%d",&opt);
	switch(opt)
	{
	case 1:	start=insert(start);
		printf("Value inserted in Queue\n");
		break;
	case 2: start=delete(start);
		printf("Value deleted from the queue\n");
		break;
	case 3:	if(start==NULL)printf("Queue deleted\n");
		else disp(start);
		break;
	case 4:	printf("Execution Terminated!\n");
	}
  }while(opt>=1&&opt<=3);
}



NODE insert(NODE start)
{
	NODE new_node,ptr;
	int x;
	printf("Enter a value (-1 to exit)\n");
	scanf("%d",&x);
	while(x!=-1)
	{
		new_node=(NODE)malloc(sizeof(struct node));
		new_node->data=x;
		if(start==NULL)
		{
			start=new_node;
			new_node->next=NULL;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			ptr=ptr->next;			
			ptr->next=new_node;
			new_node->next=NULL;
		}
	printf("Enter more val(-1 to Exit)\n");
	scanf("%d",&x);
	}
return start;
}

NODE delete(NODE start)
{
	NODE ptr=start;
	if(start==NULL)
	printf("Underflow \n");
	else
	{	
		start=start->next;
		free(ptr);
	}
return start;
}

void disp(NODE start)
{
NODE ptr=start;
while(ptr->next!=NULL)
{
printf("%d->",ptr->data);
ptr=ptr->next;
}
printf("%d",ptr->data);
}	
