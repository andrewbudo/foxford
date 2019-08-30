# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###
Первое остовное дерево понятно как построить. А чем от него отличается второе? Хотя бы одним ребром. По очереди уберем из графа каждое ребро первого остовного дерева и построим в оставшемся графе еще одно минимальное. Минимальное из всех построенных и есть ответ

#include <iostream>

#include <vector>

#include <algorithm>

#include <cmath>

#include <string>

#include <set>

typedef long long ll;

 

using namespace std;

 

const ll inf = 1e9;

vector <ll> p;

 

ll dsu_get(ll v) {

return (v == p[v]) ? v : p[v] = dsu_get(p[v]);

}

 

void dsu_un(ll a, ll b) {

a = dsu_get(a);

b = dsu_get(b);

if (rand() & 1) {

swap(a, b);

}

if (a != b) {

p[a] = b;

}

}

 

int main() {

ll m, n;

cin >> n >> m;

vector <pair<ll, pair <ll, ll>>> g(m);

vector <ll> res;

for (long long i = 0; i < m; i++) {

cin >> g[i].second.first >> g[i].second.second >> g[i].first;

}

p.resize(n + 1);

for (ll i = 1; i <= n; i++) {

p[i] = i;

}

ll cost = 0;

sort(g.begin(), g.end());

for (ll i = 0; i < m; i++) {

ll a = g[i].second.first, b = g[i].second.second, len = g[i].first;

if (dsu_get(a) != dsu_get(b)) {

cost += len;

res.push_back(i);

dsu_un(a, b);

}

}

ll cost1 = 1e9;

vector <ll> ansik, ansi;

for (ll i = 0; i < res.size(); i++) {

for (ll k = 1; k <= n; k++) {

p[k] = k;

}

ll kostik = 0;

for (ll j = 0; j < m; j++) {

ll a = g[j].second.first, b = g[j].second.second, len = g[j].first;

if (j != res[i]) {

if (dsu_get(a) != dsu_get(b)) {

ansik.push_back(len);

kostik += len;

dsu_un(a, b);

}

}

}

if (ansik.size() == n - 1) {

cost1 = min(cost1, kostik);

}

ansik.clear();

}

cout << cost << " " << cost1;

return 0;

}
