#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 char s[100006];
int check_pal(int x,int y)
{
    int i,h;
    h=(x+y)/2;
    for(i=x;i<=h;i++)
    {
        if(s[i]!=s[y-(i-x)])
        {
            return 0;
        }
    }
    return 1;

}
int main() {

    int t,i,l,j,pos;
    scanf("%d",&t);
    while(t--)
    {
        pos=-1;
        scanf("%s",s);
        l=strlen(s);
        if(l>2){
        for(i=0,j=l-1;i<j;i++,j--)
        {
            if(s[i]!=s[j])
            {
                if(s[i+1]==s[j])
                    {
                        pos=i;
                        if(check_pal(pos+1,j)==0)
                        {
                            pos=j;
                        }
                    }
                else if(s[j-1]==s[i])
                    {pos=j;
                        if(check_pal(i,pos-1)==0)
                        {
                            pos=i;
                        }
                    }
                    break;
            }
        }
        }
        printf("%d\n",pos);
    }
      return 0;
}
