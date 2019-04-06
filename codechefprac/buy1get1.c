#include<stdio.h>
#include<string.h>
int main()
{
    int t,asc,i,cnt=0,len,a[52];
    char b[200];
    scanf("%d",&t);
    while(t--)
    {
        //ch=0;
           for(i=0;i<52;i++)
           a[i]=0;
           scanf("%s",b);
          // printf("%s\n",b);
          len=strlen(b);
     for(i=0;i<len;i++)
     {
            //scanf("%c",&ch);
            asc=(int)b[i];
            if(asc>=65 && asc<=90)
            {
                a[asc-65]++;
            }
            else if(asc>=97 && asc<=122)
            {
                a[asc-71]++;
            }
           // else if(ch=='\n') break;
          //printf("%c,",ch);
     }//while(ch!='\n');
     cnt=0;
     for(i=0;i<52;i++)
     {
         //if(a[i]%2==0)
         //cnt+=a[i]/2;
         //else
            cnt=cnt+(a[i]/2)+(a[i]%2);
     }
     printf("%d\n",cnt);
    }
return 0;
}
