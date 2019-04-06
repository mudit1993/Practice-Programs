#include<stdio.h>
#include<string.h>
char s[50],rev[50],post[50],pre[50];
char stack[50];
main()
{
int top=0,i,j=-1;
printf("Enter an Infix Expression\n");
gets(s);
for(i=(strlen(s)-1);i>=0;i--)
{
    if(s[i]=='(')
        rev[top]=')';
    else if(s[i]==')')
        rev[top]='(';
    else
        rev[top]=s[i];
    top++;
}
i=0;
while(rev[i]!='\0')
 i++;
rev[i]=')';
top=i=0;
stack[top]='(';

while(rev[i]!='\0')
{
     if(rev[i]=='+'||rev[i]=='-'||rev[i]=='^'||rev[i]=='%'||rev[i]=='/'||rev[i]=='*')
    {
        if(rev[i]=='+'||rev[i]=='-')
        {
            while(stack[top]!='(')
            {
                if(stack[top]!='+'&& stack[top]!='-')
                {
                j++;
                post[j]=stack[top];
                top--;
                }
                else
                    break;
            }
        }
        else if(rev[i]=='/' ||rev[i]=='*' || rev[i]=='%')
        {
            while(stack[top]!='(' && stack[top]!='+' && stack[top]!='-')
            {
                if(stack[top]=='^')
                {
                    j++;
                    post[j]=stack[top];
                    top--;
                }
                else break;

            }
        }
        else if(rev[i]=='^')
        {
            while(stack[top]!='('&& stack[top]!='+' && stack[top]!='-' && stack[top]!='/' && stack[top]!='*' && stack[top]!='%')
            {
                j++;
                post[j]=stack[top];
                top--;
            }
        }

        top++;
        stack[top]=rev[i];

    }
    else if(rev[i]=='(')
    {
    top++;
    stack[top]=rev[i];
    }
    else if((rev[i]>=65 && rev[i]<=90)||(rev[i]>=97 && rev[i]<=122)||(rev[i]>=48 && rev[i]<=57))
    {
    j++;
    post[j]=rev[i];
    }
    else if(rev[i]==')')
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
top=0;
for(i=j;i>=0;i--)
{
    pre[top]=post[i];
    top++;
}
puts(pre);
}
