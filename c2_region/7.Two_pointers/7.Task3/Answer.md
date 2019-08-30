# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###
Примените метод двух указателей

#include <bits/stdc++.h>

#define puba push_back

#define mapa make_pair

#define ff first

#define ss second

#define bend(_x) (_x).begin(), (_x).end()

#define szof(_x) ((int) (_x).size())

#define TASK_NAME "game"

 

using namespace std;

typedef long long ll;

typedef pair <int, int> pii;

 

int main() {        

   

 

    int n, k;

    scanf("%d%d", &n, &k);

    vector <pii> v;

    map <int, int> mp;

 

    for (int i = 0; i < n; ++i) {

        int num;

        scanf("%d", &num);

        mp[num]++;

    }

 

    for (auto p: mp) {

        v.puba(p);

    }

 

    int c = 0;

    ll ans = 0;

    int pairs = 0;

    int uni = 0;

    for (int i = 0; i < szof(v); ++i) {

        while (c < szof(v) && v[c].ff <= (ll) v[i].ff * k) {

            pairs += v[c].ss >= 2;

            uni += v[c].ss >= 1;

            ++c;

        }        

        pairs -= v[i].ss >= 2;

        uni -= v[i].ss >= 1;

        //cerr << i << " " << pairs << " " << uni << endl;

        if (v[i].ss >= 3) {

            ans += 1;

        }

        if (v[i].ss >= 2) {

            ans += uni * 3;

        }

        ans += (ll) uni * (uni - 1) / 2 * 6;

        ans += pairs * 3;

        //cerr << ans << endl;

    }

 

    cout << ans << endl;

 

    return 0;

}
