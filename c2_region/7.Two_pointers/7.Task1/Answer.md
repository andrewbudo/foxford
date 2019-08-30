# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###
#include<bits/stdc++.h>

#define INF INT_MAX

using namespace std;

using ll = long long;

using ld = long double;

 

 

int main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);cout.tie(0);

    cout.precision(20);cout << fixed;

    ld ans = 0, a, b, x;

    cin >> a >> b >> x;

    int t = 1;

    ld v = x / a;

    if(v <= 1000)ans = 1000;

    while(1)

    {

        ld l = (a + b) * t, r = (a + b) * t + a;

        if(x / l <= 1000)

        {

            ans = max(ans,x / l);

            break;

        }

        else

        {

            if(x / r <= 1000)

            {

                ans = 1000;

                break;

            }

        }

        t++;

    }

    t = 1;

    while(1)

    {

        ld l = (a + b) * t - a, r = (a + b) * t;

        if(x / l <= 1000)

        {

            ans = max(ans,x / l);

            break;

        }

        else

        {

            if(x / r <= 1000)

            {

                ans = 1000;

                break;

            }

        }

        t++;

    }

    cout << ans;

}

 
