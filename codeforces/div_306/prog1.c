#include<string.h>
#include<stdio.h>
int main()
{
char s[100000];
int i,len,cnt=0,cnt1=0;
scanf("%s",s);
len=strlen(s);
for(i=0;i<len-1;)
{
    if(s[i]=='A' && cnt==0){
        if(s[i+1]=='B')
        {
                cnt++;
                i=i+2;
        }
        else i++;
    }
    else if(s[i]=='B' && cnt1==0){
        if(s[i+1]=='A')
        {
            cnt1++;
            i+=2;
        }
        else i++;
    }
    else{
        i++;
    }
}
if(cnt!=0 && cnt1!=0)
    printf("YES");
else printf("NO");
return 0;
}
