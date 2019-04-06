// A Dynamic Programming based solution for 0-1 Knapsack problem
#include<stdio.h>
#include<climits>
#include<iostream>
#include<string>
#include<math.h>
#include<stdlib.h>
using namespace std;
struct ar{
int no;
int count;
};
int getMid(int s, int e) {  return s + (e -s)/2;  }
struct ar constructSTUtil(struct ar arr[], int ss, int se, struct ar *st, int si)
{

       if (ss == se)
    {
        st[si] = arr[ss];

        return arr[ss];
    }


    int mid = getMid(ss, se);
    struct ar y=constructSTUtil(arr, ss, mid, st, si*2+1);
     struct ar y1=constructSTUtil(arr, mid+1, se, st, si*2+2);
    if(y.no==y1.no)
    {
        st[si].count=y.count+y1.count;
        st[si].no=y.no;
    }
    else if(y.no>y1.no)
    {
        st[si].count=y.count;
        st[si].no=y.no;
    }
    else
    {
        st[si].count=y1.count;
        st[si].no=y1.no;
    }
    return st[si];
}

int getSumUtil(struct ar *st, int ss, int se, int qs, int qe, int index,struct ar &res)
{
    if (qs <= ss && qe >= se)
    {
       if(res.no<st[index].no)
       {
           res.no=st[index].no;
           res.count=st[index].count;
       }
       else if(res.no==st[index].no)
           res.count=res.count+st[index].count;
        return 0;
    }
    if (se < qs || ss > qe)
        return 0;
    int mid = getMid(ss, se);
       getSumUtil(st, ss, mid, qs, qe, 2*index+1,res);
      getSumUtil(st, mid+1, se, qs, qe, 2*index+2,res);

    return 0;

}
int main()
{

int a,b;
cin>>a>>b;
struct ar arr[a];int min=-1;
for(int i=0;i<a;i++)
{
    cin>>arr[i].no;
    arr[i].count=1;
}
 int x = (int)(ceil(log2(a)));
    int max_size = 2*(int)pow(2, x) - 1;
    struct ar *st = new struct ar[max_size];
    constructSTUtil(arr, 0, a-1, st, 0);
struct ar res;
for(int i=0;i<b;i++)
{
    int a4,b4;
    cin>>a4>>b4;
    res.no=-1;
    res.count=0;
    getSumUtil(st, 0,a-1,a4-1,b4-1, 0,res);
    cout<<res.count<<endl;

}
return 0;
}
