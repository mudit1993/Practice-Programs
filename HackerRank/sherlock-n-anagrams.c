#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char str[101],s[101];
int ctr,a[26],b[26];
void clear_arr()
{
    int j;
    for(j=0;j<26;j++)
            {
                a[j]=0;
            }
}
void fill_arr(int x,int y){
int i;
clear_arr();
for(i=x;i<=y;i++)
{
a[s[i]-97]++;
}
}

void getstr(int x,int y){
int i;
for(i=x;i<=y;i++)
    str[i-x]=s[i];
}
int check(int x)
{
    int i;
    for(i=0;i<=x;i++)
    {
        b[str[i]-97]++;
    }
    for(i=0;i<26;i++)
    {
        if(a[i]!=b[i])
            return 0;
    }
    return 1;
}

int main() {

    int t,len,i,j,k,m,cnt;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        scanf("%s",s);
        len=strlen(s);
        for(i=0;i<len-1;i++)
        {
            //clear_arr();
            for(j=0;j+i<len;j++)
            {
                fill_arr(j,j+i);
                /*for(k=j;k<=j+i;k++)
                    {
                        str[ctr++]=s[k];
                    }*/
                for(m=j+1;m+i<len;m++)
                {
                    getstr(m,m+i);
                    for(k=0;k<26;k++)
                        b[k]=0;
                    if(check(i)==1)
                    {
                        cnt++;
                    }
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}

/*
from collections import *
for i in range(input()):
    s = raw_input()
    check = defaultdict(int)
    l = len(s)
    for i in range(l):
        for j in range(i+1,l+1):
            sub = list(s[i:j])
            print sub
            sub.sort()

            sub = "".join(sub)
            check[sub]+=1
    sum = 0
    for i in check:
        n = check[i]
        sum += (n*(n-1))/2
    print sum
    */
