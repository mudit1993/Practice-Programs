%{
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
	
	int	braceCountSquare = 0, braceCountCurly = 0, braceCount = 0, isValid = 1;
	stack s;
%}

%%
[a-zA-Z_][a-zA-Z0-9]*	{
							if (isempty(&s))
							{
								PUSH(&s, 1);
							}
							else if (Peek(&s) == 2 || Peek(&s) == 3 || Peek(&s) == 5 || Peek(&s) == 7)
							{
								PUSH(&s, 1);
							}
							else
							{
								return 1;
							}
						}
						

[0-9]+"."[0-9]+			{
							if (isempty(&s))
							{
								PUSH(&s, 1);
							}
							else if (Peek(&s) == 2 || Peek(&s) == 3 || Peek(&s) == 5 || Peek(&s) == 7)
							{
								PUSH(&s, 1);
							}
							else
							{
								return 1;
							}
						}
						

[0-9]+					{
							if (isempty(&s))
							{
								PUSH(&s, 1);
							}
							else if (Peek(&s) == 2 || Peek(&s) == 3 || Peek(&s) == 5 || Peek(&s) == 7)
							{
								PUSH(&s, 1);
							}
							else
							{
								return 1;
							}
						}


						
[+\-*/]					{
							if (!isempty(&s))
							{
								if (Peek(&s) == 1 || Peek(&s) == 4 || Peek(&s) == 6 || Peek(&s) == 8)
								{
									PUSH(&s, 2);
								}
							}
							else
							{
								return 1;
							}
						}
						
						
"["						{
							if (isempty(&s))
							{
								PUSH(&s, 3);
								++braceCountSquare;
							}
							else if (Peek(&s) == 2 || Peek(&s) == 3 || Peek(&s) == 5 || Peek(&s) == 7)
							{
								PUSH(&s, 3);
								++braceCountSquare;
							}
							else
							{
								return 1;
							}
						}
						
						
						
"]"						{
							if (braceCountSquare > 0 && !isempty(&s) && Peek(&s) == 1)
							{
								while (!isempty(&s) && Peek(&s) != 3)
								{
									POP(&s);
								}
								POP(&s);
								--braceCountSquare;
								PUSH(&s, 1);
							}
							else
							{
								--braceCountSquare;
								return 1;
							}
						}
						
"{"						{
							if (isempty(&s))
							{
								PUSH(&s, 5);
								++braceCountCurly;
							}
							else if (Peek(&s) == 2 || Peek(&s) == 3 || Peek(&s) == 5 || Peek(&s) == 7)
							{
								PUSH(&s, 5);
								++braceCountCurly;
							}
							else
							{
								return 1;
							}
						}
						
						
						
"}"						{
							if (braceCountCurly > 0 && !isempty(&s) && Peek(&s) == 1)
							{
								while (!isempty(&s) && Peek(&s) != 5)
								{
									POP(&s);
								}
								POP(&s);
								--braceCountCurly;
								PUSH(&s, 1);
							}
							else
							{
								--braceCountCurly;
								return 1;
							}
						}
						
						
"("						{
							if (isempty(&s))
							{
								PUSH(&s, 7);
								++braceCount;
							}
							else if (Peek(&s) == 2 || Peek(&s) == 3 || Peek(&s) == 5 || Peek(&s) == 7)
							{
								PUSH(&s, 7);
								++braceCount;
							}
							else
							{
								return 1;
							}
						}
						
						
						
")"						{
							if (braceCount > 0 && Peek(&s) == 1)
							{
								if (!isempty(&s))
								{
									while (!isempty(&s) && Peek(&s) != 7)
									{
										POP(&s);
									}
									POP(&s);
									--braceCount;
									PUSH(&s, 1);
								}
							}
							else
							{
								--braceCount;
								return 1;
							}
						}
						
.						{
							isValid = 0;
							return 1;
						}
%%

int yywrap()
{
	return 1;
}

main()
{
	system("clear");
	
	initialize(&s);
	
	yyin = fopen("expression.txt", "r");
	yylex();
	
	fclose(yyin);
	
	if (braceCountSquare == 0 && braceCountCurly == 0 && braceCount == 0 && isValid == 1)
	{
		if (isempty(&s) || Peek(&s) == 1)
		{
			printf("Valid Expression");
		}
		else
		{
			printf("In-Valid Expression");
		}
	}
	else
	{
		printf("In-Valid Expression");
	}
	
	printf("\n\n");
}

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
