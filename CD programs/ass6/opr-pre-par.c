#include<stdio.h>
#include<string.h>
//#include<conio.h>
#define T 4 // number of terminal symbols
    int topt=0,topn=-1,ipLen=0,inp=0;
    char TStack[20],NTStack[20];
    
/*
  E--> E+E | E*E | a
*/  
    char Ter[T]={'a','+','*','$'};
/*                  a   +   *   $             */
    char PT[T][T]={' ','>','>','>',   //a
                   '<','>','<','>',   //+
                   '<','>','>','>',   // *
                   '<','<','<',' '};   // $
    char ip[20]; // for input string   
 

int indexof(char val)
{
 int ii,kk=0;
 
 for(ii=0;ii<T;ii++)  
    if(val==Ter[ii])
       kk = ii;
       
  return kk;     
}
void display()
{
     int j,k;
     for(j=0;j<=topn;j++)
        printf("%c",NTStack[j]);
     for(j=1;j<=15-topn;j++)   
        printf(" "); 
     for(j=0;j<=topt;j++)
        printf("%c",TStack[j]);
     for(j=1;j<=12-topt;j++)   
        printf(" ");
     for(k=inp;k<=ipLen;k++)
        printf("%c",ip[k]);
     for(j=1;j<=15-ipLen+inp;j++)   
        printf(" ");    
}

int main()
{       
    int i,j,k,col,row,flag=1;
    char ch;            
printf("\nPRECEDENCE TABLE:\n");
printf("===========================================\n");
for(i=0;i<T;i++)
   printf("\t%c",Ter[i]);
   
printf("\n");
for(i=0;i<T;i++)
{
    printf("\n%c",Ter[i]);
    for(j=0;j<T;j++)
      printf("\t%c",PT[i][j]);
}
printf("\n==========================================\n\n");
TStack[0]='$'; // Top of stack is '$'
printf("\nEnter the input string:");
scanf("%s",ip);
ipLen=strlen(ip);
ip[ipLen]='$';

printf("\nNTSTACK        TSTACK        INPUT STRING      ACTION\n");
printf("================================================================\n");

  /*  Write the Algorithm below*/
  
  /******************/
  inp=0; topt=0;topn=-1;
  while(flag==1)
  {
     col=indexof(ip[inp]);//b
     row=indexof(TStack[topt]);//a
     if(PT[row][col]=='<'||PT[row][col]=='=')
     {
           TStack[++topt]= ip[inp];   
           inp++; //Modified line
           display(); // To display the line.        
           printf("Shiht.\n");
     }  
     else if(PT[row][col]=='>')// Modified line
     {
         
            while((PT[row][col]!='<'&&PT[row][col]!=' ')&&flag==1)// Modified line
            {
              ch=TStack[topt--]; //ch=popt();
              if(ch=='a')
              {
                 NTStack[++topn]='E';
                 display(); // To display the line.     
                 printf("Reduce by E-->a.\n");  
              }  
              else 
              {
                 topn--; //popn();
                 topn--; //popn(); // Modified line
                 if(topn<-1) {printf("Error.\n"); flag=-1;} // You should have sufficient non terminals on NTStack
                 else
                 {
                    NTStack[++topn]='E'; // Modified line
                    display(); // To display the line.     
                    if(ch=='+')  printf("Reduce by E--> E+E.\n"); 
                    else  printf("Reduce by E--> E*E.\n");
                 }     
             }
              
                 row=indexof(TStack[topt]);
             }
   
    }
     else  {printf("Error.\n"); flag=-1;}// Modified line
   
      if(ip[inp]=='$'&&TStack[topt]=='$')
      flag=0;
   
   }
   printf("================================================================\n");
   if(NTStack[topn]=='E'&&flag==0) printf("\nSuccessful parsing.");
   else printf("\nUnsuccessful parsing.");
//getch();
}
