# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###
Используйте 0-1 bfs

#include <bits/stdc++.h>

using namespace std;

 

#define FAST ios_base::sync_with_stdio(false); \

             cin.tie(nullptr);                 \

             cout.tie(nullptr)

 

vector<long long> data;

 

long long a, b, k, n, m, tmp, tmp1, tmp2, ans = 0;

 

 

 

 

 

int main()

    {

    //FAST;

 

 

 

    cin >> n >> k;

 

    vector<vector<bool>> matrix(n+10, vector<bool>(n+10, false));

 

 

    for (int i = 0; i < k; i++)

        {

        cin >> m;

 

        vector<vector<int>> graph (n);

 

        for (int j = 0; j < m; j++)

            {

            cin >> tmp1 >> tmp2;

            --tmp1;

            --tmp2;

            graph[tmp1].push_back(tmp2);

            graph[tmp2].push_back(tmp1);

            }

 

        vector<bool> used (n, false);

 

        for (int j = 0; j < n; j++)

            {

            if (used[j]) continue;

 

            vector<int> cur_comp;

            cur_comp.push_back(j);

 

            used[j] = true;

            queue<int> Queue;

            Queue.push(j);

 

            while(!Queue.empty())

                {

                int cur = Queue.front();

                Queue.pop();

 

                for (int cnt = 0; cnt < graph[cur].size(); cnt++)

                    {

                    int next = graph[cur][cnt];

                    if (used[next]) continue;

 

                    used[next] = true;

                    Queue.push(next);

                    cur_comp.push_back(next);

                    }

                }

 

            //cout << "list for\ [map]: " << i << ", [start vertex]: " << j << endl << "[list]: ";

            for (int i_ = 0; i_ < cur_comp.size(); i_++)

                {

                //cout << cur_comp[i_] << " ";

                for (int j_ = i_ + 1; j_ < cur_comp.size(); j_++)

                    {

                    matrix[cur_comp[i_]][cur_comp[j_]] = true;

                    matrix[cur_comp[j_]][cur_comp[i_]] = true;

                    //cout << "{" << cur_comp[i_] << " " << cur_comp[j_] << "} ";

                    }

                }

            //cout << endl;

 

            }

        }

 

    for (int i = 0; i < n; i++)

        {

        for (int j = i+1; j < n; j++)

            {

            matrix[j][i] = matrix[i][j];

            }

        }

 

    /*for (int i = 0; i < n; i++)

        {

        for (int j = 0; j < n; j++)

            {

            cout << matrix[i][j] << " ";

            }

        cout << endl;

        }*/

 

 

 

    vector<bool> used(n, false);

    vector<int> dist(n, 0);

    queue<int> Queue;

    used[0] = true;

    Queue.push(0);

 

    while(!Queue.empty())

        {

        int cur = Queue.front();

        Queue.pop();

 

        for (int cnt = 0; cnt < n; cnt++)

            {

            if (!matrix[cur][cnt]) continue;

            int next = cnt;

            if (used[next]) continue;

 

            used[next] = true;

            Queue.push(next);

            dist[next] = dist[cur] + 1;

            }

        }

 

    if (dist[n-1] == 0)

        {

        cout << -1;

        return 0;

        }

 

    cout << dist[n-1];

 

    return 0;

    }

 

/*

 

6 1

4

1 5

5 4

3 4

3 6

 

 

*/
