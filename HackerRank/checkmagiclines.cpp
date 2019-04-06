#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 510000;

typedef long long ll;

int n, q;
ll a[MAX_N];
ll s[MAX_N];

int main() {
  cin>>n;
  for (int i = 0; i < n; i++) {
    cin>>a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] + a[i];
    cout<<s[i]<<" "<<s[i+1]<<endl ;
  }
  cin>>q;
  ll sum = 0;
  while (q--) {
    ll x;
    cin>>x;
    sum += x;
    int p =lower_bound(a, a + n, -sum) - a;
    cout<<(-(p * sum + s[p]) + ((n - p) * sum + s[n] - s[p]))<<endl;
  }
  return 0;
}
