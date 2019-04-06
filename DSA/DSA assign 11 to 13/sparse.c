#include<stdio.h>
#include<malloc.h>
typedef struct node
{
int row,column,no;
struct node *next;
}*NODE;
int arr[20][20],i,j,cnt=0;
void disp(NODE);
NODE create(NODE);
NODE header;
main()
{
int r,c;
header=(NODE)malloc(sizeof(struct node));
NODE start=header;
header->next=NULL;
printf("Enter no. of rows and columns respectively\n");
scanf("%d%d",&r,&c);
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
printf("ROW:%d  COLUMN:%d-",i+1,j+1);
scanf("%d",&arr[i][j]);
}
}
printf("Sparse Matrix:\n");
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
printf("%d\t",arr[i][j]);
printf("\n");
}
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
if(arr[i][j]!=0)
{
start=create(start);
}
}
}header->row=r;
header->column=c;

printf("Representation:\nRow\tColumn\tNumber\n");
disp(start->next);
}




NODE create(NODE start)
{
cnt++;
NODE new_node,ptr;
ptr=start;
new_node=(NODE)malloc(sizeof(struct node));
new_node->row=i+1;
new_node->column=j+1;
new_node->no=arr[i][j];
new_node->next=NULL;
if(header->next==NULL)
header->next=new_node;
else
{
while(ptr->next!=NULL)
ptr=ptr->next;
ptr->next=new_node;
}
//header->row=cnt;
//header->column=cnt;
header->no=cnt;
return start;
}


void disp(NODE start)
{
NODE ptr;
ptr=start;
if(start->next==NULL)
{
printf("No. of rows-%d,columns-%d and elements-%d\n",header->row,header->column,header->no);
}
else
{
while(ptr->next!=NULL)
{
printf("%d\t%d\t%d\n",ptr->row,ptr->column,ptr->no);
ptr=ptr->next;
}
printf("%d\t%d\t%d\n",ptr->row,ptr->column,ptr->no);
printf("No. of rows-%d,columns-%d and elements-%d\n",header->row,header->column,header->no);
}
}
