typedef struct stack
{
    int *s;
    int top;
    int capacity;
}stack;

void initialize(stack *st);

int isempty(stack *st);

int isfull(stack *s);

void resize_stack(stack *s);

void PUSH(stack *s, int element);

int POP(stack *s);

int Peek(stack *s);
