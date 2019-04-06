#include<stdio.h>
#include<malloc.h>
#include<string.h>
/*typedef struct node
{
char a,b,e;
struct node *ptr;
}nfa;
nfa *arr[5];*/
//int clo[5],m=0;
//char r[6];
int tops,topr;
void move(char no,int nn)
{

}



void push(char state,char r[],int topr)
{
r[topr]=state;
//topr++;
}


char pop(char s[],int tops)
{
tops--;
char ch=s[tops];
return ch;
}



void e_closure(char s[])
{
char r[6];
int i,flag=0,topr=0;
char ch;
tops=strlen(s);
//for(i=0;i<tops;i++)printf("%c",s[i]);
//printf("\n");
while(tops!=0)
{
ch=pop(s,tops);
tops--;
printf("\npoped-%c\n",ch);
flag=0;
for(i=0;i<topr;i++)
{
if(r[i]==ch)
{flag=1;break;}

}
if(flag==0) 
{push(ch,r,topr);topr++;}

}
for(i=0;i<topr;i++)
printf("%c",r[i]);
}





int main()
{
int i,j;
char *nfa[3][3];
//s[]={'a','b','c'};
tops=0;topr=0;
nfa[0][0]="a";
nfa[0][1]="b";
nfa[0][2]="c";
nfa[1][0]="c";
nfa[1][1]="ac";
nfa[1][2]="bc";
nfa[2][0]="";
nfa[2][1]="bc";
nfa[2][2]="a";
nfa[3][0]="";
nfa[3][1]="c";
nfa[3][2]="b";
for(i=0;i<3;i++){
for(j=0;j<3;j++){
//s=nfa[i][j];
e_closure(nfa[i][j]);}}
/*for(i=0;i<5;i++)
{s[i]=i+1;
printf("Enter for state %d\n",i+1);
for(j=0;j<3;j++)
{
scanf("%d",&nfa[i][j]);
}
}*/
for(i=0;i<3;i++)
{
printf("%s,%s,%s",nfa[i][0],nfa[i][1],nfa[i][2]);
}
return 0;
}
