# foxford
## Практикум по программированию: подготовка к региональному этапу олимпиады ##
### Ответ ###
Функция времени от икс координаты точки пересечения с разделительной прямой — выпукла. Сделаем тернарный поиск по ней.

from math import *

from decimal import *

getcontext().prec = 20

def f(y):

    t1 = (1-a) * (1-a) + y * y

    t1 = t1.sqrt()

    t1 *= v2

    t2 = a * a + (1 - y) * (1 - y)

    t2 = t2.sqrt()

    t2 *= v1

    return t1 + t2

    #(((1-a)*(1-a) + y*y).sqrt()) * v2 + (((a * a + (1-y) * (1-y)).sqrt())* v1

 

v1, v2 = map(Decimal, input().split())

a = Decimal(input())

l = Decimal(0)

r = Decimal(1)

while r - l > 10**(-13):

    m1 = (l + l + r) / 3

    m2 = (l + r + r) / 3

    if f(m1) < f(m2):

        r = m2

    else:

        l = m1

print(r)
