# foxford
## Практикум по программированию: подготовка к окружному этапу олимпиады ##
### Ответ ###
Честно пробегитесь циклом по непокрашеным отрезкам. Взяв очередной отрезок, красьте его максимально. Если отрезок не закончился, обрабатывайте его конец заново. Иначе переходите к следующему.

 

#include <iostream>

 

using namespace std;

 

typedef long long ll;

 

int main()

{

    ll n, k, m, vvod[120];

    cin >> n >> k >> m;

    for (ll i = 1; i <= 2 * m; i++)

    {

        cin >> vvod[i];

    }

    sort(vvod + 1, vvod + 1 + 2 * m);

    ll i = 2 * m, ans = 0;

    while (i > 1)

    {

        ll d = (vvod[i] - vvod[i - 1] + 1) / k;

        ll h = (vvod[i] - vvod[i - 1] + 1) % k;

 

        for (ll j = 1; j <= d; j++)

        {

            ans += vvod[i] * 2;

            vvod[i] -= k;

        }

        if (h == 0)

            i -= 2;

        else

        {

            ans += vvod[i] * 2;

            ll cop = k - h;

            i -= 2;

            while (cop > 0 && i > 1)

            {

                if (vvod[i] - vvod[i - 1] + 1 == cop)

                {

                    cop = 0;

                    i -= 2;

                }

                else if (vvod[i] - vvod[i - 1] + 1 > cop)

                {

                    vvod[i] -= cop;

                    cop = 0;

                }

                else

                {

                    cop -= (vvod[i] - vvod[i - 1] + 1);

                    i -= 2;

                }

            }

        }

    }

    cout << ans;

}

 