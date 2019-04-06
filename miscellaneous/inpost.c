#include<stdio.h>
#include<string.h>
char s[50],post[50];
char stack[50];
main()
{
int top=0,i=0,j=-1;
printf("Enter an Infix Expression\n");
gets(s);
while(s[i]!='\0')
 i++;
s[i]=')';
i=0;
stack[top]='(';

while(s[i]!='\0')
{
     if(s[i]=='+'||s[i]=='-'||s[i]=='^'||s[i]=='%'||s[i]=='/'||s[i]=='*')
    {
        if(s[i]=='+'||s[i]=='-')
        {
            while(stack[top]!='(')
            {
                j++;
                post[j]=stack[top];
                top--;
            }
        }
        else if(s[i]=='/' ||s[i]=='*' || s[i]=='%')
        {
            while(stack[top]!='(' && stack[top]!='+' && stack[top]!='-')
            {
                j++;
                post[j]=stack[top];
                top--;
            }
        }
        else if(s[i]=='^')
        {
            while(stack[top]!='('&& stack[top]!='+' && stack[top]!='-' && stack[top]!='/' && stack[top]!='*' && stack[top]!='%')
            {
                j++;
                post[j]=stack[top];
                top--;
            }
        }

        top++;
        stack[top]=s[i];

    }
    else if(s[i]=='(')
    {
    top++;
    stack[top]=s[i];
    }
    else if((s[i]>=65 && s[i]<=90)||(s[i]>=97 && s[i]<=122)||(s[i]>=48 && s[i]<=57))
    {
    j++;
    post[j]=s[i];
    }
    else if(s[i]==')')
    {
        while(stack[top]!='(')
        {
            j++;
            post[j]=stack[top];
            top--;
        }
    top--;
    }
i++;
}
printf("Postfix expression:\n");
puts(post);
}
