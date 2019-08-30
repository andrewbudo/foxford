# foxford
## Практикум по программированию: подготовка к окружному этапу олимпиады ##
### Ответ ###
Задача громоздкая, но решается простым моделированием процесса.

n = int(input())

A = list(map(int,input().split()))

B = list(map(int,input().split()))

m = int(input())

Trios_0 =[0]*n

Trios_1 = [0] * n

Result = [0]*n

Penalty_time = [0]*n

i = 0

while i < m:

    times,number,tests = map(int,input().split())

    if tests >= B[number-1]and Result[number-1] != 2:

        if tests == A[number-1]:                      

            Penalty_time[number-1] = times 

            Result[number-1] = 2                        

        else:

            if Result[number-1] != 1:                

                Penalty_time[number-1] = times

                Result[number-1] = 1

    if tests == -1:

        1 == 1

    elif tests < B[number-1]and Result[number-1]!= 1 and Result[number-1] != 2 :

        Trios_0[number-1] += 1

        Trios_1[number-1] += 1

        

    elif tests < A[number-1]and Result[number-1]!= 2:

        Trios_1[number-1] += 1                

    i= i+1

res = 0

pen = 0

res = sum(Result)

pen = sum(Penalty_time)

for i in range(len(Penalty_time)):

    if Result[i] == 1:

        pen = pen + (Trios_0[i]*20)

    elif Result[i] == 2:

        pen = pen + (Trios_1[i]*20)

print(res,end = ' ' )

print(pen,end = ' ' )

 