# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###
Строим граф и выделяем компоненты сильной связности. Далее получаем полный ациклический граф. Единственные ребра, которые имеет смысл разворачивать - ребра из первой вершины в остальные. Если вы развернули одно из ребер между 1-ой и i-ой компонентой, то совершенными становятся все города в 2, 3, …, i-той компонентах. Не забывайте про то, что между вершинами в новом графе больше одного ребра. Единственный особый случай - когда в первой и второй компоненте по одной вершине и если развернем единственное ребро между ними, то вторая станет совершенной, а первая перестанет

#include<iostream>

#include<vector>

#include<string>

#include<algorithm>

 

using namespace std;

 

vector<vector<int> > g, gT;

 

void dfs(int v, vector<bool>& used, vector<int>& ans)

{

    used[v] = true;

    for (size_t i = 0; i < g[v].size(); ++i) {

        if (!used[g[v][i]]) {

            dfs(g[v][i], used, ans);

        }

    }

    ans.push_back(v);

}

 

void topsort(int n, vector<int>& ans)

{

    vector<bool> used(n, false);

    for (int i = 0; i < n; i++)

    {

        if (!used[i])

        {

            dfs(i, used, ans);

        }

    }

    reverse(ans.begin(), ans.end());

}

 

void dfs2(int v, vector<bool>& used, int cur_comp, vector<int>& comp_size) {

    used[v] = true;

    comp_size[cur_comp]++;

    for (size_t i = 0; i < gT[v].size(); ++i) {

        if (!used[gT[v][i]]) {

            dfs2(gT[v][i], used, cur_comp, comp_size);

        }

    }

}

 

int main() {

    int n, p;

    cin >> n >> p;

    g.resize(n);

    gT.resize(n);

    for (int i = 0; i < n; ++i) {

        string s;

        cin >> s;

        for (int q = 0; q < n; ++q) {

            if (q <= i) {

                continue;

            }

            if (s[q] == '+') {

                g[i].push_back(q);

                gT[q].push_back(i);

            }

            else {

                g[q].push_back(i);

                gT[i].push_back(q);

            }

        }

    }

    vector<int> ans;

    topsort(n, ans);

    vector<bool> used(n, false);

    int cur_comp = 0;

    vector<int> comp_size(n, 0);

    for (int i = 0; i < n; ++i) {

        if (!used[ans[i]]) {

            dfs2(ans[i], used, cur_comp, comp_size);

            cur_comp++;

        }

    }

    cout << comp_size[0] << endl;

    vector<int> output(n - comp_size[0] + 1, 0);

    if (comp_size[0] != 1 || comp_size[1] != 1) {

        output[comp_size[1]] += (comp_size[0] * comp_size[1]);

    }

    int pref_sum = comp_size[1];

    for (int i = 2; i < cur_comp; ++i) {

        output[pref_sum + comp_size[i]] += (comp_size[0] * comp_size[i]);

        pref_sum += comp_size[i];

    }

    for (size_t i = 1; i < output.size(); ++i) {

        cout << output[i] << ' ';

    }

    return 0;

}
