# foxford
## Практикум по программированию: подготовка к окружному этапу олимпиады ##
### Ответ ###
Как мы помним, сложность бинарного поиска это двоичный логарифм от числа N. Можно просто взять функцию log2 от N и округлить вверх.

import math

n = int(input())

print(math.ceil(math.log2(n)))