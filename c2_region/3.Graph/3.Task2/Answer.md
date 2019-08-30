# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###
В этой задаче можно легко проверить, можно ли некоторое количество порций мороженого перевезти одним рейсом за 24 часа.

Поэтому задача решается двоичным поиском по ответу. В качестве левой границы возьмем число 0 — столько порций мороженого заведомо можно перевезти (ничего перевозить и не нужно), в качестве правой границы возьмем 10^7 — столько порций мороженого заведомо перевезти нельзя ни по одной дороге (т.к. ограничение на каждой дороге не превосходит 10^9 грамм, а масса одной порции — 100 грамм). Далее будем двоичным поиском сдвигать левые и правые границы, проверяя для среднего значения, можно ли данное число порций мороженого перевезти за 24 часа.

Для проверки возможности транспортировки некоторого числа порций мороженого за 24 часа построим граф, соответствующий дорогам. У каждого ребра графа будет две характеристики — длина ребра (т.е. время, необходимое на проезд по дороге) и его пропускная способность, которую лучше сразу же хранить в порциях мороженого, еще на этапе считывания вычитая из ограничения по массе на данной дороге  грамм, а затем поделив на 100.

После этого найдем кратчайший путь от вершины 1 до вершины n используя алгоритм Дейкстры, но при этом будем рассматривать только те ребра, пропускная способность которых больше или равна рассматриваемого числа перевозимых порций мороженого.

#include<iostream>
#include<vector>

using namespace std;

const int INF = 1e9;

int dijkstra(int n, vector <vector <int> > & len, vector <vector <int > > & capacity, int min_capacity)
{
    vector <int> dist(n, INF);
    dist[0] = 0;
    vector <bool> used(n, false);
    int min_dist = 0;
    int min_vertex = 0;
    while (min_dist < INF)
    {
        int i = min_vertex;
        used[i] = true;
        for (int j = 0; j < n; ++j)
            if (capacity[i][j] >= min_capacity && dist[i] + len[i][j] < dist[j])
                dist[j] = dist[i] + len[i][j];
        min_dist = INF;
        for (int j = 0; j < n; ++j)
            if (!used[j] && dist[j] < min_dist)
            {
                min_dist = dist[j];
                min_vertex = j;
        }
    }
    return dist[n - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > len(n, vector<int>(n, INF));
    vector <vector <int> > capacity(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
    {
        int start, end, l, c;
        cin >> start >> end >> l >> c;
        start--;
        end--;
        c -= 3000000;
        c /= 100;
        len[start][end] = l;
        capacity[start][end] = c;
        len[end][start] = l;
        capacity[end][start] = c;
    }
    int left = 0;
    int right = 1e7;
    while (right - left > 1)
    {
        int middle = (left + right) / 2;
        if (dijkstra(n, len, capacity, middle) <= 1440)
            left = middle;
        else
            right = middle;
    }
    cout << left << endl;
    return 0;
}
