# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###
Двигаем два указателя. Двигаем левый, если на текущем отрезке есть все деревья и правый если нет.

n,k = map(int, input().split())

a = list(map(int, input().split()))

cnt = [0] * (k + 1)

u1 = 0

u2 = 0

r1 = 0

r2 = 0

opt = 10 ** 20

cnt[a[u2]] += 1

c = 1

while u1 <= u2 < n:

    while (c < k) and u2 < n:

        u2 += 1

        if u2 < n:

            cnt[a[u2]] += 1

            if cnt[a[u2]] == 1:

                c += 1

    if u2 - u1 < opt:

        r1 = u1

        r2 = u2

        opt = r2 - r1

    while c >= k and u1 <= u2:

        if u2 - u1 < opt:

            r1 = u1

            r2 = u2

            opt = r2 - r1

        u1 += 1

        cnt[a[u1-1]] -= 1

        if cnt[a[u1-1]] == 0:

            c -= 1

print(r1+1, r2+1) 
