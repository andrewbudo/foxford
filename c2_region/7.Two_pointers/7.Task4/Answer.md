# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###
Примените динамику. Первый параметр длина числа, второй - последняя цифра

#include <bits/stdc++.h>

#define puba push_back

#define mapa make_pair

#define ff first

#define ss second

#define bend(_x) (_x).begin(), (_x).end()

#define szof(_x) ((int) (_x).size())

#define TASK_NAME "numbers"

 

using namespace std;

typedef long long ll;

typedef pair <int, int> pii;

const int MAXN = 105;

const ll MOD = 1e9 + 7;

 

string l, r;

int num1[MAXN], num2[MAXN];

int d[11][MAXN];

 

int solve(int *num) {

    memset(d, 0, sizeof d);

    d[9][0] = 1;

    for (int i = 1; i < MAXN; ++i) {

        for (int j = 0; j < 10; ++j) {

            for (int k = j; k < 10; ++k) {

                d[j][i] = (d[j][i] + d[k][i - 1]) % MOD;

            }

        }

        int end = 10;

        if (i > 1) {

            end = num[i - 2];

        }

        for (int j = num[i - 1]; j < end; ++j) {

            d[10][i] = (d[10][i] + d[j][i - 1]) % MOD;

        }

        if (i > 1 && num[i - 2] >= num[i - 1]) {

            d[10][i] = (d[10][i] + d[10][i - 1]) % MOD;

        }

        /*

        cerr << "i: " << i << " " << num[i] << endl;

        for (int j = 0; j < 11; ++j) {

            cerr << d[j][i] << " ";

        }

        cerr << endl;

        */

    }

    return d[10][MAXN - 1];

}

 

int main() {        

 

    getline(cin, l);

    getline(cin, r);

 

    for (int i = 0; i < szof(l); ++i) {

        num1[szof(l) - i - 1] = l[i] - '0';

    }

 

    for (int i = 0; i < szof(r); ++i) {

        num2[szof(r) - i - 1] = r[i] - '0';

    }

 

    for (int i = 0; i < MAXN; ++i) {

        if (num1[i]) {

            --num1[i];

            break;

        }

    }

 

    //solve(num2);

    cout << ((solve(num2) - solve(num1)) % MOD + MOD) % MOD << endl;

 

    return 0;

}
