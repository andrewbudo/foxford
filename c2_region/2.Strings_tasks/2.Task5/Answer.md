# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###
Переберите каждый возможный центр палиндрома (каждая буква и каждый промежуток). Теперь бинарным поиском найдите максимальную длину половины палиндрома с центром в этой точке. Очевидно, что и все подотрезки с таким центром и длиной половины меньше найденной тоже палиндромы

#include <bits/stdc++.h>

 

using namespace std;

 

typedef long long ll;

 

ll p = 123456;

ll mod = 1e9 + 7;

 

vector <ll> pows;

 

void build_pows(ll siz)

{

    pows.resize(siz + 1);

    pows[0] = 1;

    for (int i = 1; i < pows.size(); i++){

        pows[i] = (pows[i - 1] * p) % mod;

    }

}

 

void build_hash(vector <ll> & hash, const string & inp)

{

    hash.resize(inp.size());

    hash[0]= inp[0] - 'a';

    for (int i = 1; i < hash.size(); i++){

        hash[i] = (hash[i - 1] * p + inp[i] - 'a') % mod;

    }

}

 

ll gethash(const vector <ll> & hash, ll l, ll r)

{

    return (hash[r] - ((l == 0 ? 0 : hash[l - 1]) * pows[r - l + 1]) % mod + mod) % mod;

}

 

 

 

void solve()

{

    string inp;

    cin >> inp;

 

    ll n = inp.size();

 

    build_pows(n + 5);

 

    vector <ll> hash, ahash;

 

 

    build_hash(hash, inp);

    reverse(inp.begin(), inp.end());

    build_hash(ahash, inp);

    reverse(inp.begin(), inp.end());

 

    ll answer = 0;

 

    for (ll i = 0; i < n; i++){

        ll l = 0, r = min(i + 1, n - i);

        while (r - l > 1){

            ll m = (r + l) / 2;

            if (gethash(hash, i, i + m) == gethash(ahash, n - i - 1, n - i - 1 + m)){

                l = m;

            }

            else {

                r = m;

            }

        }

        answer += r;

 

        if (i == n - 1)

            continue;

        if (inp[i] != inp[i + 1])

            continue;

 

        l = 0, r = min(i + 1, n - i - 1);

        while (r - l > 1){

            ll m = (r + l) / 2;

            if (gethash(hash, i + 1, i + m + 1) == gethash(ahash, n - i - 1, n - i - 1 + m)){

                l = m;

            }

            else {

                r = m;

            }

        }

 

        answer += r;

    }

    cout << answer;

}

 

 

int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

 

    solve();

 

    return 0;

}

 
