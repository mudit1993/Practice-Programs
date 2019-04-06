#include<iostream>
#include <map>
#include<string>
using namespace std;
int fact(int);
int fact(int no){
    int fact=1,i;
if(no==0) return fact;
else{
for(i=2;i<=no;i++)
    fact*=i;
    return fact;
}
}
int main()
{
int t,n,q,k,i,j,cnt;
string s,temp;

cin>>t;
while(t--)
{
    map <string,int> sub;
    cin>>n>>q>>s;
    //cout<<n<<" "<<q<<" "<<s;
    for(i=0;i<n;i++)
    {

        for(j=0;j+i<n;j++)
        {
           //cout<<s.substr(j,i+1)<<endl;
           temp=s.substr(j,i+1);
           if(sub.count(temp))
           sub[temp]++;
           else
           sub[temp]=1;
        }
       // cout<<endl;
    }
    while(q--)
    {
        cnt=0;
        cin>>k;
        if(k==1)
            {cout<<n*(n+1)*0.5<<endl;continue;}

        map <string, int>::iterator it;
        for (it = sub.begin(); it != sub.end(); ++it)
        //cout << it->second << endl;
       {
        if(it->second>=k)
            {
                cnt+= (fact(it->second)/(fact(k)*fact(it->second-k)));
            }
       }
        cout<<cnt<<endl;
    }

}
return 0;
}
