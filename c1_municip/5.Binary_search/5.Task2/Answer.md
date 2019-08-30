# foxford
## Практикум по программированию: подготовка к окружному этапу олимпиады ##
### Ответ ###
Функция возрастающая, поэтому сделаем бинарный поиск. Не забудем, что требуется точность 6 знаков после запятой, учтем это.

def special_function(x):    

    return x ** 2 + x ** 0.5

 

def root_bin_search(value):

    left = 0

    right = value

    eps = 0.000001

    while right - left > eps:

        middle = (right + left) / 2

        if special_function(middle) - value > 0:

            right = middle

        else:

            left = middle

    return middle

 

v = float(input())

result = root_bin_search(v)

print("{0:.9f}".format(round(result, 6)))