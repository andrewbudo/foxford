# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###
Удвойте одну из строк - таким образом вы получили, что все циклические сдвиги исходной присутствуют в удвоенной как подстроки. Далее идет повторение задачи 1, можно использовать хеши или z-функцию или префикс-функци

def main():   

    s = input()

    t = input()

    qq = len(t)

    s = s + '#' + t + t

    n = len(s)

    ans = [0] * n

    for i in range(1, n):

        k = ans[i - 1]

        if k - 1 == ans[k - 1] and s[i] == s[i - 1] and s[k] != s[i]:

            k = k - 1

        while s[k] != s[i] and k > 0:

            k = ans[k - 1]

        if s[i] == s[k]:

            ans[i] = k + 1

    r = -1

    for i in range(len(ans)):

        if ans[i] >= qq:

            print(i - 2 * qq, end=' ')

            return

    print(-1)

main()
