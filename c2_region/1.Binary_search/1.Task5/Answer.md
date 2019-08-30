# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###
import sys

 

 

n, w = map(int, input().split())

l, r = map(int, input().split())

if n > 0:

    a = list(map(int, input().split()))

else:

    a = []

a.append(r)

a.insert(0, l)

if r - l < w:

    print(-1)

    sys.exit()

d = dict()

for i in range(n + 2):

    d[a[i]] = i

ans = [float("inf"), 0]

a.sort()

j = 0

n += 2

for i in range(n):

    while j + 1 < n and a[j] - a[i] < w:

        j += 1

    if a[j] - a[i] >= w:

        ans = min([j - i - 1, i + 1], ans)

if ans[0] == -1:

    print(0)

    sys.exit()

print(ans[0])

if ans[0] == float("inf"):

    print(0)

    sys.exit()

for i in range(ans[1], ans[1] + ans[0]):

    print(d[a[i]])
