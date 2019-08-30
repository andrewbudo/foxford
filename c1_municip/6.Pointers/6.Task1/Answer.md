# foxford
## Практикум по программированию: подготовка к окружному этапу олимпиады ##
### Ответ ###
Переберем методом двух указателей пару городов, которые отстоят друг от друга хотя бы на r метров. Тогда мы сможем найти ответ так, как описано в подсказке.

 

qwer = [int(i) for i in input().split()]

n = qwer[0]

r = qwer[1]

u1 = 0

u2 = 1

ans = 0

qwer1 = [int(i) for i in input().split()]

for u1 in range(n-1):

    while u2 < n - 1 and qwer1[u2]-qwer1[u1] <= r:

        u2 += 1

    if qwer1[u2]-qwer1[u1] > r:

        ans += (n - u2)

print(ans)