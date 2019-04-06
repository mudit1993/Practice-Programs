#include <cstdio>
#include <string>
#include <map>
#include <cstring>
#include <cassert>
using namespace std;

typedef unsigned long long llu;
struct node {
int  num;
char a[9];
char no;
char vwb;
char dwb;
};

int mm,n,last,now,pp,un;
llu ans;
char s[10][10];


inline bool operator<(const node &a,const node &b) {
    if (a.no < b.no) {
        return true;
    }
    if (a.no > b.no) {
        return false;
    }
    if (a.dwb < b.dwb) {
        return true;
    }
    if (a.dwb > b.dwb) {
        return false;
    }
    if (a.vwb < b.vwb) {
        return true;
    }
    if (a.vwb > b.vwb) {
        return false;
    }
        if (a.num<b.num) {
            return true;
        }
        if (a.num>b.num) {
            return false;
        }
    for (int i = 0;i < n;++i) {
        if (a.a[i] < b.a[i]) {
            return true;
        }
        if (a.a[i] > b.a[i]) {
            return false;
        }
    }
    return false;
}

map<node,llu> save[2];

inline bool iswhite(int x) {
    return !(x & 1);
}

inline bool isblack(int x) {
    return (x & 1);
}

void makelone(node &tmp,int y,int x,int n) {
int i,j,z = (y << 1) + x;
    tmp.a[y] = z;
    z = (y << 1);
    for (i = y + 1;i < n;++i) {
        if (tmp.a[i] == z) {
            break;
        }
    }
    for (j = i,i <<= 1; j < n; ++j) {
        if (tmp.a[j] == z) {
            tmp.a[j] = i;
        }
    }
    z = (y << 1) | 1;
    for (i = y + 1;i < n;++i) {
        if (tmp.a[i] == z) {
            break;
        }
    }
    for (j = i,i = (i << 1) | 1;j < n;++j) {
        if (tmp.a[j] == z) {
            tmp.a[j] = i;
        }
    }

}

void makeunion(node &tmp,int x,int y,int n) {
    if (x < y) {
        x ^= y ^= x ^= y;
    }
    for (int i = 0; i < n;++i) {
        if (tmp.a[i] == x) {
            tmp.a[i] = y;
        }
    }
}


void makewhite(int x,int y,node tmp,llu ans,int add) {
bool yes;
int i,j,k,ll,uu;
map<node,llu>::iterator t;

    if ((tmp.no == 0) || (tmp.dwb == 0))  {
        return;
    }
    tmp.num += add;
    if ((tmp.num + un < -pp) || (tmp.num - un > pp)) {
        return;
    }
    yes = (tmp.dwb == 1);

    if ((x) && (tmp.a[y] == ((y << 1) | 1))) {
        for (i = y + 1;i < n;++i) {
            if (tmp.a[i] == tmp.a[y]) {
                break;
            }
        }
        if (i >= n) {
            if ((tmp.vwb != 1) && (tmp.vwb != 2)) {
                return;
            }
            yes = true;
        }
    }
    ll = ((y) && iswhite(tmp.a[y - 1]))?tmp.a[y - 1]:(-1);
    uu = ((x) && iswhite(tmp.a[y]))?tmp.a[y]:(-1);
    k = x?n:(y + 1);
    if (uu < 0) {
        makelone(tmp, y,0 ,k);
        if (ll >= 0) {
            tmp.a[y] = ll;
        }
    }
    else if ((ll >= 0) && (ll != uu)) {
        makeunion(tmp,ll,uu,k);

    }
    for (i = j = 0;i < k;++i) {
        if ((tmp.a[i]== (i<<1)) && (++j > 1)) {
            break;
        }
    }
    if (j == 1) {
        tmp.vwb = ((tmp.vwb == 1) || (tmp.vwb == 2))?2:0;
    }
    else { //j > 1
        tmp.vwb = ((tmp.vwb == 1) || (tmp.vwb == 2))?1:3;
    }
    tmp.dwb = yes?1:3;
    tmp.no = ((uu >= 0) && (y + 1 < n) && ((tmp.a[y + 1] & 1) == 0))?0:2;
    save[now][tmp] += ans;

}


