typedef struct stack
{
    int *s;
    int top;
    int capacity;
}stack;

void initialize(stack *st)
{
    st->top = -1;
    st->capacity = 10;
    st->s = (int *)malloc(sizeof(int)*st->capacity);
}

int isempty(stack *st)
{
    if(st->top == -1)
        return 1;
    else
        return 0;
}

int isfull(stack *s)
{
    if(s->top == (s->capacity -1))
        return 1;
    else
        return 0;
}

void resize_stack(stack *s)
{
    s->capacity += 10;
    s->s = (int *)realloc(s->s,sizeof(int)*s->capacity);
}

void PUSH(stack *s, int element)
{
    if(isfull(s))
        resize_stack(s);
    s->s[++s->top] = element;
}

int POP(stack *s)
{
    if(isempty(s))
    {
        printf("\nStack is Empty\n");
        return;
    }
    else
        return(s->s[s->top--]);
}

int Peek(stack *s)
{
	if (!isempty(s))
	{
		return s->s[s->top];
	}
	
	return -1;
}
