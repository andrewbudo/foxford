# foxford
## Практикум по программированию: подготовка к окружному этапу олимпиады ##
### Ответ ###
Воспользуемся методом двух указателей. Первый указатель (переменная i) будет двигаться по первому массиву, второй (j) — по второму. Процесс закончится, когда будут найдены два одинаковых числа, или один из указателей достигнет конца массива. В переменной min будем хранить текущий наименьший модуль разности между уже просмотренными элементами  массивов. Изначально запишем в min очень большое число.

На каждом шаге будем анализировать abs(A[i] - B[j]), если он меньше min, то перезаписываем min. Если A[i] < B[j], то увеличиваем на единицу значение переменной i, поскольку все пары чисел (A[i], B[k]), где k > j не имеет смысла рассматривать — в силу упорядоченности массивов, разность между элементами будет только увеличиваться.

Аналогично, если A[i] > B[j], то увеличиваем на единицу значение переменной j. Таким образом, мы не более одного раза рассмотрим все элементы данных массивов.

#### РЕШЕНИЕ НА ЯЗЫКЕ PASCAL ####
var
  A, B: array[1..100000] of longint;
  i, j, n, m, min, ti, tj: longint;
 
begin
  readln(n);
  for i := 1 to n do
    read(A[i]);
  readln(m);
  for i := 1 to m do
    read(B[i]);
  min := 10000000;
  i := 1;
  j := 1;
  while(min <> 0) and (i <= n) and (j <= m) do begin
    if abs(A[i] - B[j]) < min then begin
      min := abs(A[i] - B[j]);
      ti := i;
      tj := j;
    end;
    if (A[i] < B[j]) then
      inc(i)
    else
      inc(j);
  end;
  writeln(A[ti], ' ', B[tj]);
end.

#### РЕШЕНИЕ НА ЯЗЫКЕ PYTHON ####
N = int(input())
A = list(map(int,input().split()))
M = int(input())
B = list(map(int,input().split()))
minn = 10000000
i = 0
j = 0
while minn != 0 and i < N and j < M:
      if abs(A[i] - B[j]) < minn:
            minn = abs(A[i] - B[j])
            ti = i
            tj = j
      if A[i] < B[j]:
        i += 1
      else:
        j += 1
print(A[ti], B[tj])