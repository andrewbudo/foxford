# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###
Требуется создать граф, где ребра - отношение высоты некоторых солдат. Дальше просто сделайте топологическую сортировку. Дополнительно проверьте, что сортировка возможна, то есть что нет циклов

#include <bits/stdc++.h>

#define pb push_back

#include<set>

 

using namespace std;

typedef long long ll;

 

vector<vector<int>> g;

vector<int> us, ans;

 

void dfs(int v) {

    us[v] = 1;

    for(int i = 0; i < g[v].size(); ++i) {

        int to = g[v][i];

        if (!us[to]) {

            dfs(to);

        }

    }

    ans.pb(v);

}

 

void dfs1(ll v) {

    us[v] = 1;

    for(ll i = 0; i < g[v].size(); ++i) {

        ll to = g[v][i];

        if (!us[to]) {

            dfs1(to);

        }

        else if (us[to] == 1) {

            cout << "No";

            exit(0);

        }

    }

    us[v] = 2;

}

 

int main() {

    int n, m;

    cin >> n >> m;

    g.resize(n);

    for(int i = 0; i < m; ++i) {

        int u, v;

        cin >> u >> v;

        g[u - 1].pb(v - 1);

    }

    us.resize(n, 0);

    for(int i = 0; i < n; ++i) {

        if (!us[i]) {

            dfs1(i);

        }

    }

    us.assign(n, 0);

    for(int i = 0; i < n; ++i) {

        if (!us[i]) {

            dfs(i);

        }

    }

    reverse(ans.begin(), ans.end());

    set<int> s;

    cout << "Yes\n";

    for(auto x : ans) {

        cout << x + 1 << ' ';

        s.insert(x);

    }

    for(int i = 0; i < n; ++i) {

        if (s.find(i) == s.end()) {

            cout << i + 1 << ' ';

        }

    }

}
