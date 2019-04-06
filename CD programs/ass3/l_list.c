#include <stdio.h>
#include <stdlib.h>
#include "l_list.h"

int initialize_l_list(l_list *h)
{
	h = (l_list *)malloc(sizeof(l_list));
	h->head=NULL;
	h->tail=NULL;
	h->curr=NULL;
	h->length = 0;
}

int print_l_list(l_list *h)
{
    if(h->head != NULL) //If there is at least 1 item in the list
    {
        //printf("List:");
        h->curr = h->head; //curr points to head
        while(h->curr != NULL) //while curr is not NULL
        {
            printf("%d,",h->curr->data); //print the data at curr
            h->curr = h->curr->next; //point curr to the next node
        }
        return(1);
    }
    else
    {
        printf("\nNo Item in List.\n");
        return(-1);
    }
}

int insert_at_start(l_list *h,int item)
{
    /*here we make a new node with head pointing to it. enter data into it. and point it to the next node
    */
    h->curr = h->head; //curr points to head
    h->head=(node *)malloc(sizeof(node)); //new node is created with head pointing to it
    if(!h->head)
    {
        printf("\nError. Node not created.\n");
        return(-1);
    }
    h->head->data = item; //data is entered into node that head points to
    h->length++;
    h->head->next = h->curr; //the head node then points to curr node, that is the next node in the list
    if(h->tail == NULL) //if there are no items in the list previously
    {
        h->tail = h->head; //tail is pointed to head as there is only 1 item
    }
    return(1);
}

int insert_at_end(l_list *h,int item)
{
    // we create a new node with curr pointing to it. also point tail to it. and enter data into it
    h->curr=(node *)malloc(sizeof(node));
    if(h->curr)
    {
        if(h->tail) //case if at least 1 item exists in the list
        {
            h->tail->next = h->curr; //it can also be: h->tail = h->curr;
        }
        else //case if there are no items in the list
        {
            h->head = h->curr; //head points to curr
        }
            h->tail = h->curr; //tail points to curr
            h->tail->data = item; //entered data into tail
            h->tail->next = NULL; //pointed tail to NULL
            h->length++;
    }
    else
    {
        printf("\nError. Node not created.\n");
        return(-1);
    }
}

int insert_at_middle(l_list *h,int pos, int item)
{
    /*here we traverse to the required position. create a new node and enter data into it. we point the new item
     to the next item of the curr pos. then we point curr to the new item
    */
	if(pos == 1)  //when position is the start of the list
	{
		insert_at_start(h,item);
		return(1);
	}

	else if(pos == h->length+1)  //when position is at the end of the list
	{
		insert_at_end(h,item);
		return(1);
	}

	else if(pos > h->length+1)  //when position is beyond the length of the list
	{
		printf("\nExceeds list Length.\n");
		return(-1);
	}

    else  //when position is in the middle of the list
    {
        int count=1;
        node *new = (node*) malloc (sizeof(node)); //creating a new node
        if(!new)
        {
            printf("\nError. Node not created.\n");
        }
        else
        {
            new->data = item; //entering data into the new node
            h->curr = h->head; //making the curr position to the head

            while(count < pos-1)
            {
                h->curr = h->curr->next; //changing current position to the next until required position is reached
                count++;
            }

            new->next = h->curr->next; //the new node is pointing to the next node that curr is pointing to
            h->curr->next = new; //the curr points to the new node
            new = NULL; //new pointer is no longer required so it is made NULL
            h->length++;
        }
    }
}

int remove_at_start(l_list *h)
{
    //here we point curr to head, then point head to the next item and remove the curr
    if(h->head != NULL) //case of at least 1 item in list
    {
        h->curr = h->head; //curr pointing to the head
		if(h->head->next == NULL)
			h->tail = NULL;
        h->head = h->head->next; //head pointing to the next node
        free(h->curr); //curr is freed now
        h->length--;
    }
    else
    {
        return(-1);
    }
}

int remove_at_end(l_list *h)
{
    //here we point the curr to the item before the tail, remove the tail and point it to curr item
    if(h->tail != NULL)  //if there is at least 1 item in the list
    {
        h->curr = h->head; //curr points to head
        if(h->head != h->tail) //if there are more than 1 items in the list ie head and tail don't point to same thing
        {
            while(h->curr->next != h->tail) //runs till the curr item is the previoous item from tail
            {
                h->curr = h->curr->next; //curr points to the next node
            }
            free(h->tail); //last node is deleted
            h->tail = h->curr; //tail now points to the curr node ie the node before the old tail
            h->curr->next = NULL; //the last node is made to point to NULL
        }
        else //when there is exactly 1 item in the list
        {
            free(h->tail); //the node is deleted
            h->head = h->tail = h->curr = NULL; //everything is made to point to NULL
        }
        h->length--;
    }
    else
    {
        return(-1);
    }
}

