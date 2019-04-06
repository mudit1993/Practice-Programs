#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

   int t,len,i,f;
   string w,cpy;
   cin>>t;
   while(t--)
   {
       f=0;
       cin>>w;
       cpy=w;
       len=w.length();
      if(next_permutation(w.begin(),w.end()))
       cout<<w<<endl;
       else
           cout<<"no answer\n";
   }
    return 0;
}
