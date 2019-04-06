#include<stdio.h>
int crypto(int no)
{
int no1=no,flag=0;
if(no%11==0)
    return 1;
else{
while(no1!=0)
{
if((no1%10)%2!=0)
{
flag=1;
return flag;
}
no1/=10;
}
no1=no;
while(no1!=0)
{
if((no1%100)%11==0)
{
 flag=1;
 return flag;
}
   no1/=10;
}
no1=no;
while(no1!=0)
{
if((no1%1000)%11==0)
{
 flag=1;
 return flag;
}
   no1/=10;
}
}
return flag;
}

int main()
{

int k,t,c=0,no=1;
do{
scanf("%d",&t);
}while(t<=0 || t>=10);
while(t!=0)
{
    scanf("%d",&k);
    while(c!=k)
    {
     if(crypto(no)==0)
     {

         c++;
     //printf("%d  ",no-1);
        no++;
          printf("%d  ",no-1);

     }
     else
        no++;
    }
    //printf("%d",no-1);
        t--;
}



}
