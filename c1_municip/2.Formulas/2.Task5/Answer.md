# foxford
## Практикум по программированию: подготовка к окружному этапу олимпиады ##
### Ответ ###
Если нет звездочки — циклом проверьте совпадение строк.

Если есть звездочка, то проверьте, что совпадает кусок до нее и после нее, и тогда все хорошо.

 

mask = input()

fnames = []

for i in range(5):

   fnames.append(input())

star_pos = -1

for i in range(len(mask)):

   if mask[i] == '*':

      star_pos = i

      break

for i in range(len(fnames)):

   if star_pos == -1 and len(fnames[i]) != len(mask) or len(mask) - len(fnames[i]) > 1:

      print('NO')

      continue

   bgn = 0

   end = len(fnames[i]) - 1

   flag = True

   for j in range(star_pos):

      if mask[j] != '?' and mask[j] != fnames[i][bgn]:

         flag = False

         break

      bgn += 1 

   for j in range(len(mask) - 1, star_pos, -1):

      if mask[j] != '?' and mask[j] != fnames[i][end]:

         flag = False

         break

      end -= 1  

   if flag:

      print('YES')

   else:

      print('NO')