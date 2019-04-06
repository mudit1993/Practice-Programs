#include<stdio.h>
#include<string.h>
int main()
{
    int c[100000],h[100000],e[100000],f[100000],q,len,c1=0,h1=0,e1=0,f1=0,j,i,sum;
    int l,r,pos;
    char s[100000],a,b;
   // printf("%d",'c'-99);
    scanf("%s",&s);
    len=strlen(s);

    for(i=0;i<len;i++)
    {
        if(s[i]=='c')
        {
            c[c1]=i;
            c1++;
        }
        else if(s[i]=='h')
        {
            h[h1]=i;
            h1++;
        }
        else if(s[i]=='e')
        {
            e[e1]=i;
            e1++;
        }
        else if(s[i]=='f')
        {
            f[f1]=i;
           f1++;
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
if(a=='c')
{
    if(b=='h')
    {
//printf("hey\n");
        while(c[i]<l){i++;}
        while(c[i]<=r && i<c1){
        while(c[i]>h[j] && h[j]<=r){j++;}
        pos=j;
       // printf("j=%d,sum=%d\n",pos,sum);

        while(h[pos]<=r && pos<h1)
        {
          //  printf("h[%d]=%d",pos,h[pos]);
        sum++;
        pos++;
        }
        i++;
        }
    }
    else if(b=='e')
    {
        while(c[i]<l){i++;}
        while(c[i]<=r && i<c1){
        while(c[i]>e[j] && e[j]<=r){j++;}
        pos=j;
        while(e[pos]<=r && pos<e1)
        {
        sum++;
        pos++;
        }
        i++;
        }
    }
    else if(b=='f')
    {
       // printf("c1-%d,f1=%d",c1,f1);
        while(c[i]<l){i++;}
        while(c[i]<=r && i<c1){
        while(c[i]>f[j] && f[j]<=r){j++;}
        pos=j;
        while(f[pos]<=r && pos<f1)
        {
        sum++;
        pos++;
        }
        i++;
        }

    }

}
else if(a=='h')
{
    if(b=='c')
    {
        while(h[i]<l){i++;}
        while(h[i]<=r && i<h1){
        while(h[i]>c[j] && c[j]<=r){j++;}
        pos=j;
        while(c[pos]<=r && pos<c1)
        {
        sum++;
        pos++;
        }
        i++;
        }
    }
    else if(b=='e')
    {
        while(h[i]<l){i++;}
        while(h[i]<=r && i<h1){
        while(h[i]>e[j] && e[j]<=r){j++;}
        pos=j;
        while(e[pos]<=r && pos<e1)
        {
        sum++;
        pos++;
        }
        i++;
        }
    }
    else if(b=='f')
    {
        while(h[i]<l){i++;}
        while(h[i]<=r && i<h1){
        while(h[i]>f[j] && f[j]<=r){j++;}
        pos=j;
        while(f[pos]<=r && pos<f1)
        {
        sum++;
        pos++;
        }
        i++;
        }
    }

}
else if(a=='e')
{
    if(b=='c')
    {
       // printf("e1=%d,c1=%d",e1,c1);
        while(e[i]<l){i++;}
        while(e[i]<=r && i<e1){
        while(e[i]>c[j] && c[j]<=r){j++;}
        pos=j;
        while(c[pos]<=r && pos<c1)
        {
        sum++;
        pos++;
        }
        i++;
        }
    }
    else if(b=='h')
    {
        while(e[i]<l){i++;}
        while(e[i]<=r && i<e1){
        while(e[i]>h[j] && h[j]<=r){j++;}
        pos=j;
        while(h[pos]<=r && pos<h1)
        {
        sum++;
        pos++;
        }
        i++;
        }
    }
    else if(b=='f')
    {
        while(e[i]<l){i++;}
        while(e[i]<=r && i<e1){
        while(e[i]>f[j] && f[j]<=r){j++;}
        pos=j;
        while(f[pos]<=r && pos<f1)
        {
        sum++;
        pos++;
        }
        i++;
        }
    }
}
else if(a=='f')
{
    if(b=='c')
    {
        while(f[i]<l){i++;}
        while(f[i]<=r && i<f1){
        while(f[i]>c[j] && c[j]<=r){j++;}
        pos=j;
        while(c[pos]<=r && pos<c1)
        {
        sum++;
        pos++;
        }
        i++;
        }

    }
    else if(b=='h')
    {
        while(f[i]<l){i++;}
        while(f[i]<=r && i<f1){
        while(f[i]>h[j] && h[j]<=r){j++;}
        pos=j;
        while(h[pos]<=r && pos<h1)
        {
        sum++;
        pos++;
        }
        i++;
        }
        }
    else if(b=='e')
    {
        while(f[i]<l){i++;}
        while(f[i]<=r && i<f1){
        while(f[i]>e[j] && e[j]<=r){j++;}
        pos=j;
        while(e[pos]<=r && pos<e1)
        {
        sum++;
        pos++;
        }
        i++;
        }
    }
}
printf("%d\n",sum);
//printf("%c %c %d %d\n",a,b,l,r);
}
return 0;
}
