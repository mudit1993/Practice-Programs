#include<cstring>
#include<map>
#include<iostream>
#include<cstring>
using namespace std;

char LuckyChar(char *S);

char LuckyChar(char *S)
{
    //********************************
    //**Candidate's code starts here**
    std::map <char,int> lucky;
    char ch;
    int len=strlen(S),i;
    for(i=0;i<len;i++)
    {
    if(lucky.count(S[i])<1)
    lucky[S[i]]=1;
    else if(lucky.count(S[i])==1)
     {ch=S[i];break;}
   }
   return ch;

    //***Candidate's code ends here***
    //********************************
}

int main(int argc, char * argv[])
{
    /* getting char from user code */
    char lucky = LuckyChar("AaKJK ");

    cout << lucky;

    /* To calculate time complexity: LuckyChar()
       is called several times */

    return 0;
}
