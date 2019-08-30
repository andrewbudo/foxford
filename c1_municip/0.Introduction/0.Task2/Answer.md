# foxford
## Практикум по программированию: подготовка к окружному этапу олимпиады ##
### Ответ ###
Можно составить список всех делителей и просто перебрать 
все тройки возможных чисел из списка делителей.

Для каждой тройки чисел A, B, C, где каждое число — делитель числа N проверим, 
что ABC = N, посчитаем площадь поверхности параллелепипеда и запомним тройку, 
для которой площадь поверхности будет минимальной.

Поскольку эмпирическая оценка на число делителей числа N равна N^(1/3), 
то такое решение должно иметь сложность около O(N).

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> div;
    int i = 1;
    while (i * i < n)
    {
        if (n % i == 0)
        {
            div.push_back(i);
            div.push_back(n / i);
        }
        ++i;
    }
    if (i * i == n)
        div.push_back(i);
    sort(div.begin(), div.end());
    int ans_a, ans_b, ans_c, ans_s = 1000000000;
    for (auto a: div)
    for (auto b: div)
    for (auto c: div)
    {
        int s = 2 * a * b + 2 * b * c + 2 * a * c;
        if ((long long) a * b * c == n && s < ans_s)
        {
            ans_s = s;
            ans_a = a;
            ans_b = b;
            ans_c = c;
        }
    }
    cout << ans_a << " " << ans_b << " " << ans_c << endl;
}