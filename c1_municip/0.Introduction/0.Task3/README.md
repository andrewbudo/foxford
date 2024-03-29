# foxford
## Практикум по программированию: подготовка к окружному этапу олимпиады ##

<p>
    <a href="https://informatics.msk.ru/moodle/mod/statements/view3.php?chapterid=485#1">Сайт</a>
</p>

### Ставки ###
#### Олимпиадная ####
#### Ограничение по времени работы: 2 секунды ####

Перед началом тараканьих бегов всем болельщикам было предложено сделать по две ставки 
на результаты бегов. Каждая ставка имеет вид "Таракан №A придет раньше, чем таракан №B".

Организаторы бегов решили выяснить, могут ли тараканы прийти в таком порядке,
чтобы у каждого болельщика сыграла ровно одна ставка из двух
(то есть чтобы ровно одно из двух утверждений каждого болельщика оказалось верным). 
Считается, что никакие два таракана не могут прийти к финишу одновременно.

##### ВХОДНЫЕ ДАННЫЕ #####
В первой строке входных данных содержатся два разделенных пробелом натуральных числа: 
число K, не превосходящее 10, — количество тараканов и число N, не превосходящее 100, — 
количество болельщиков. Все тараканы пронумерованы числами от 1 до K. 
Каждая из следующих N строк содержит 4 натуральных числа A, B, C, D, не превосходящих K, 
разделенных пробелами. Они соответствуют ставкам болельщика 
"Таракан №A придет раньше, чем таракан №B" и "Таракан №C придет раньше, чем таракан №D".

##### ВЫХОДНЫЕ ДАННЫЕ #####
Если завершить бега так, чтобы у каждого из болельщиков сыграла ровно одна из двух ставок, 
можно, то следует вывести номера тараканов в том порядке, 
в котором они окажутся в итоговой таблице результатов 
(сначала номер таракана, пришедшего первым, затем номер таракана, пришедшего вторым и т. д.) 
в одну строку через пробел. Если таких вариантов несколько, выведите любой из них.

Если требуемого результата добиться нельзя, выведите одно число 0.

##### ПРИМЕР #####
#### ввод ####
```c++
3 2
2 1 2 3
1 2 3 2
```
#### вывод ####
```c++
3 2 1
```
#### ввод ####
```c++
3 4
1 2 1 3
1 2 3 1
1 2 2 3
1 2 3 2
```
#### вывод ####
```c++
0
```
