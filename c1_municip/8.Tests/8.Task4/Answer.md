# foxford
## Практикум по программированию: подготовка к окружному этапу олимпиады ##
### Ответ ###
Переберите все возможные времена зарядки. Для фиксированного времени зарядки ваш заработок это сумма чисел на отрезке. Такие суммы можно посчитать заранее с использованием префиксных сумм.

 

n = int(input())

p = list(map(int, input().split()))

a = list(map(int, input().split()))

cumsum = [0] * (n + 1)

s = 0

for i in range(1, n + 1):

    s += p[i - 1]

    cumsum[i] = s

ms = 0

mj = -1

for j in range(n + 1):

    summ = cumsum[min(j + a[j], n)] - cumsum[j]

    if summ >= ms:

        ms = summ

        mj = j

print(ms, mj)