# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###
Ну как обычно первый параметр - количество обработанных столбцов. Пусть теперь мы кладем плитку. Нам надо знать предпоследний столбец - как он замощен. Пусть dp[i][j] - количество способов замостить полностью i-1 столбец, а в последнем замостить состояние j (таких всего 4). Теперь честно перебираем все варианты предыдущего столбца и текущего (не забываем учитывать поставленные уже плитки, некоторые состояния будут запрещенными) и обновляем динамику.

#include <algorithm>

#include <iostream>

#include <cstdio>

#include <vector>

#include <string>

#include <cmath>

#include <queue>

#include <map>

#include <set>

 

#define task "paul"

#define local

#define N 100010

#define ll long long

 

using namespace std;

 

 

 

const int M = 1e9 + 7;

 

int p[N], dp[N][4];

 

int main(){

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

 

int n, k, i, v, u;

cin >> n >> k;

 

for (i = 0; i < k; i++){

scanf("%d %d", &v, &u);

p[v] |= 1 << (u - 1);

}

 

ll nxt[4][4] = {

{ 2, 1, 1, 1 },

{ 1, 0, 1, 0 },

{ 1, 1, 0, 0 },

{ 1, 0, 0, 0 }

};

 

dp[0][3] = 1;

 

for (i = 1; i <= n + 1; i++){

vector< vector<char> > mark(4, vector<char>(4));

for (int i1 = 0; i1 < 4; i1++){

for (int i2 = 0; i2 < 4; i2++){

if (p[i] & i2){

continue;

}

int pr = p[i] | i2;

if (mark[i1][pr]){

continue;

}

mark[i1][pr] = 1;

dp[i][pr] = (dp[i][pr] + nxt[i1][i2] * dp[i - 1][i1]) % M;

}

}

}

 

cout << dp[n + 1][0];

 

return 0;

}
