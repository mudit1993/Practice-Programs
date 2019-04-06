#include<stdio.h>
#include<malloc.h>
typedef struct node{
    int data;
    struct node * next;
    struct node * prev;
} * NODE;

NODE start=NULL;

NODE create(NODE start)
{
    NODE ptr;
    int x;
    printf("Enter -1 to end..\n");
    printf("Enter the data...\n");
    scanf("%d",&x);

        NODE temp=(NODE)malloc(sizeof(struct node));
        temp->data=x;
        temp->next=temp->prev=temp;
        start=temp;

    while(x!= -1)
    {
        ptr=(NODE)malloc(sizeof(struct node));
        scanf("%d",&x);
        ptr->data=x;
        ptr->prev=start->prev;
        ptr->next=start;
        start->prev->next=ptr;
        start->prev=ptr;
    }
    return start;
}

/*

NODE create(NODE start)
{
int x;NODE ptr,ptr1;
printf("Enter val(-1 to exit)\n");
scanf("%d",&x);
while(x!=-1)
{
NODE new_node;
new_node=(NODE)malloc(sizeof(struct node));
new_node->data=x;
if(start==NULL)
{
start=new_node;
new_node->next=start;
new_node->prev=start;
ptr=new_node;
ptr1=new_node;
}
else
{
new_node->next=start;
ptr->next=new_node;
ptr1->prev=new_node;
new_node->prev=ptr;
start=new_node;
ptr1=ptr1->prev;
}
printf("Enter more val(-1 to exit)\n");
scanf("%d",&x);
}//end of while loop
return start;
}*/



NODE insert_at(NODE start)
{
    int pos,c=1,flag=0;
    NODE ptr=start;
    printf("Enter the position where you want to enter ..:");
    scanf("%d",&pos);
     while((ptr!=start|| flag==0) && c<pos)
    {
        flag=1;
        ptr=ptr->next;
        c=c+1;
    }
    //if(pos<1) //|| pos>c)
    //{
      //  printf("Invalid input...\n");
        //goto t;
    //}
    if(c==pos)//(pos==1)
    {
         NODE temp=(NODE)malloc(sizeof(struct node));
        printf("Enter the data..:\n");
        scanf("%d",&temp->data);
        if(pos==1)
          {
              temp->prev=start->prev;
              temp->next=start;
            start->prev->next=temp;
            start->prev=temp;
            start=temp;
          }
         else if(ptr==start && flag==1)
          {
              temp->next=ptr;
              temp->prev=ptr->prev;
              ptr->prev->next=temp;
              ptr->prev=temp;
          }
          else
            {
                temp->prev=ptr->prev;
                temp->next=ptr;
                ptr->prev->next=temp;
                ptr->prev=temp;
            }
    }
    else
        printf("Invalid Input\n");
    /* }
      }
    }
    else
    {
        NODE temp=(NODE)malloc(sizeof(struct node));
        printf("Enter the value to insert");
        scanf("%d",&temp->data);
        temp->next=ptr->next;
        temp->prev=ptr->next->prev;
        ptr->next->prev=temp;
        ptr->next=temp;
    }

    t: */
    return start;
}

void display(NODE start)
{
    NODE ptr=start,flag=1;
    while(ptr!=start || flag==1)// && FLAG==1)
    {
        flag=2;
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
main()
{
    int opt;
	while(1)
	{
		printf("\nEnter a option...:");
		printf("\n1) create a linked list\n2) display \n3) insert \n4) delete at position\n5) exit\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				start=create(start);
				printf("Link created...");
			case 2:
				display(start);
				printf("\n");
				break;
			case 3:
				start=insert_at(start);
				break;
			case 5:
				exit(0);
		}
	}

}

