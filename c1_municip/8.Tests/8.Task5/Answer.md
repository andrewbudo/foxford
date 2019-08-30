# foxford
## Практикум по программированию: подготовка к окружному этапу олимпиады ##
### Ответ ###
Честно рассмотрите все линии и столбцы. Если есть ровно одна линия или ровно один столбец, то опознать нельзя. Иначе разбор случаев: если есть и горизонтальные и вертикальные столбцы, то клетка. Иначе легко.

n, m = map(int, input().split())

a = [input() for i in range (n)]

if n == 1 or m == 1:

    n = 0

    m = 0

kl = 0

ks = 0

rs = 0

rl = 0

for i in range (n):

    if a[i][0] == a[i][1] == "1":

        if kl == 1:

            rl = i - rl - 1

        elif kl == 0:

            rl = i

        kl += 1

for j in range (m):

    if a[0][j] == a[1][j] == "1":

        if ks == 1:

            rs = j - rs - 1

        elif ks == 0:

            rs = j

        ks += 1

if ks > 0 and kl > 0:

    print ("Square")

elif kl > 1 and rl < m:

    print ("Line")

elif ks > 1 and rs < n:

    print ("Vertical line")

else:

    print ("?")