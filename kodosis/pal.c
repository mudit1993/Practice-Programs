#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#include <map>
#include <string>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

const int maxN = 20000;
const int BOUND = 2000;

long long find_limit(long long k) {
 long long l = 0, r = 5000000;
 long long res = 0;
 while (l <= r) {
   long long key = (l + r) / 2;
   long long total = (key * (key + 1)) / 2;
   if (total <= k) {
     res = key;
     l = key + 1;
   } else {
     r = key - 1;
   }
 }
 return res;
}

char s[maxN];

void solvebig(long long k) {
 int MID = 10000;
 long long counta = find_limit(k);
 long long total = (counta * (counta + 1)) / 2;

 k -= total;

 if (k == 0) {
   cout << counta << endl;
   return;
 }
 if (k == 1) {
   cout << counta + 1 << endl;
   return;
 }

 MID = min(MID, (int)counta);
 for (int i = 0; i < MID; ++i) {
   s[i] = 'a';
 }

 int res = counta;
 s[MID] = 'b';

 --k;

 bool addonlya = true;
 for (int i = MID + 1; ; ++i) {
   for (char c = 'a'; c <= 'z'; ++c) {
     s[i] = c;
     if (c != 'a') {
       addonlya = false;
     }
     long long cur = 0;
     if (addonlya) {
       cur = i - MID + 1;
     } else {
       int bound = min(MID, 2 * (i - MID + 10));
       bound = min(bound, i + 1);
       for (int j = 1; j <= bound; ++j) {
         bool good = true;
         for (int k = 0; k < j / 2; ++k) {
           if (s[i - k] != s[i - j + 1 + k]) {
             good = false;
             break;
           }
         }
         if (good) {
           ++cur;
         }
       }
     }
     if (cur == k) {
       cout << counta + (i + 1 - MID ) << endl;
       return;
     }
     if (cur < k) {
       k =k- cur;
       break;
     }
   }
 }
}

int main() {
  int t;
 cin >> t;
 for (int i = 0; i < t; ++i) {
   //cerr << i << endl;
   long long k;
   cin >> k;
   solvebig(k);
 }

 return 0;
}
