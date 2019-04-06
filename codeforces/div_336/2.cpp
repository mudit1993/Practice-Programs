#include<iostream>

using namespace std;
long long int l[2][200002],r[2][200002],cnt[200002];
int main()
{
string a,b;
long long int i,lena,lenb,j,sum=0,one=0,ze=0,k1=0,k2=0;
cin>>a>>b;
lena=a.length();
lenb=b.length();
l[0][0]=l[1][0]=r[0][0]=r[1][0]=0;

for(i=0;i<lena;i++){
if(a[i]=='0')
    {        k1++;
        l[0][k1]=l[0][k1-1]+1;
        l[1][k1]=l[1][k1-1];
    }
else
  {
      k1++;
      l[1][k1]=l[1][k1-1]+1;
      l[0][k1]=l[0][k1-1];
        }
}
for(i=lena-1;i>=0;i--){
if(a[i]=='0')
    {   k2++;
        r[0][k2]=r[0][k2-1]+1;
        r[1][k2]=r[1][k2-1];

    }
else
  {k2++;
      r[1][k2]=r[1][k2-1]+1;
      r[0][k2]=r[0][k2-1];

}
}
//cout<<k1<<" "<<k2<<endl;
for(i=0;i<lenb;i++)
    cnt[i]=lena;
i=0;j=lenb-1;
int ct=1;
while(i<=j && ct<=lena)
{
    cnt[i]=ct;
    cnt[j]=ct;
    ct++;
}
if((lena+lena-1)<lenb)
{
for(i=0;i<lena;i++)
{
if(b[i]=='0')
{
    sum+=l[1][i+1];
}
else sum+=l[0][i+1];
if(b[lenb-i-1]=='0')
    sum+=r[1][i+1];
else sum+=r[0][i+1];
}
for(i=lena;i<=lenb-lena-1;i++)
{
    //cout<<l[0][k1];
    if(b[i]=='0')
        sum+=l[1][k1];
    else sum+=l[0][k1];
}
cout<<sum;
}
else {
        for(i=0;i<ct;i++)
        {
            if(b[i]=='0')
            {
                sum+=l[1][i+1];
            }
            else sum+=l[0][i+1];
        }
        int k3=1;
        for(i=lenb-1;i>=ct+1;i--)
        {
            if(b[i]=='0')
            {
                sum+=r[1][k3++];
            }
            else  sum+=l[0][k3++];
        }
cout<<sum;
}
    return 0;
}
