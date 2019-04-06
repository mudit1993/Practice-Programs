#include <iostream>
#include<cmath>
#include<cstdio>
#include<string>
using namespace std;

int main() {
    long t,a[127],len,i;
    string s;
    char c='~';
    cin>>t;
    getline(cin,s);
    while(t--){
    c='~';
    for(i=0;i<127;i++) a[i]=0;
    getline(cin,s);
    len=s.length();
    for(i=0;i<len;i++){
        char ch = s[i];
        //cout<<ch<<":";
        if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') ){
        ch = toupper(ch);
        a[ch]++;
        a[ch+32]++;
        }
        else{
         a[ch]++;
        }
    }
    //for(i=0;i<127;i++) cout<<i<<"="<<a[i]<<",";
    for(i=65;i<=90;i++){
        if(a[i]==0){
            c=(char)i;break;
        }
    }
    if(a[32]==0)
        c=' ';
    cout<<c<<endl;
    }

	return 0;
}