void makeblack(int x,int y,node tmp,llu ans,int add) {
bool yes;
int i,j,k,ll,uu;
map<node,llu>::iterator t;

    if ((tmp.no == 1) || (tmp.dwb == 1))  {
        return;
    }
    tmp.num += add;
    if ((tmp.num + un < -pp) || (tmp.num - un > pp)) {
        return;
    }

    yes = (tmp.dwb == 0);
    if ((x) && (tmp.a[y]==(y << 1))) {
        for (i = y + 1;i < n;++i) {
            if (tmp.a[i] == tmp.a[y]) {
                break;
            }
        }
        if (i >= n) {
            if ((tmp.vwb != 0) && (tmp.vwb != 2)) {
                return;
            }
            yes = true;
        }
    }

    ll = ((y) && isblack(tmp.a[ y - 1]))?tmp.a[y - 1]:(-1);
    uu = ((x) && isblack(tmp.a[y]))?tmp.a[y]:(-1);
    k = x?n:(y + 1);
    if (uu < 0) {
        makelone(tmp,y,1,k);
        if (ll >= 0) {
            tmp.a[y] = ll;
        }
    }
    else if ((ll >= 0) && (ll != uu)) {
        makeunion(tmp,ll,uu,k);
    }
    for (i = j = 0;i < k;++i) {
        if ((tmp.a[i]==((i << 1) | 1)) && (++j > 1)) {
            break;
        }
    }
    if (j == 1) {
        tmp.vwb = ((tmp.vwb==0) || (tmp.vwb==2))?2:1;
    }
    else {
        tmp.vwb = ((tmp.vwb==0) || (tmp.vwb==2))?0:3;
    }
    tmp.dwb = yes?0:3;
    tmp.no = ((uu >= 0) && (y + 1 < n) && ((tmp.a[ y + 1] & 1) == 1))?1:2;
    save[now][tmp] += ans;

}


int main() {
int z;
node tmp;
    scanf("%d%d%d",&mm,&n,&pp);
    assert(0 <= mm && mm <= 8);
    assert(0 <= n && n <= 8);
    assert(0 <= pp <= mm*n);
    memset(tmp.a,0,sizeof(tmp.a));
    tmp.num = 0;
    tmp.no = tmp.vwb = 2;
    tmp.dwb = 3;
    save[0].clear();
    un = 0;
    for (int i  = 0;i < mm;++i) {
        scanf("%s",s[i]);
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == 'T') {
                ++tmp.num;
            }
            else if (s[i][j] == 'D') {
                --tmp.num;
            }
            else {
                ++un;
            }
        }
    }
    save[last = 0][tmp] = 1;
    //printf("un = %d\n",un);
    for (int i = 0; i < mm; ++i) {
        for (int j = 0; j < n;++j) {
            save[now = 1 ^ last].clear();
            if (s[i][j] == 'U') {
                --un;
            }
            for (map<node,llu>::iterator t = save[last].begin();t != save[last].end();++t) {
                if (s[i][j] == 'T') {
                    makeblack(i,j,t->first,t->second, 0);
                }
                else if (s[i][j] == 'D') {
                    makewhite(i,j,t->first,t->second, 0);
                }
                else {
                    makeblack(i,j,t->first,t->second, 1);
                    makewhite(i,j,t->first,t->second, -1);
                }
            }
            last = now;
        }

    }
    ans = 0;
    assert(un == 0);
    for (map<node,llu>::iterator t = save[last].begin();t != save[last].end();++t) {
        if (t->first.vwb == 2) {
            assert((t->first.num >= -pp) && (t->first.num <= pp));
            ans += t->second;
        }
    }
    printf("%llu\n",ans);
    return 0;
}
