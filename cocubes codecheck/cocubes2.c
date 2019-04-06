#include<stdio.h>
#include<malloc.h>

typedef struct node
{
char chh;
struct node *next;
}*alpha;

int main()
{
    alpha head=NULL,prev=NULL,ptr=NULL,new_node,last;
    char ch;
    int cnt,c;
    scanf("%d",&cnt);
    c=cnt;
    c--;
    new_node=(alpha)(malloc(sizeof(struct node)));
    head=new_node;
    head->next=NULL;
    scanf(" %c",&ch);
    head->chh=ch;
    ptr=prev=head;
    while(c--)
    {
        scanf(" %c",&ch);
        new_node=(alpha)(malloc(sizeof(struct node)));
        ptr->next=new_node;
        ptr=ptr->next;
        ptr->next=NULL;
        ptr->chh=ch;
    }
    last=ptr;
    c=cnt;
    ptr=head;
    if(head->chh=='a'||head->chh=='e'||head->chh=='i'||head->chh=='o'||head->chh=='u'){

    }
    else{
    while(c--)
    {
        ch=ptr->chh;
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
    {
        break;
    }
    else{
            prev=ptr;
        ptr=ptr->next;
    }
    }
    last->next=head;
    head=ptr;
    prev->next=NULL;
    last=prev;
    c++;
    }

    //printf("\n%c",last->chh);
    ptr=prev=head;

    while(c--)
    {
      ch=ptr->chh;

    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
    {
        prev=ptr;
        ptr=ptr->next;
    }
    else{
        prev->next=ptr->next;
        last->next=ptr;
        last=last->next;
        //printf("last- %c",last->chh);
        last->next=NULL;
        ptr=prev->next;
    }
    }
    ptr=head;
    while(cnt--)
    {
    printf("%c->",ptr->chh);
    ptr=ptr->next;
    }

return 0;
}
