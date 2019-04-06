#include<stdio.h>
#include<string.h>
main()
{
int i=0,c=0;
char s[50];
printf("Enter an expression\n");
gets(s);
while(s[i]!='\0')
{
    if(s[i]==')' || s[i]=='(')
    {
        if(i==0 && s[i]==')')
        {c--;
            break;
        }
        else if(i==strlen(s) )
if(s[i]=='(' &&((s[i+1]>=65 && s[i+1]<=90)|| (s[i+1]>=97 && s[i+1]<=122)))
{
if(i==0)
c++;
else if(s[i-1]=='^'||s[i-1]=='*'||s[i-1]=='/'||s[i-1]=='%'||s[i-1]=='-'||s[i-1]=='+')
c++;
else
break;
}
else if(s[i]==')' &&((s[i-1]>=65 && s[i-1]<=90)|| (s[i-1]>=97 && s[i-1]<=122)))
{
if(s[i+1]=='\0')
c--;
else if(s[i+1]=='^'||s[i+1]=='*'||s[i+1]=='/'||s[i+1]=='%'||s[i+1]=='-'||s[i+1]=='+')
c--;
else
break;
}
//else if(s[i]=='(')
   // c++;
//    c--;
}
i++;
}
if(c==0)
printf("Expression is correct\n");
else
printf("Expression is not correct\n");
}
