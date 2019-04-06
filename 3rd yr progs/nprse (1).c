/*E->TE'
   E'->+TE'/@
   T->FT'
   T'->*FT'/@
   F->(E)/a
   
   T' as H
   E' as G
   */
   
   #include<stdio.h>
   #include<string.h>
   char stack[40],inp[20];
   int i=0,j=0;
   
   void push(char *);
   void pop();
   int main()
   {
   int len,flag;
   flag=0;
   char *tab[5][6],ch;
   tab[0][0] = "TG";
   tab[0][3] = "TG";
   tab[1][1] = "+TG";
   tab[1][4] = "@";
   tab[1][5] = "@";
   tab[2][0] = "FH";
   tab[2][3] = "FH";
   tab[3][1] = "@";
   tab[3][2] = "*FH";
   tab[3][4] = "@";
   tab[3][5] = "@";
   tab[4][0] = "a";
   tab[4][1] = "(E)";
   
   printf("enter the string \n");
   scanf("%s",inp);
   len = strlen(inp);
   push("E$");
   while(len && flag==0)
   {
   if(stack[i]=='E' && inp[j]=='a')
   {
   pop();
   push(tab[0][0]);
   }
   else if
   (stack[i]=='E' && inp[j]=='(')
   {
   pop();
   push(tab[0][3]);
   }else
   if(stack[i]=='G' && inp[j]=='+')
   {
   pop();
   push(tab[1][1]);
   }else
   if(stack[i]=='G' && inp[j]==')')
   {
   pop();
   //push(tab[0][0]);
   }
   else
   if(stack[i]=='G' && inp[j]=='$')
   {
   pop();
   //push(tab[0][0]);
   }else
   if(stack[i]=='T' && inp[j]=='a')
   {
   pop();
   push(tab[2][0]);
   }else
   if(stack[i]=='T' && inp[j]=='(')
   {
   pop();
   push(tab[2][3]);
   }else
   if(stack[i]=='H' && inp[j]=='+')
   {
   pop();
   push(tab[3][1]);
   }else
   if(stack[i]=='H' && inp[j]=='*')
   {
   pop();
   push(tab[3][2]);
   }else
   if(stack[i]=='H' && inp[j]==')')
   {
   pop();
   //push(tab[3][4]);
   }else
   if(stack[i]=='H' && inp[j]=='$')
   {
   pop();
   //push(tab[0][0]);
   }else
   if(stack[i]=='F' && inp[j]=='a')
   {
   pop();
   push(tab[4][0]);
   }else
   if(stack[i]=='F' && inp[j]=='(')
   {
   pop();
   push(tab[4][3]);
   }else
   if(stack[i]=='(' || stack[i]==')' || stack[i]=='+' || stack[i]=='*')
   {
   pop();
   j++;
   }else
   {
flag=1;
   }   
   }
 
   if(flag==1)
   printf("parsing unsucessful");
   else
   printf("sucessful parsing");
      }
   
   void push(char *M)
   {
   int k,l;
   l=strlen(M);
    for(k=l;k>0;k--)
    {
    i++;
    stack[i] =M[k];
     }
   }
   
   void pop()
   {
   i--;
   }
