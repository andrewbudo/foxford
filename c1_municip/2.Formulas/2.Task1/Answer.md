# foxford
## Практикум по программированию: подготовка к окружному этапу олимпиады ##
### Ответ ###
Пусть мы добавили x родителей. Тогда должно выполняться следующее равенство: (K+x)*3>=N+x.

Решая его получаем 3K+3x>=N+x, x>=(N-3K)/2. Требуется округлить вверх и не забыть, что возможно родителей уже хватает и обработать этот случай.

 

n = int(input())

k = int(input())

print(max(0, (n - 3 * k + 1) // 2))