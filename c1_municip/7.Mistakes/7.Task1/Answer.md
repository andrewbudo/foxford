# foxford
## Практикум по программированию: подготовка к окружному этапу олимпиады ##
### Ответ ###
Найдем ближайший автобус, троллейбус и трамвай и проверим на чем поехать будет быстрее:

x = int(input())

y = int(input())

z = int(input())

m = int(input())

ans = 10 ** 10

for i in range(m, 61):

    if i % 15 == 0:

        ans = min(ans, i - m + x)

    if i % 10 == 0:

        ans = min(ans, i - m + y)

    if i % 5 == 0:

        ans = min(ans, i - m + z)

print(ans)