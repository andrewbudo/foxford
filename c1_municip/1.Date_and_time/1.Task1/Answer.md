# foxford
## Практикум по программированию: подготовка к окружному этапу олимпиады ##
### Ответ ###
Для решения задачи удобнее перевести время в минуты. Считываем параметры будильника, в случае ежедневного будильника рассмотрим два случая: если время на нем больше чем текущее, то номер дня недели для будильника равен текущему дню, в противном случае на один больше. Если текущее время больше чем время будильника, увеличиваем его на неделю. Находим разницу с текущим временем и запоминаем наименьшую. Полученный минимальный промежуток прибавляем к текущему времени и переводим полученный результат в дни (целая часть от деления на 24*60), часы (оставшиеся от дней минуты делим на 60 нацело) и минуты (остаток от деления на 60 оставшихся от дней минут. Если число полученных дней больше чем дней недели, находим остаток от деления на 7, в случае получения нулевого остатка заменяем его на 7.

#include <iostream>

 

using namespace std;

 

long long md, mh, mm, allt;

int mins;

 

int gettime(int d, int h, int m) {

    int nowt = d * 1440 + h * 60 + m;

    return (nowt - allt + mins) % mins;

}

 

int main() {

    cin >> md >> mh >> mm;

    md--;

    allt = md * 1440 + mh * 60 + mm;

    int n;

    cin >> n;

    mins = 1440 * 7;

    int d, h, m;

    int mint = mins, thist;

    for (int i = 0; i < n; i++) {

        cin >> d >> h >> m;

        d--;

        if (d == -1) {

            thist = min(gettime((md + 1) % 7, h, m), gettime(md, h, m));

        } else {

            thist = gettime(d, h, m);

        }

        mint = min(mint, thist);

    }

    mm = mm + mint;

    mh = mh + mm / 60;

    mm = mm % 60;

    md = md + mh / 24;

    mh = mh % 24;

    md = md % 7;

    md++;

    cout << md << ' ' << mh << ' ' << mm;

}