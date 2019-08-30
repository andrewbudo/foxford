# foxford
## Практикум по программированию: подготовка к окружному этапу олимпиады ##
### Ответ ###
Решение аналогично задаче 3. Только придется поддерживать 4 указателя для четырех видов одежды

 

 def get(a):

 

def get(a):

    return a[3][0] - a[0][0]

 

a = []

for o in range(4):

  ans = int(input())

  a.append(sorted(list(map(int, input().split()))))

pos = [0, 0, 0, 0]

f = True

ans = 1e9

ans2 = []

while (f):

  f = False

  Min = []

  for j in range(4):

    Min.append(tuple((a[j][pos[j]], pos[j], j)))

  Min.sort()

  if (ans > get(Min)):

    ans2 = [0 for i in range(4)]

    ans = get(Min)

    for el in Min:

      ans2[el[2]] = el[0]

  for el in Min:

    if el[1] != len(a[el[2]]) - 1:

      f = True

      pos[el[2]] += 1

      break

print(*ans2)