#include<stdio.h>
#include<string.h>
#define T 4 // number of terminal symbols
char TStack[20],NTStack[20];
char Ter[T]={'a','+','*','$'};
int topter,i,i1;
 char ip[20];    // for input string
 /*                  a   +   *   $             */
    char PT[T][T]={' ','>','>','>',   //a
                   '<','>','<','>',   //+
                   '<','>','>','>',   // *
                   '<','<','<',' '};   // $
/*
  E--> E+E | E*E | a
*/
void push()
{
TStack[++topter]=ip[i];
i++;
//printf("In pus()\n Topter=%c,ip=%c\n",TStack[topter],ip[i]);
}
char pop()
{
int n;
 //printf("TStackPOP:");
  //for(n=0;n<=topter;n++) printf("%c",TStack[n]);
char ch;
ch=TStack[topter];
if(topter>0) topter--;
return ch;
}
int main()
{
    topter=0;
    char ch;
   int j,k,n,i3,flag=0,ipLen;

//clrscr();


/*
printf("\nPRECEDENCE TABLE:\n");
for(i=0;i<T;i++)
   printf("\t%c",Ter[i]);

printf("\n");
for(i=0;i<T;i++)
{
    printf("\n%c",Ter[i]);
    for(j=0;j<T;j++)
      printf("\t%c",PT[i][j]);
}*/
int no;
TStack[0]='$'; // Top of stack is '$'
printf("\nEnter the input string:");
scanf("%s",ip);
ipLen=strlen(ip);
ip[ipLen]='$';


//i=0;
printf("\nOutput\tSTACK\t\tINPUT STRING\t\tACTION\n\n");
/*for(j=0;j<=top; j++)
   printf("%c",TStack[j]);
printf("\t\t\t");
for(j=0;ip[j]!='$'; j++)
   printf("%c",ip[j]);
printf("$\t\t\t");
*/
i=i3=0;
i1=-1;
ch='$';
 while(TStack[topter]!='$'||i!=ipLen)
 {
 ch=TStack[topter];
//  printf("\n");
  //i3=i1;
 /*  for(i3=0;i3<=i1;i3++) printf("%c",NTStack[i3]);
    printf("\t");
  for(n=0;n<=topter;n++) printf("%c",TStack[n]);
  printf("\t\t");
    i3=i;
   for(i3=i;i3<=ipLen;i3++) printf("%c",ip[i3]);
    printf("\t\t\t");
*/
 // NTStack[++i1]='E';
 //printf("ch=%c,ip=%c",ch,ip[i]);
switch(ch)
{
case 'a':j=0;break;
case '+':j=1;break;
case '*':j=2;break;
case '$':j=3;break;
}
switch(ip[i])
{
case 'a':k=0;break;
case '+':k=1;break;
case '*':k=2;break;
case '$':k=3;break;
}
//printf("PT[][]=%c\n",PT[j][k]);
 if(PT[j][k]=='<')
 {push();
  for(i3=0;i3<=i1;i3++) printf("%c",NTStack[i3]);
    printf("\t");
  for(n=0;n<=topter;n++) printf("%c",TStack[n]);
  printf("\t\t");
    i3=i;
   for(i3=i;i3<=ipLen;i3++) printf("%c",ip[i3]);
    printf("\t\t\t");
 printf("Shift\n");continue;}
 else if(PT[j][k]=='>')
 {//printf("Reduce\n");
 //printf("TStack2:");
 // for(n=0;n<=topter;n++) printf("%c",TStack[n]);
 no=0;
 	do{
   // printf("\n");
   if(no>0){
    for(i3=0;i3<=i1;i3++) printf("%c",NTStack[i3]);
    printf("\t");
  for(n=0;n<=topter;n++) printf("%c",TStack[n]);
  printf("\t\t");
    i3=i;
   for(i3=i;i3<=ipLen;i3++) printf("%c",ip[i3]);
    printf("\t\t\t");
    printf("Reduce\n");
   }
   no++;
 	ch=pop();
 	if(ch=='a')
 	NTStack[++i1]='E';
 	else if(ch=='+'||ch=='*')
 	{
 	if(i1==1) i1=0;
 	else {//printf("Unsuccessful!!!\n");
 	flag=1;break;}
 	}
 	switch(ch)
	{
		case 'a':j=0;break;
		case '+':j=1;break;
		case '*':j=2;break;
		case '$':j=3;break;
	}
	switch(ip[i])
	{
		case 'a':k=0;break;
		case '+':k=1;break;
		case '*':k=2;break;
		case '$':k=3;break;
	}
	}while(PT[j][k]=='>');
 }
 else break;
 if(flag==1) {//printf("BREAK!\n");
 break;}
 else {//printf("Continue!\n");
 continue;}
}
if(i==ipLen && flag==0) printf("\nSuccessful!\n");
else printf("\nUNsuccessful!!\n");
return 0;
}
