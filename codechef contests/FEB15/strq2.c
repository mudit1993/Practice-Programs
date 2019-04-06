#include<stdio.h>
#include<string.h>
int c[6][1000000];
int main()
{
   // printf("%d,%d,%d,%d",'c'-99,'h'-99,'e'-99,'f'-99);
    int q,len,c1[6],j,i,sum;
    int l,r,pos;
    char s[1000000],a,b;
    for(i=0;i<6;i++) c1[i]=0;
    //printf("%d",(int)'c'-67);
    scanf("%s",&s);
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='c')
        {
            c['c'-99][c1['c'-99]]=i;
            c1['c'-99]++;
        }
        else if(s[i]=='h')
        {
            c['h'-99][c1['h'-99]]=i;
            c1['h'-99]++;
        }
        else if(s[i]=='e')
        {
            c['e'-99][c1['e'-99]]=i;
            c1['e'-99]++;
        }
        else if(s[i]=='f')
        {
            c['f'-99][c1['f'-99]]=i;
            c1['f'-99]++;
        }
    }
//for(i=0;i<c1;i++)
//printf("%d,",c[i]);
scanf("%d",&q);
while(q--)
{
    i=j=0;
scanf(" %c %c",&a,&b);
scanf("%d%d",&l,&r);
l--;r--;
sum=0;
//printf("hey\n");
        while(c[a-99][i]<l){i++;}
        while(c[a-99][i]<=r && i<c1[a-99]){
        while(c[a-99][i]>c[b-99][j] && c[b-99][j]<=r){j++;}
        pos=j;
       // printf("j=%d,sum=%d\n",pos,sum);

        while(c[b-99][pos]<=r && pos<c1[b-99])
        {
          //  printf("h[%d]=%d",pos,h[pos]);
        sum++;
        pos++;
        }
        i++;
        }
printf("%d\n",sum);
//printf("%c %c %d %d\n",a,b,l,r);
}
return 0;
}
