typedef struct node
{
	int data;
	struct node *next;

}node;

typedef struct l_list
{
	struct node *head;
	struct node *tail;
	struct node *curr;
	int length;
}l_list;


int initialize_l_list(l_list *h);

int print_l_list(l_list *h);

int insert_at_start(l_list *h,int item);

int insert_at_end(l_list *h,int item);

int insert_at_middle(l_list *h,int pos, int item);

int remove_at_start(l_list *h);

int remove_at_end(l_list *h);

int remove_at_middle(l_list *h,int pos);

int reverse(l_list *h);

int find_by_position(l_list *h,int pos);

int find_by_value(l_list *h,int item);

int merge_two_lists(l_list *h1,l_list *h2,l_list *h3);

int size(l_list *h);
