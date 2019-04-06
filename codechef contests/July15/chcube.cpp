#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
int t,i;
string color1,color2;
cin>>t;
while(t--)
{
    map <string,int> cube;
       cin>>color1>>color2;
        cube[color1]=1;
        cube[color2]=1;
        for(i=0;i<2;i++){
        cin>>color1>>color2;
        if(cube.count(color1)){
            cube[color1]++;
        }
        if(cube.count(color2))
        {
            if(color1!=color2)
                cube[color2]++;
        }
            //else continue;
        }
        //for loop
      map <string,int>::iterator it;
    int  flag=0;
    for(it=cube.begin(); it!=cube.end();++it)
    {
        if(it->second==3)
        {
            //cout<<it->first<<" "<<it->second;
            flag=1;
            break;
        }

    }
    if(flag==0)
        cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    }

return 0;
}