int remove_at_middle(l_list *h,int pos)
{
    /*here we traverse to the required position. create a new node and enter data into it. we point the new item
     to the next item of the curr pos. then we point curr to the new item
    */
	if(pos == 1)  //when position is the start of the list
	{
		remove_at_start(h);
		return(1);
	}

	else if(pos == h->length)  //when position is at the end of the list
	{
		remove_at_end(h);
		return(1);
	}

	else if(pos > h->length)  //when position is beyond the length of the list
	{
		printf("\nExceeds list Length.\n");
		return(-1);
	}

    else  //when position is in the middle of the list
    {
        int count=1;
        node *new;// = (node*) malloc (sizeof(node)); //creating a new node
        //if(!new)
        //{
          //  printf("\nError. Node not created.\n");
        //}
        //else
        //{
            //new->data = item; //entering data into the new node
            h->curr = h->head; //making the curr position to the head

            while(count < pos-1)
            {
                h->curr = h->curr->next; //changing current position to the next until required position is reached
                count++;
            }

            new = h->curr->next->next; //the new node is pointing to the next node that curr is pointing to
            free(h->curr->next);
            h->curr->next = new;// = new; //the curr points to the new node
            //new = NULL; //new pointer is no longer required so it is made NULL
            //free(new);
            h->length--;
        //}
    }
}

int reverse(l_list *h)
{
    /*here we kind of create a new list, remove the first element of old list and add it to the beginning of the new list
    and point the head to the next item of the old list.
    */
    struct node *new_head = NULL; //a new node is made which points to NULL
    if(h->head != NULL) //if there is at least 1 item in the list
    {
        while(h->head != NULL) //continues till head doesn't point to NULL ir upto the last node
        {
            h->curr = h->head; //curr points to head
            h->head = h->head->next; //head points to the next node
            if(new_head == NULL) //if new_head points to NULL ie, there are no items the new_head is pointing to
            {
                h->tail = h->curr; //tail now points to the curr node
            }
            h->curr->next = new_head; //the next node from curr points to the new_head
            new_head = h->curr; //new_head points to curr
        }
        h->head = new_head; //finally we make head point to new_head
        new_head = NULL; //since new_head pointer is no longer required, it is made to point to NULL
    }
    else
    {
        return(-1);
    }
}

int find_by_position(l_list *h,int pos)
{
    if(h->head != NULL) //if there is at least 1 item in the list
    {
        if(pos > h->length)
        {
            printf("\nExceeds List Length.\n");
            return(-1);
        }
        else
        {
            int count = 1;
            h->curr = h->head; //curr points to head

            while(count < pos)
            {
                h->curr = h->curr->next; //curr points to the next node
                count++;
            }

            printf("\nItem at position %d is: %d",pos,h->curr->data); //prints item at the curr node
        }
    }

    else //if there are no items in the list
    {
        printf("\nNo Item in List.");
        return(-1);
    }
}

int find_by_value(l_list *h,int item)
{
    if(h->head != NULL) //if there is at least 1 item in the list
    {
        int flag = 0,count = 1;
        h->curr = h->head; //curr points to head

        while(count <= h->length)
        {
            if(h->curr->data == item)
            {
                printf("\nPosition of %d is: %d",item,count);
                flag = 1;
            }
            h->curr = h->curr->next; //curr points to the next node
            count++;
        }

        if(flag == 0) //if item is not found in the list
        {
            printf("\n%d is not in List.",item);
        }
    }

    else //if there are no items in the list
    {
        printf("\nNo Item in List.");
        return(-1);
    }
}

int merge_two_lists(l_list *h1,l_list *h2,l_list *h3)
{
    h1->curr = h1->head;

    while(h1->curr != NULL)
    {
        insert_at_end(h3,h1->curr->data);
        h1->curr = h1->curr->next;
    }

    h2->curr = h2->head;

    while(h2->curr != NULL)
    {
        insert_at_end(h3,h2->curr->data);
        h2->curr = h2->curr->next;
    }

    return(1);
}

int size(l_list *h)
{
    return(h->length); //returns the length of the list
}
