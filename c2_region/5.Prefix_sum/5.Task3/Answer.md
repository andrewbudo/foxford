# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###
Реализуйте спуск по дереву для нахождения k-ого нуля в массиве. 
А дальше чтобы найти k-ый на интервале, найдите количество нулей
(стандартной операцией подсчета количества нулей) на отрезке [0; l) 
и дальше сможете легко узнать k-ый ноль на отрезке через операцию взятия k-ого нуля в массиве

#include <stdlib.h>

#include <stdio.h>

#include <iostream>

#include <math.h>

#include <map>

#include <set>

#include <stack>

#include <vector>

#include <time.h>

#include <random>

#include <algorithm>

#include <string>

#include <string.h>

#include <queue>

#include <deque>

#include <functional>

#include <cctype>

#include <list>

#include <unordered_set>

#include <unordered_map>

#include <bitset>

#define rt return

#define rt0 return 0

#define rt1 return 1

#define mp make_pair

#define endl "\n"

#define cen cout << "\n"

#define all(x) begin(x), end(x)

#define rep(x) for (int rep_iter = 0; rep_iter < x; ++rep_iter)

#define fnd(x, y) (x.find(y) != x.end())

#define fndv(x, y) (find(all(x), y) != end(x))

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef double db;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

typedef pair<db, db> pdd;

const int MOD = 1000000007;

const ll INF = 1000000007;

const ll INF2 = 1000000007LL * 1000000007LL;

const long double EPS = 1e-9;

const int SIZE = 200010; //200010

 

// изменяется только один элемент за раз

struct segment_tree {

vector<ll> t;

ll undef = -(1e18 + 7);

int n;

 

void build(int v, int vl, int vr, vector<int> & a) {

if (vl == vr){

t[v] = (a[vl] == 0);

return;

}

int vm = (vl + vr) / 2;

build(2 * v + 1, vl, vm, a);

build(2 * v + 2, vm + 1, vr, a);

t[v] = t[2 * v + 1] + t[2 * v + 2];

}

 

segment_tree(int n_) {

n = n_;

t.resize(4 * n, 0);

}

 

segment_tree(int n_, vector<int> & a) {

n = n_;

t.resize(4 * n, 0);

build(0, 0, n - 1, a);

}

 

ll query(int v, int vl, int vr, int l, int r){ // кол-во нулей на отрезке

if (r < vl || vr < l)

return 0;

if (l <= vl && vr <= r)

return t[v];

int vm = (vl + vr) / 2;

ll ql = query(2 * v + 1, vl, vm, l, r);

ll qr = query(2 * v + 2, vm + 1, vr, l, r);

return ql + qr;

}

 

void modify(int v, int vl, int vr, int index, int val){

if (vr < index || index < vl)

return;

if (vl == vr && vl == index){

t[v] = (val == 0);

return;

}

int vm = (vl + vr) / 2;

modify(2 * v + 1, vl, vm, index, val);

modify(2 * v + 2, vm + 1, vr, index, val);

t[v] = t[2 * v + 1] + t[2 * v + 2];

}

 

int search(int v, int vl, int vr, int k) { // k-тый ноль в массиве

if (vl == vr)

return vl;

int left = t[2 * v + 1];

int right = t[2 * v + 2];

int vm = (vl + vr) / 2;

if (k <= left)

return search(2 * v + 1, vl, vm, k);

return search(2 * v + 2, vm + 1, vr, k - left);

}

 

int searchOnRange(int l, int r, int k) {

if (l > 0)

return search(0, 0, n - 1, k + query(0, 0, n - 1, 0, l - 1));

return search(0, 0, n - 1, k);

}

};

 

vector<int> a;

int n, k;

 

int main() {

#ifdef _DEBUG

freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

#endif

ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

cin >> n;

a.resize(n);

for (auto& i : a) {

cin >> i;

}

segment_tree sgt(n, a);

cin >> k;

rep(k) {

char c;

cin >> c;

if (c == 's') {

int l, r, k;

cin >> l >> r; --l; --r;

cin >> k;

if (sgt.query(0, 0, n - 1, l, r) < k)

cout << "-1 ";

else

cout << sgt.searchOnRange(l, r, k) + 1 << ' ';

}

else {

int index, val;

cin >> index >> val; --index;

sgt.modify(0, 0, n - 1, index, val);

}

}

 

 

 

 

return 0;

}

