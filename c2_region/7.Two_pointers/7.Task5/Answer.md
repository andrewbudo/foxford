# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###
def sym(c):   

    return ord(c) - ord('a')

 

def main():

    s = input()

    n = len(s)

    ans = 0

    sm = [[s[0], 1]]

    for i in range(1, n):

        if s[i] == s[i - 1]:

            sm[-1][-1] += 1

        else:

            sm.append([s[i], 1])

    let = [0] * 26

    for i in sm:

        let[sym(i[0])] = max(let[sym(i[0])], i[1])

    ans += sum(let)

    p = [[[] for i in range(26)] for j in range(26)]

    for i in range(len(sm) - 1):

        p[sym(sm[i][0])][sym(sm[i + 1][0])].append((sm[i][1], sm[i + 1][1]))

    for i in range(26):

        for q in range(26):

            if len(p[i][q]) == 0:

                continue

            p[i][q].sort(reverse = True)

            ans += p[i][q][0][0] * p[i][q][0][1]

            last = 0

            for j in range(1, len(p[i][q])):

                if p[i][q][j][1] <= p[i][q][last][1]:

                    continue

                ans += p[i][q][j][0] * (p[i][q][j][1] - p[i][q][last][1])

                last = j

    print(ans)

 

main()
