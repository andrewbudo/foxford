# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###

Пусть первый и единственный параметр это количество обработанных гангстеров. Тогда пусть обрабатываем текущего гангстера. Надо понять кто был перед ним. Переберем. Пусть находимся на гангстере i и перебираем гангстера q. Тогда i может прийти после q если их разница во времени не меньше чем разница в толщине. Выберем самого оптимального предыдущего гангстера.

#include <bits/stdc++.h>

 

#define vremya first

#define dengi second.first

#define otkr second.second

 

using namespace std;

 

int n, k1, t1, tn, pn, kn, a[101];

pair <int, pair <int, int> >  p[101];

 

int main(){

    cin >> n >> k1 >> t1;

    for(int i = 0; i < n; i++) {

        cin >> p[i].vremya;

    }

    for(int i = 0; i < n; i++) {

        cin >> p[i].dengi;

    }

    for(int i = 0; i <  n; i++) {

        cin >> p[i].otkr;

    }

    sort(p, p + n);

    vector <int> mx(n, 0);

    for(int i = 0; i < n; i++) {

        if(!(p[i].otkr > p[i].vremya)) {

            a[i] = p[i].dengi;

            for(int j = 0; j < i; j++) {

                if(!(abs(p[j].otkr - p[i].otkr) > p[i].vremya - p[j].vremya)) {

                    a[i] = max(a[i], a[j] + p[i].dengi);

                }

            }

        }

    }

    int mxx = 0;

    for(int i = 0; i < n; i++){

        mxx = max(mxx, a[i]);

    }

    cout << mxx;

}