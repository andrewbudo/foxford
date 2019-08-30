# foxford
## Практикум по программированию: подготовка к окружному этапу олимпиады ##
### Ответ ###
Встретили первый неотремонтированный участок дороги — поставили сюда бригаду. Теперь следующие L участков можно и не проверять.

#include <iostream>

 

using namespace std;

 

int main()

{

    int l, n = 0;

    cin >> l >> n;

    int road[n];

    for(int i = 0; i < n; i++){

        cin >> road[i];

    }

    int c = 0;

    for(int i = 0; i < n; i++){

        if(road[i] == 1){

            i += l - 1;

            c++;

        }

    }

    cout << c;

    return 0;

}

 