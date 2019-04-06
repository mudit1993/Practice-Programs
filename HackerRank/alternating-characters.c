#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int t,i,cnt1,cnt2,len,k,k1;
    char s[100000],ch,ch1;
    scanf("%d",&t);
    while(t--)
    {
        cnt1=cnt2=0;
        k=0;k1=0;
        ch='A';ch1='B';
        scanf("%s",s);
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(s[i]==ch)
            {
                ch=pow(-1,k)+ch;
                k++;
                //printf("%c",ch);
            }
            else {cnt1++;}
            if(s[i]==ch1)
            {
                k1++;
               ch1=pow(-1,k1)+ch1;
            }
            else cnt2++;
        }
       // printf("%d %d",cnt1,cnt2);
        printf("%d\n",cnt1<cnt2?cnt1:cnt2);

    }
    return 0;
}
