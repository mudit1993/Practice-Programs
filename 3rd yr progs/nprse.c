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
   int i=1,j=0;

   void push(char *x);
   void main()
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
   tab[4][3] = "(E)";

   printf("enter the string \n");
   scanf("%s",inp);
   printf("%s \n",inp);
   len = strlen(inp);
   stack[0]='$';
   stack[1]='E';
   while(j<len && flag==0)
   {
   if(stack[i]=='E' && inp[j]=='a')
   {
   stack[i]='\0';
   i--;
   push(tab[0][0]);
   printf("%s\n",stack);
   }
   else if
   (stack[i]=='E' && inp[j]=='(')
   {
   stack[i]='\0';
   i--;
   push(tab[0][3]);
   printf("%s\n",stack);
   }
   else if(stack[i]=='G' && inp[j]=='+')
   {
   stack[i]='\0';
   i--;
   push(tab[1][1]);
   printf("%s\n",stack);
   }
   else
   if(stack[i]=='G' && inp[j]==')')
   {
   stack[i]='\0';
   i--;
   //push(tab[0][0]);
   printf("%s\n",stack);
   }
   else
   if(stack[i]=='G' && inp[j]=='$')
   {
   stack[i]='\0';
   i--;
   //push(tab[0][0]);
   printf("%s\n",stack);
   }
   else
   if(stack[i]=='T' && inp[j]=='a')
   {
   stack[i]='\0';
   i--;
   push(tab[2][0]);
   printf("%s\n",stack);
   }
   else
   if(stack[i]=='T' && inp[j]=='(')
   {
   stack[i]='\0';
   i--;
   push(tab[2][3]);
   printf("%s\n",stack);
   }
   else
   if(stack[i]=='H' && inp[j]=='+')
   {
   stack[i]='\0';
   i--;
   //push(tab[3][1]);
   printf("%s\n",stack);
   }
   else
   if(stack[i]=='H' && inp[j]=='*')
   {
   stack[i]='\0';
   i--;
   push(tab[3][2]);
   printf("%s\n",stack);
   }
   else
   if(stack[i]=='H' && inp[j]==')')
   {
   stack[i]='\0';
   i--;
   //push(tab[3][4]);
   printf("%s \n",stack);
   }
   else
   if(stack[i]=='H' && inp[j]=='$')
   {
   stack[i]='\0';
   i--;
   //push(tab[0][0]);
   printf("%s\n",stack);
   }
   else
   if(stack[i]=='F' && inp[j]=='a')
   {
   stack[i]='\0';
   i--;
   push(tab[4][0]);
   printf("%s\n",stack);
   }
   else
   if(stack[i]=='F' && inp[j]=='(')
   {
   stack[i]='\0';
   i--;
   push(tab[4][3]);
   printf("%s \n",stack);
   }
   else
   if(stack[i]=='(' || stack[i]==')' || stack[i]=='+' || stack[i]=='*' || stack[i]=='a')
   {
   stack[i]='\0';
   i--;
   printf("%s\n",stack);
   j++;
   }
   else
   {
        flag=1;
        break;
   }

   }

   if(flag==1)
   printf("parsing unsucessful \n");
   else
   printf("sucessful parsing\n ");
      }

   void push(char *M)
   {
   int k,l;
   l=strlen(M);
   l=l-1;
    for(k=l;k>=0;k--)
    {
    i++;
    stack[i] =M[k];
     }
   }
