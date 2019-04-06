#include<stdio.h>
#include<string.h>
char stack[20],ch,inp[20];
int top=0,i=0;
char tab[5][6][5]={	"TG","%"  ,"%"  ,"TG" ,"%" ,"%",
					"%" ,"+TG","%"  ,"%"  ,"e" ,"e",
					"FH","%"  ,"%"  ,"FH" ,"%" ,"%",
					"%" ,"e"  ,"*FH","%"  ,"e" ,"e",
					"a" ,"%"  ,"%"  ,"(E)","%" ,"%"};
void push()
{
int j=0,k=0;
switch(ch)
{
case 'E': j=0;break;
case 'G': j=1;break;
case 'T': j=2;break;
case 'H': j=3;break;
case 'F': j=4;break;
/*case 'a': i++;break;
case '+': i++;break;
case '*': i++;break;
case '(': i++;break;
case ')': i++;break;
*/
default : break;
}
switch(inp[i])
{
case 'a': k=0;break;
case '+': k=1;break;
case '*': k=2;break;
case '(': k=3;break;
case ')': k=4;break;
case 'e': k=5;break;
default : break;
}
int len=strlen(tab[j][k]);
while((len-1)>=0)
{top++;
stack[top]=tab[j][k][len-1];
//printf("tab[j][k][len-1]=%c\n",tab[j][k][len-1]);
len--;
}
len=top;
//printf("%d",len);
/*while(len!=-1)
{printf("%c",stack[len--]);
}
printf("\n");
*/
}
void pop()
{
ch=stack[top];
top--;
//printf("Popped=%c\n",ch);
}
int main()
{
//printf("%c\n",tab[4][0][0]);
printf("Enter a string\n");
scanf("%s",inp);
stack[0]='E';
while(top!=-1)
{
while(inp[i]!=stack[top] && i<strlen(inp))
{
pop();
push();
if(stack[top]=='e') break;
if(stack[top]=='%') break;
}
if(stack[top]=='%') break;
if(i>=strlen(inp))
{
break;
}
if(stack[top]=='e'){pop();continue;}
pop();
i++;
}
while(i>=strlen(inp) && top>=0)
{
if(stack[top]=='G'|| stack[top]=='H') top--;
else break;
}
	if(stack[top]=='%') printf("Unsuccessful!\n");
	else if(top==-1) printf("Successful!\n");
	else printf("Unsuccessful!!\n");
return 0;
}
