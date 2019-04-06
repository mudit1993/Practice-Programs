#include<stdio.h>

char s[100];
char stack[100];
char post[100];
main()
{
printf("Enter infix\n");
gets(s);
int i=0;
while(s[i]!='\0')
 i++;
s[i]=')';
stack[0]='(';
int k=-1,l=0;i=0;
while(s[i]!='\0')
{
     if((s[i]>64 && s[i]<91)||(s[i]>96 && s[i]<123)||(s[i]>47
     && s[i]<58))
      {
       k++;
       post[k]=s[i];
        }
       else if(s[i]=='(')
       {
       l++;
       stack[l]='(';
        }
       else if(s[i]==')')
       {
       while(stack[l]!='(')
       {
        k++;
        post[k]=stack[l];
        l--;
         }
         l--;
         }
       else if(s[i]=='^'||s[i]=='+'||s[i]=='/'||s[i]=='*'||s[i]=='-'||s[i]=='%')
 {
 if(s[i]=='+'||s[i]=='-')
 while(stack[l]!='(')
  {
  k++;
  post[k]=stack[l];
   l--;
   }

    else if(s[i]=='*'||s[i]=='/'|| s[i]=='%')
    while(stack[l]!='(' && stack[l]!='+' && stack[l]!='-')
    {
    k++;
    post[k]=stack[l];
    l--;
    }
    else if(s[i]=='^')
    while(stack[l]!='(' && stack[l]!='+' && stack[l]!='-'&& stack[l]!='*'
    && stack[l]!='/' && stack[l]!='%')
    {
     k++;
     post[k]=stack[l];
     l--;
      }


      l++;
      stack[l]=s[i];

      }
       i++;
        }
       puts(post);
        }




