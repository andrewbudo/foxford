# foxford
## Практикум по программированию: подготовка к окружному этапу олимпиады ##
### Ответ ###
Переберите все пары чисел до куба из n. Если их сумма равна n, ответ найден. Если такой пары нет — ответ impossible.

 

#include <iostream>

#include <cmath>

#include <algorithm>

#include <string>

#include <iomanip>

using namespace std;

int main() {

  int n;

  cin >> n;

  if (n > 0 && n <= 1028) {

  for (int i = 0; i <= 11; i++) {

  for (int j = 1; j <= 11; j++) {

  if (n == pow(i, 3) + pow(j, 3)) {

  cout << i << " " << j;

  return 0;

  }

  }

  }

  cout << "impossible";

  }

}