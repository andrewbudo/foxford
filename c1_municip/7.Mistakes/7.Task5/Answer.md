# foxford
## Практикум по программированию: подготовка к окружному этапу олимпиады ##
### Ответ ###
import sys

 

def make_ans(s):

    sum1 = sum(s[:n // 2])

    sum2 = sum(s[n // 2:])

    i = len(s) - 1

    while sum2 < sum1:

        s[i] = min(9, sum1 - sum2)

        sum2 += s[i]

        i -= 1

    print("".join(map(str, s)))

    sys.exit(0)

 

s = input()

n = len(s)

if s == "9" * n:

    print(("0" * (n // 2 - 1) + "1") * 2)

else:

    s = list(map(int, s))

    sum1 = sum(s[:n // 2])

    sum2 = sum(s[n // 2:])

    for i in range(n - 1, n // 2 - 1, -1):

        for d in range (s[i] + 1, 10):

            if sum2 - s[i] + d <= sum1 <= sum2 - s[i] + d + 9 * (n - 1 - i):

                s[i] = d

                make_ans(s)

        sum2 -= s[i]

        s[i] = 0

    i = n // 2 - 1

    while s[i] == 9:

        s[i] = 0

        i -= 1

    s[i] += 1

    make_ans(s)