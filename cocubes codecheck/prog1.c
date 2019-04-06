#include<stdio.h>

int main()
{
    char arr[50],i,j,cnt,flag=0,pos;
    scanf("%s",arr);
    int len=strlen(arr);
    for(i=0;i<len;i++)
    {
        cnt=0;
        pos=i;
        for(j=i+1;j<len;j++)
        {
            if(arr[j]=='1' && cnt==0)
            {
                cnt=j-i;
                if(pos+cnt+cnt<len && arr[pos+cnt+cnt]=='1')
                {
                    printf("%d\n%d\n%d\n",pos,pos+cnt,pos+cnt+cnt);
                    flag=1;
                }
                break;
            }
        }
        if(flag==1) break;
    }
if(flag==0) printf("-1\n");
    return 0;
}

