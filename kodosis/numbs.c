#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <cassert>
#include <string>

using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define sz size()
typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;
set<int > s;
vi v;
int lessThan(int x) {
  int lo = 0, hi = (int)v.size() - 1;
  int res = -1;
  while(lo <= hi) {
    int mi = (lo + hi) >> 1;
    if(v[mi] <= x) {
      res = mi;
      lo = mi + 1;
    } else {
      hi = mi - 1;
    }
  }
  return res + 1;
}
int main() {
  int tt;
  S(tt);
  assert(tt >= 1 && tt <= 10);
  while(tt--) {
    int n,k,p;
    scanf("%d%d%d",&n,&k,&p);
    assert(n >= 1 && n <= 1000000000);
    assert(k >= 1 && k <= min(n, 100000));
    assert(p >= 1 && p <= 1000000000);
    s.clear();
    v.clear();
    rep(i,0,k) {
      int x;
      S(x);
      assert(x >= 1 && x <= n);
      if(s.find(x) == s.end()) {
        v.push_back(x);
        s.insert(x);
      }
    }
    sort(all(v));
    int lo = 1, hi = 2*n;
    int ans = 0;
    while(lo <= hi) {
      int mi = (lo + hi * 1LL) / 2;
      int x = lessThan(mi);
      int tot = mi - x;
      if(tot >= p) {
        ans = mi;
        hi = mi - 1;
      } else {
        lo = mi + 1;
      }
    }
    if(ans > n) ans = -1;
    P(ans);
  }
  return 0;
}
