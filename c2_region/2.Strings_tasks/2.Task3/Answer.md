# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###
Посчитайте прямые и обратные хеши. Теперь перебирайте позиции, в которых может стоять зеркало и проверяйте равенство кусков около зеркала

def is_pol(s, start, end):

    hash1 = (hashs[end] - hashs[start - 1] * powers[end - start + 1]) % m

    hash2 = (rhashs[len(s) - start - 1] - rhashs[len(s) - end - 2] * powers[end - start + 1]) % m

    return hash1 == hash2

 

 

n, ncol = map(int, input().split())

s = list(map(int, input().split()))

p = 1336337

m = 10 ** 9 + 7

powers = [1] + [0] * len(s)

for i in range(1, len(s)):

    powers[i] = powers[i-1] * p % m

hashs = [0] * (len(s) + 1)

for i in range(len(s)):

    hashs[i] = (hashs[i-1] * p + s[i]) % m

rhashs = [0] * (len(s) + 1)

for i in range(len(s)):

    rhashs[i] = (rhashs[i-1] * p + s[-i-1]) % m

 

print(n, end=" ")

for center in range(len(s) // 2):

    if is_pol(s, 0, center * 2 + 1):

        print(n - center - 1, end=" ")
