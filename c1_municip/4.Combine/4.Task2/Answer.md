# foxford
## Практикум по программированию: подготовка к окружному этапу олимпиады ##
### Ответ ###
Сделаем рекурсивный перебор всех последовательностей. Если на текущий момент мы уже набрали N символов — выведем строку. Иначе запустим рекурсивный перебор с текущей строкой плюс новый символ ноль, а после перебор с текущей строкой плюс новый символ один.

 

def comb(n, s = ''):

  if n == 0:

  print(s)

  return

  comb(n-1, s + '0')

  comb(n-1, s + '1')

 

n = int(input())

comb(n)